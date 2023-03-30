#include "ultra64.h"
#include "macros.h"
#include "common_structs.h"
#include "io/viint.h"
#include "os/osint.h"
#include "enums.h"


#ifndef VARIABLES_JP_H
#define VARIABLES_JP_H

typedef u8 Addr[];
extern __OSViContext vi[2];
extern __OSViContext *__osViCurr;
extern __OSViContext *__osViNext;

extern s32 rngSeed; //rng

extern Camera* D_80174860;
extern playerActor* PlayerPointer;
extern Tongue* TonguePointer;
extern contMain gContMain[MAXCONTROLLERS];

extern unk0* D_801FFB84;
extern s32 g_aa1_Count;
extern aa1* g_aa1_head;
extern aa1 D_80176F00;
extern s32 D_800F68A8;
extern s32 D_800F06B0;
extern s32 D_800F06EC;
extern s32 D_800F0B38;
extern u32 D_800F0B50;
extern s8 D_800F0B54;
extern s32 D_800F6880;
extern s32 D_800F6888[4];
extern s32 D_800F6898[4];
extern s32 D_800F68AC;
extern s32 D_800F68C0;
extern s32 D_800F68C4[2];
extern s32 D_800F68CC;
extern s32 D_800FDFA0;
extern s32 D_800FDFC0[2];
extern s32 D_800FDFC8[2];
extern u8 D_800FDFD0;
extern u8 D_800FDFD4;
extern u8 D_800FDFD8;
extern u8 D_800FDFDC;
extern s8 D_800FDFE0;
extern s8 D_800FDFE4;
extern s32 D_800FDFE8;
extern s32 D_800FDFEC;
extern f32 D_800FDFF0;
extern f32 D_800FDFF4;
extern f32 D_800FDFF8;
extern f32 D_800FDFFC;
extern s32 D_800FE000;
extern f32 D_800FE004;
extern f32 D_800FE008;
extern f32 D_800FE00C;
extern f32 D_800FE010;
extern f32 D_800FE018;
extern f32 D_800FE01C;
extern f32 D_800FE020;
extern f32 D_800FE024;
extern f32 D_800FE028;
extern f32 D_800FE02C;
extern f32 D_800FE030;
extern f32 D_800FE034;
extern f32 D_800FE038;
extern f32 D_800FE03C;
extern f32 D_800FE040;
extern f32 D_800FE044;
extern f32 D_800FE048;
extern f32 D_800FE04C;
extern f32 D_800FE050;
extern f32 D_800FE054;
extern f32 D_800FE058;
extern f32 D_800FE05C;
extern f32 D_800FE060;
extern s32 D_800FE160;
extern s32 D_800FE164;
extern u8 D_800FE18C;
extern u8 D_800FE190;
extern u8 D_800FE194;
extern u8 D_800FE198;
extern s32 D_800FE19C;
extern s8 D_800FE4DC;
extern u8 D_800FE6EC;
extern s32 D_800FEA30;
extern s32 D_800FEA34;
extern s32 D_800FEA4C;
extern s32 D_800FEB90;
extern s32 D_800FEB94;
extern s32 D_800FEB98;
extern s32 D_800FEB9C;
extern f32 D_800FEBB4;
extern f32 D_800FEBB8;
extern f32 D_800FEBBC;
extern f32 D_800FEBC0;
extern u8 D_800FEBC4;
extern u8 D_800FEBC8;
extern u8 D_800FEBCC;
extern f32 D_800FEBD0;
extern Vec4f D_800FEBD4;
extern s32 D_800FF5D0;
extern s32 D_800FF5E4;
extern s32 D_800FF5E8;
extern s16 D_800FF5EC;
extern s16 D_800FF5F0;
extern s16 D_800FF5F4;
extern s16 gIsPaused;
extern s16 D_800FF5FC;
extern s16 D_800FF604;
extern s16 D_800FF608;
extern ALSeqPlayer* D_800FF614;
extern s32 D_800FF63C;
extern u8 D_800FF64C;
extern u8 D_800FF650;
extern s16 D_800FF854[];
extern s16 D_800FFDF0;
extern s16 D_800FFDF4;
extern s32 gameModeCurrent;
extern Gfx* gMainGfxPos;
extern s32 D_800FFEB8;
extern s16 UseFixedRNGSeed;
extern PlayerInit gPlayerInits[10]; // 4 extra blank entries.
extern f32 D_8010881C;
extern f32 D_80108820;
extern s32 D_80108B68;
extern unkSpriteDmaStruct D_80100118[16];
extern OSViMode osViModeTable[42];
extern Vec2f D_8010A6D0[0x6C]; //positions?
extern unk_8010AA28 D_8010AA28[0x6C]; //actor related?
extern f32 D_8010B328;
extern f32 D_8010B32C;
extern f32 D_8010B330;
extern f32 D_8010B334;
extern f32 D_8010B34C;
extern f32 D_8010B350;
extern f32 D_8010B4D8;
extern f64 D_8010B4E0;
extern f64 D_8010B4E8;
extern f64 D_8010B550;
extern f64 D_8010B558;
extern f64 D_8010B560;
extern f64 D_8010B568;
extern f64 D_8010B7A0;
extern f64 D_8010B7A8;
extern f64 D_8010B7B0;
extern f64 D_8010B7B8;
extern f32 D_8010B7F8;
extern f32 D_8010B7FC;
extern f32 D_8010B9E8;
extern f32 D_8010BA90;
extern f32 D_8010BA94;
extern f32 D_8010BAA4;
extern f32 D_8010BB30;
extern f64 D_8010BE30;
extern f32 D_8010C098;
extern f32 D_8010C0F4;
extern f32 D_8010C0F8;
extern f32 D_8010C26C;
extern f32 D_8010C270;
extern f32 D_8010C274;
extern f32 D_8010C2B8;
extern f32 D_8010C2BC;
extern f32 D_8010C318;
extern f32 D_8010C31C;
extern f32 D_8010C320;
extern f32 D_8010C324;
extern f64 D_8010C510;
extern f64 D_8010C518;
extern char D_8010C7B0[16];
extern char D_8010C944[8];
extern char D_8010CA10[9]; //"mem err!\n"
extern f64 D_8010FFF8;
extern f64 D_80110000;
extern f32 D_80110108;
extern f64 D_80110120;
extern char D_8011074C[];
extern char D_8011077C[];
extern OSThread gIdleThread; // thread1
extern u64 gIdleThreadStack[1024]; // thread1
extern OSThread gMainThread; // thread3
extern u64 gMainThreadStack[1024]; // thread3
extern OSThread D_80117FF0; //unused thread.
extern u64 D_801181A0[512]; //unused Stack
extern void* D_801191A0;
extern OSMesg gPiManMsgs[50];
extern OSMesgQueue gPiManMgsQ;
extern s32 gControllerNo;
extern s32 D_80168D78[];
extern s32 gActorCount;
extern playerActor gPlayerActors[4];
extern s32 D_80168E5C;
extern Tongue gTongues[4];
extern Actor gActors[ACTORS_MAX]; //currently loaded actor structs
extern pole D_80170968[64]; //currently loaded pole structs
extern unkStruct D_80172E88[];
extern s32 D_80174758[];
extern s32 D_80174864;
extern s32 D_80174878;                  // Level/Stage ID | loadStageByIndex()
//extern s32 D_80174880[0x20];
extern s32 D_801748A0;
extern s32 D_80174998;
extern s32 D_8017499C;
extern s32 D_801749B0;
extern OSMesgQueue D_80175620;
extern OSPiHandle __CartRomHandle;
extern s32 D_80176824;
extern u8 D_80176850[16];
extern f32 D_80176F50;
extern OSMesgQueue D_801B3120;
extern OSTask* D_801B3138;
extern s32 D_801B3140;
extern s16 D_801B3540;
extern u8 gAlHeapBase[300000];
extern s32 D_801FC9A0;
extern s32 D_801FC9A8;
extern s16 D_801FC9AC;
extern s16 D_801FC9B4;
extern f64 D_801FCA00;
extern OSThread D_801FD560;
extern u64 D_801FD710[0x400];
extern s32 D_801FF634;
extern s32 D_801FF710;
extern OSMesgQueue D_801FF750;
extern OSIoMesg D_801FF7F0;
extern OSIoMesg D_801FF8A8[30];
extern s32 D_801FFB78;
extern unk_D_801FFB90 D_801FFB90;
extern u32 D_80200054;
extern struct UnkList D_80200060; //beginning of linked list?
extern s32 D_802025B0;
extern s32 VertextBufferCount;
extern s32 TriangleBufferCount;
extern s32 ModelBufferCount;
extern s32 D_80236968;
extern s32 D_8023696C;
extern s32 currentZone; //D_80240CD8
extern s32 D_801FC9B0;
extern s16 D_801FCA22;
extern s32 D_800FF620;
extern unk800FF624 D_800FF624;
extern ALSeqFile* D_801FCA44;
extern OSMesgQueue D_801FCA50[50];
typedef u8 Addr[];
extern char D_8010F1EC[];
extern char D_8010F1FC[];
extern u32 D_80168DA0;
extern f32 D_80168DE4;
extern char D_8010ECF8[];
extern char D_8010ED04[];
extern char D_8010ED0C[];
extern char D_8010ED20[];
extern char D_8010ED2C[];
extern char D_8010ED48[];
extern char D_8010ED58[];
extern char D_8010ED5C[];
extern char D_8010ED68[];
extern char D_8010ED84[];
extern char D_8010ED94[];
extern s32 D_80175668[4];
extern u16 D_80175678[4];
extern u16 D_801756C0[4];
extern s16 D_801756C2;
extern s16 D_801756C4;
extern s16 D_801756C6;
extern s32 gFixedSeedIndex;
extern OSMesgQueue D_801FCA50[50];
extern OSMesg D_801FCF08[50];
extern s32 D_801FD558;
extern DMAStruct D_801FCFD8[50];
extern unk801FD550 D_801FD550;
extern void* D_80200C8C;
extern void* D_80200C94;
extern Addr D_AB10B0;
extern Addr D_F000000;
extern Addr D_F0042B0;
extern Camera gCamera[4];
extern unk802000C84 D_80200C84;
extern Collision D_80240D6C[];
extern u8 gCarrotBitfield;
extern s8 D_801B313D;
extern unkFlags D_80200C00;
extern Vec3s D_801087D8[];
extern s32 D_800FF898;
extern u32 D_800FF89C;
extern u32 D_800FF8A0;
extern s32 D_800FF8A4;
extern s32 D_800FF8A8;
extern s32 D_800FF8AC;
extern f64 D_8010F410;
extern char* D_80100FD4[18];
extern f32 D_801B316C;
extern char D_8011078C[];
extern char D_801107A0[];
extern char D_801107B0[];
extern char D_801107C0[];
extern char D_801107D0[];
extern char D_8010D940[];
extern char D_8010D964[];
extern u32 D_800FF884;
extern char D_8010D968[];
extern s32 D_800FF888;
extern u32 D_800FF88C;
extern s32 D_800FF890[];
extern s16 D_800FF8BC;
extern s32 D_800FF8A8;
extern s32 D_800FF8B4;
extern u32 D_800FF8B8;
extern s32 D_801B3168;
extern u8 gSelectedCharacters[];
extern u8 D_800F0BE0[];
extern unkStruct0 D_800F0BE4[];
extern s32 D_801749B4;
extern s32 gCurrentStage;
extern s32 D_80176F58;
extern s16 D_801B1EEC;
extern s16 D_801B1EEE;
extern unk801FCA20 D_801FCA20;
extern unk801FCA20 D_800FF4D0[];
extern s16 D_801FCA24;
extern s16 D_801FCA48;
extern ALSeq* D_800FF618;
extern s16 D_8020005A;
extern s32 D_80236974;
extern char D_8010D834[];
extern u8 D_80200A98[];
extern u8 D_800FF64C;
extern u8 D_800FF650;
extern ALSndPlayer* D_800FF61C;
extern frameBufferData D_803B5000[2];
extern Addr D_1000000;
extern Addr D_1045C00;
extern unk80100F50 D_80100F50[];
#endif
