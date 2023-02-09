#include "common.h"
#include "piint.h"
//AOF=3

s32 __osPiRawStartDma(s32 direction, u32 devAddr, void* dramAddr, u32 size) {
    register u32 stat;

    WAIT_ON_IOBUSY(stat);

    IO_WRITE(PI_DRAM_ADDR_REG, osVirtualToPhysical(dramAddr));
    IO_WRITE(PI_CART_ADDR_REG, K1_TO_PHYS((u32)osRomBase | devAddr));

    switch (direction) {
        case OS_READ:
            IO_WRITE(PI_WR_LEN_REG, size - 1);
            break;
        case OS_WRITE:
            IO_WRITE(PI_RD_LEN_REG, size - 1);
            break;
        default:
            return -1;
    }
    return 0;
}

s32 __osEPiRawStartDma(OSPiHandle *pihandle, s32 direction, u32 devAddr, void *dramAddr, u32 size) {
    register u32 stat = IO_READ(PI_STATUS_REG);
    
    while (stat & 3) {
        stat = IO_READ(PI_STATUS_REG);
    }
    
    IO_WRITE(PI_DRAM_ADDR_REG, osVirtualToPhysical(dramAddr));
    IO_WRITE(PI_CART_ADDR_REG, K1_TO_PHYS(pihandle->baseAddress | devAddr));

    switch (direction)
    {
        case OS_READ:
            IO_WRITE(PI_WR_LEN_REG, size - 1);
            break;
        case OS_WRITE:
            IO_WRITE(PI_RD_LEN_REG, size - 1);
            break;
        default:
            return -1;
    }
    return 0;
}

void __osDevMgrMain(void *args) {
    OSIoMesg *mb;
    OSMesg em;
    OSMesg dummy;
    s32 ret;
    OSDevMgr *dm = (OSDevMgr *)args;
    s32 messageSend;

    messageSend = 0;
    mb = NULL;
    ret = 0;

    while (TRUE)
    {
        osRecvMesg(dm->cmdQueue, (OSMesg)&mb, OS_MESG_BLOCK);

        if (mb->piHandle != NULL &&
            mb->piHandle->type == DEVICE_TYPE_64DD &&
            (mb->piHandle->transferInfo.cmdType == LEO_CMD_TYPE_0 ||
             mb->piHandle->transferInfo.cmdType == LEO_CMD_TYPE_1))
        {
            __OSBlockInfo *blockInfo;
            __OSTranxInfo *info;
            info = &mb->piHandle->transferInfo;
            blockInfo = &info->block[info->blockNum];
            info->sectorNum = -1;

            if (info->transferMode != LEO_SECTOR_MODE) {
                blockInfo->dramAddr = (void *)((u32)blockInfo->dramAddr - blockInfo->sectorSize);
            }

            if (info->transferMode == LEO_TRACK_MODE && mb->piHandle->transferInfo.cmdType == LEO_CMD_TYPE_0) {
                messageSend = 1;
            } else {
                messageSend = 0;
            }

            osRecvMesg(dm->acsQueue, &dummy, OS_MESG_BLOCK);
            __osResetGlobalIntMask(OS_IM_PI);
            __osEPiRawWriteIo(mb->piHandle, LEO_BM_CTL, (info->bmCtlShadow | 0x80000000));

readblock1:
                osRecvMesg(dm->evtQueue, &em, OS_MESG_BLOCK);
                osSendMesg(mb->hdr.retQueue, mb, OS_MESG_NOBLOCK);

                if (messageSend == 1 && mb->piHandle->transferInfo.block[0].errStatus == LEO_ERROR_GOOD) {
                    messageSend = 0;
                    goto readblock1;
                }
            
            osSendMesg(dm->acsQueue, NULL, OS_MESG_NOBLOCK);
            if (mb->piHandle->transferInfo.blockNum == 1) {
                osYieldThread();
            }
        } else {
            switch (mb->hdr.type) {
                case OS_MESG_TYPE_DMAREAD:
                    osRecvMesg(dm->acsQueue, &dummy, OS_MESG_BLOCK);
                    ret = dm->dma(OS_READ, mb->devAddr, mb->dramAddr, mb->size);
                    break;
                case OS_MESG_TYPE_DMAWRITE:
                    osRecvMesg(dm->acsQueue, &dummy, OS_MESG_BLOCK);
                    ret = dm->dma(OS_WRITE, mb->devAddr, mb->dramAddr, mb->size);
                    break;
                case OS_MESG_TYPE_EDMAREAD:
                    osRecvMesg(dm->acsQueue, &dummy, OS_MESG_BLOCK);
                    ret = dm->edma(mb->piHandle, OS_READ, mb->devAddr, mb->dramAddr,
                                mb->size);
                    break;
                case OS_MESG_TYPE_EDMAWRITE:
                    osRecvMesg(dm->acsQueue, &dummy, OS_MESG_BLOCK);
                    ret = dm->edma(mb->piHandle, OS_WRITE, mb->devAddr, mb->dramAddr,
                                mb->size);
                    break;
                case OS_MESG_TYPE_LOOPBACK:
                    osSendMesg(mb->hdr.retQueue, mb, OS_MESG_NOBLOCK);
                    ret = -1;
                    break;
                default:
                    ret = -1;
                    break;
            }

            if (ret == 0) {
                osRecvMesg(dm->evtQueue, &em, OS_MESG_BLOCK);
                osSendMesg(mb->hdr.retQueue, mb, OS_MESG_NOBLOCK);
                osSendMesg(dm->acsQueue, NULL, OS_MESG_NOBLOCK);
            }
        }
    }
}
