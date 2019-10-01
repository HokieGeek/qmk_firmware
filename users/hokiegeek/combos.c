#include "combos.h"

const uint16_t PROGMEM combos[][3] = {
    // Colemak
    [QA]    = {KC_Q,      KC_A, COMBO_END},
    [WR]    = {KC_W,      KC_R, COMBO_END},
    [FS]    = {KC_F,      KC_S, COMBO_END},
    [PT]    = {KC_P,      KC_T, COMBO_END},
    [GD]    = {KC_G,      KC_D, COMBO_END},
    [JH]    = {KC_J,      KC_H, COMBO_END},
    [LN]    = {KC_L,      KC_N, COMBO_END},
    [UE]    = {KC_U,      KC_E, COMBO_END},
    [YI]    = {KC_Y,      KC_I, COMBO_END},
    [SCLNO] = {KC_SCOLON, KC_O, COMBO_END},

    [AZ]    = {KC_A, KC_Z,    COMBO_END},
    [RX]    = {KC_R, KC_X,    COMBO_END},
    [SC]    = {KC_S, KC_C,    COMBO_END},
    [TV]    = {KC_T, KC_V,    COMBO_END},
    [DB]    = {KC_D, KC_B,    COMBO_END},
    [HK]    = {KC_H, KC_K,    COMBO_END},
    [NM]    = {KC_N, KC_M,    COMBO_END},
    [ECOMM] = {KC_E, KC_COMM, COMBO_END},
    [IDOT]  = {KC_I, KC_DOT,  COMBO_END},
    [OSLSH] = {KC_O, KC_SLSH, COMBO_END},

    // Qwerty
    [WS]    = {KC_W, KC_S,    COMBO_END},
    [ED]    = {KC_E, KC_D,    COMBO_END},
    [RF]    = {KC_R, KC_F,    COMBO_END},
    [TG]    = {KC_T, KC_G,    COMBO_END},
    [YH]    = {KC_Y, KC_H,    COMBO_END},
    [UJ]    = {KC_U, KC_J,    COMBO_END},
    [IK]    = {KC_I, KC_K,    COMBO_END},
    [OL]    = {KC_O, KC_L,    COMBO_END},
    [PSCLN] = {KC_P, KC_SCLN, COMBO_END},

    [SX]       = {KC_S,    KC_X,     COMBO_END},
    [DC]       = {KC_D,    KC_C,     COMBO_END},
    [FV]       = {KC_F,    KC_V,     COMBO_END},
    [GB]       = {KC_G,    KC_B,     COMBO_END},
    [HN]       = {KC_H,    KC_N,     COMBO_END},
    [JM]       = {KC_J,    KC_M,     COMBO_END},
    [KCOMM]    = {KC_K,    KC_COMM,  COMBO_END},
    [LDOT]     = {KC_L,    KC_DOT,   COMBO_END},
    [SCLNSLSH] = {KC_SCLN, KC_SLSH,  COMBO_END}
};
