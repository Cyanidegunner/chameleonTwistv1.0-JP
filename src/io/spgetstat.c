#include "common.h"
#include "PR/rcp.h"
//AOF=1

u32 __osSpGetStatus() {
    return IO_READ(SP_STATUS_REG);
}
