#include "common.h"

extern f32 D_80168DB0;
extern s32 D_801749A0;
extern s32 D_80168E24;
extern s32 D_801749A0;

#define SQROOT_2_DIV_2 0.70710678f

//0xD7, 0x1E);
//0xAC, 0x2D);
//0x5B, 0x78);
void func_800D85A0(Collider* arg0, s32 sfxID, s32 arg2) {
    if (((arg0->unk_00 + D_801749A0) % arg2) == 0) {
        func_80088698(PLAYSFXAT(sfxID, arg0->sfxPos, 0, 0));
    }
}

void func_800D8628(Collider* arg0, s32 sfxID, s32 arg2) {
    if ((arg0->unk_00 + D_801749A0) % arg2 == 0) {
        PLAYSFX(sfxID, 0, 0x10);
    }
}

void func_800D86A4(Collider* arg0, s32 sfxID0, s32 sfxID1, s32 arg3) {
    if ((arg0->unk_B4 == 0) && (arg0->unk_BC == 1) && (arg0->unk_C0 == 0)) {
        func_80088698(PLAYSFXAT(sfxID0, arg0->sfxPos, 0, 0));
        return;
    }
    if ((arg0->unk_BC == 1) && (((arg0->unk_00 + D_801749A0) % arg3) == 0) && (sfxID1 >= 0)) {
        func_80088698(PLAYSFXAT(sfxID1, arg0->sfxPos, 0, 0));
    }
}

void func_800D87A4(Collider* arg0, s32 sfxID) {
    if (arg0->unk_B8 == 1) {
        func_80088698(PLAYSFXAT(sfxID, arg0->sfxPos, 0, 0));
    }
}

void func_800D87F8(Collider* arg0, s32 sfxID, s32 arg2) {
    if ((arg0->unk_BC >= 0) && (((D_801749A0 - arg0->unk_BC) % arg2) == 0)) {
        PLAYSFX(sfxID, 0, 0x10);
    }
}

void func_800D887C(Collider* arg0, s32 arg1, s32 arg2) {
    s32 new_var;
    if (((new_var = arg0->unk_00) == D_80168E24) && (((new_var + D_801749A0) % arg2) == 0)) {
        func_80088698(PLAYSFXAT(arg1, arg0->sfxPos, 0, 0));
    }
}

void func_800D8918(Collider* arg0, s32 sfxID, s32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8) {
    s32 var_v0;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 xPos;
    f32 zPos;
    f32 *new_var = &arg4;
    f32 sp44;
    f32 var_f12;
    Vec3f sp34;
    f32 sp40;
    
    if ((arg0->unk_00 + D_801749A0) % arg2 == 0) {
        zPos = gPlayerActors->pos.z - arg3;
        xPos = gPlayerActors->pos.x - arg4;
        var_v0 = 1;
        temp_f0 = (zPos - xPos) * SQROOT_2_DIV_2;
        
        if (temp_f0 < -(arg5 + arg7)) {
            var_v0 = 0;
        } else {
            if (temp_f0 < -arg5) {
                sp44 = -arg5;
            } else if (temp_f0 < arg5) {
                sp44 = temp_f0;
            } else if (temp_f0 < arg5 + arg7) {
                sp44 = arg5;
            } else {
                var_v0 = 0;
            }
        }
        
        temp_f0_2 = (zPos + xPos) * SQROOT_2_DIV_2;
        
        if (temp_f0_2 < -(arg6 + arg8)) {
            var_v0 = 0;
        } else {
            if (temp_f0_2 < -arg6) {
                var_f12 = -arg6;
            } else if (temp_f0_2 < arg6) {
                var_f12 = temp_f0_2;
            } else {
                if (temp_f0_2 < (arg6 + arg8)) {
                    var_f12 = arg6;
                } else {
                    var_v0 = 0;
                }
            }
        }
        if (var_v0 != 0) {
            sp34.z = (*new_var) + (var_f12 - sp44) * SQROOT_2_DIV_2;
            sp34.y = D_80168DB0;
            sp34.x = (sp44 + var_f12) * SQROOT_2_DIV_2;
            sp34.x = arg3 + sp34.x;
            func_80088698(playSoundEffect(sfxID, &sp34.z, &sp34.y, &sp34.x, 8, 0));
        }
    }
}

// arg3, 5, 7 relates to zPos
// arg4, 6, 8 relates to xPos

// func_800D8B28(arg0, 0x89, 0x1E, -5100.0f, 25300.0f, 600.0f, 2500.0f, 1000.0f, 1000.0f);}
// func_800D8B28(arg0, 0x89, 0x1E, 0, 25300.0f, 600.0f, 2500.0f, 1000.0f, 1000.0f);}

void func_800D8B28(Collider* arg0, s32 sfxID, s32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8) {
    f32 sum_arg5_arg7;
    f32 xPos;
    f32 zPos;
    f32 sum_arg6_arg8;
    s32 var_v0;
    f32 sp40;
    f32 sp3C;
    Vec3f sp30;

    if (((arg0->unk_00 + D_801749A0) % arg2) == 0) {
        sum_arg5_arg7 = arg5 + arg7;
        var_v0 = 1;
        zPos = gPlayerActors->pos.z - arg3;
        xPos = gPlayerActors->pos.x - arg4;
        if (xPos < -(sum_arg5_arg7)) {
            var_v0 = 0;
        } else {
            if (xPos < -arg5) {
                sp40 = -arg5;
            } else if (xPos < arg5) {
                sp40 = xPos;
            } else if (xPos < sum_arg5_arg7) {
                sp40 = arg5;
            } else {
                var_v0 = 0;
            }            
        }
        
        sum_arg6_arg8 = arg6 + arg8;
        
        if (zPos < -sum_arg6_arg8) {
            var_v0 = 0;
        } else {
            if (zPos < -arg6) {
                sp3C = -arg6;
            } else if (zPos < arg6) {
                sp3C = zPos;
            } else if (zPos < sum_arg6_arg8) {
                sp3C = arg6;
            } else {
                var_v0 = 0;
            }
        }

        if (var_v0 != 0) {
            sp30.z = arg4 + sp40;
            sp30.y = D_80168DB0;
            sp30.x = arg3 + sp3C;
            func_80088698(playSoundEffect(sfxID, &sp30.z, &sp30.y, &sp30.x, 0, 0));
        }
    }
}

void func_800D8CF0(Collider* arg0, s32 sfxID) {
    if ((func_800B34D0(arg0->unk_AC) != 0) && (arg0->unk_B0 != 0)) {
        func_80088698(PLAYSFXAT(sfxID, arg0->sfxPos,0, 0));
        arg0->unk_B0 = 0;
    }
}

void func_800D8D58(Collider* arg0) {func_800D8918(arg0, 0x55, 0x1E, -12800.0f, 19600.0f, 700.0f, 1500.0f, 1000.0f, 2000.0f);}

void func_800D8DBC(Collider* arg0) {
    func_800D8628(arg0, 0x59, 0x2D);
}

void func_800D8DE0(Collider* arg0) {
    func_800D8628(arg0, 0x5B, 0x69);
}

void func_800D8E04(Collider* arg0) {
    func_800D85A0(arg0, 0x5B, 0x78);
}

void func_800D8E28(Collider* arg0) {
    func_800D8628(arg0, 0x5C, 0x1B);
}

void func_800D8E4C(Collider* arg0) {
    func_800D8628(arg0, 0x89, 0x1E);
}

void func_800D8E70(Collider* arg0) {func_800D8918(arg0, 0x89, 0x1E, 6000.0f, 6000.0f, 600.0f, 1500.0f, 500.0f, 2000.0f);}

void func_800D8ED4(Collider* arg0) { func_800D8918(arg0, 0x89, 0x1E, 2200.0f, 1400.0f, 700.0f, 1000.0f, 500.0f, 2000.0f);}

void func_800D8F3C(Collider* arg0) {func_800D8918(arg0, 0x89, 0x1E, -8500.0f, 24000.0f, 600.0f, 2500.0f, 1000.0f, 1000.0f);}

void func_800D8F9C(Collider* arg0) {func_800D8B28(arg0, 0x89, 0x1E, -5100.0f, 25300.0f, 600.0f, 2500.0f, 1000.0f, 1000.0f);}

void func_800D8FFC(Collider* arg0) {func_800D8B28(arg0, 0x89, 0x1E, 0, 25300.0f, 600.0f, 2500.0f, 1000.0f, 1000.0f);}

void func_800D9058(Collider* arg0) {func_800D8918(arg0, 0x89, 0x1E, 5100.0f, 23600.0f, 3000.0f, 600.0f, 1000.0f, 1000.0f);}

void func_800D90B8(Collider* arg0) {
    func_800D86A4(arg0, 0xA0, -1, 0x1E);
}

void func_800D90E0(Collider* arg0) {
    func_800D85A0(arg0, 0xD7, 0x1E);
}

void func_800D9104(Collider* arg0) {
    func_800D85A0(arg0, 0xAC, 0x2D);
}

void func_800D9128(Collider* arg0) {
    func_800D8628(arg0, 0xB0, 0x2D);
}

void func_800D914C(Collider* arg0) {
    func_800D8628(arg0, 0xB1, 0x27);
}

void func_800D9170(Collider* arg0) {
    func_800D87A4(arg0, 194);
}

void func_800D9190(Collider* arg0) {
    func_800D87F8(arg0, 0xAD, 0x27);
}

void func_800D91B4(Collider* arg0) {
    func_800D887C(arg0, 0xAE, 0x24);
}

void func_800D91D8(Collider* arg0) {
    func_800D8CF0(arg0, 0x3B);
}
