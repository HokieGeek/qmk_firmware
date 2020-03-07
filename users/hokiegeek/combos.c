#include "combos.h"

const uint16_t PROGMEM chords2[][3] = {
    // Colemak
    [QA]    = {KC_Q,    KC_A, COMBO_END},
    [WR]    = {KC_W,    KC_R, COMBO_END},
    [FS]    = {KC_F,    KC_S, COMBO_END},
    [PT]    = {KC_P,    KC_T, COMBO_END},
    [GD]    = {KC_G,    KC_D, COMBO_END},
    [JH]    = {KC_J,    KC_H, COMBO_END},
    [LN]    = {KC_L,    KC_N, COMBO_END},
    [UE]    = {KC_U,    KC_E, COMBO_END},
    [YI]    = {KC_Y,    KC_I, COMBO_END},
    [SCLNO] = {KC_SCLN, KC_O, COMBO_END},

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

    [QW] = {KC_Q, KC_W, COMBO_END},
    [WF] = {KC_W, KC_F, COMBO_END},
    [FP] = {KC_F, KC_P, COMBO_END},
    [PG] = {KC_P, KC_G, COMBO_END},
    [AR] = {KC_A, KC_R, COMBO_END},
    [RS] = {KC_R, KC_S, COMBO_END},
    [ST] = {KC_S, KC_T, COMBO_END},
    [TD] = {KC_T, KC_D, COMBO_END},
    [ZX] = {KC_Z, KC_X, COMBO_END},
    [XC] = {KC_X, KC_C, COMBO_END},
    [CV] = {KC_C, KC_V, COMBO_END},
    [VB] = {KC_V, KC_B, COMBO_END},

    [JL] = {KC_J, KC_L, COMBO_END},
    [LU] = {KC_L, KC_U, COMBO_END},
    [UY] = {KC_U, KC_Y, COMBO_END},
    [YSCLN] = {KC_Y, KC_SCLN, COMBO_END},
    [NE] = {KC_N, KC_E, COMBO_END},
    [EI] = {KC_E, KC_I, COMBO_END},
    [IO] = {KC_I, KC_O, COMBO_END},
    [KM] = {KC_K, KC_M, COMBO_END},
    [MCOMM] = {KC_M, KC_COMM, COMBO_END},
    [COMMDOT] = {KC_COMM, KC_DOT, COMBO_END},
    [DOTSLSH] = {KC_DOT, KC_SLSH, COMBO_END},

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

const uint16_t PROGMEM chords3[][4] = {
    // Colemak
    [QWP] = {KC_Q, KC_W, KC_F, COMBO_END},
    [WFP] = {KC_W, KC_F, KC_P, COMBO_END},
    [FPG] = {KC_F, KC_P, KC_G, COMBO_END},
    [ARS] = {KC_A, KC_R, KC_S, COMBO_END},
    [RST] = {KC_R, KC_S, KC_T, COMBO_END},
    [STD] = {KC_S, KC_T, KC_D, COMBO_END},
    [ZXC] = {KC_Z, KC_X, KC_C, COMBO_END},
    [XCV] = {KC_X, KC_C, KC_V, COMBO_END},
    [CVB] = {KC_C, KC_V, KC_B, COMBO_END},

    [JLU]         = {KC_J,    KC_L,    KC_U,    COMBO_END},
    [LUY]         = {KC_L,    KC_U,    KC_Y,    COMBO_END},
    [UYSCLN]      = {KC_U,    KC_Y,    KC_SCLN, COMBO_END},
    [HNE]         = {KC_H,    KC_N,    KC_E,    COMBO_END},
    [NEI]         = {KC_N,    KC_E,    KC_I,    COMBO_END},
    [EIO]         = {KC_E,    KC_I,    KC_O,    COMBO_END},
    [KMCOMM]      = {KC_K,    KC_M,    KC_COMM, COMBO_END},
    [MCOMMDOT]    = {KC_M,    KC_COMM, KC_DOT,  COMBO_END},
    [COMMDOTSLSH] = {KC_COMM, KC_DOT,  KC_SLSH, COMBO_END}
};

const uint16_t PROGMEM chords4[][5] = {
    // Colemak
    /*
    [QWAR] = {KC_Q, KC_W, KC_A, KC_R, COMBO_END},
    [WFRS] = {KC_W, KC_F, KC_R, KC_S, COMBO_END},
    [FPST] = {KC_F, KC_P, KC_S, KC_T, COMBO_END},
    [PGTD] = {KC_P, KC_G, KC_T, KC_D, COMBO_END},
    [ARZX] = {KC_A, KC_R, KC_Z, KC_X, COMBO_END},
    [RSXC] = {KC_R, KC_S, KC_X, KC_C, COMBO_END},
    [STCV] = {KC_S, KC_T, KC_C, KC_V, COMBO_END},
    */
    [TDVB] = {KC_T, KC_D, KC_V, KC_B, COMBO_END}//,

    /*
    [JLHN] = {KC_J, KC_L, KC_H, KC_N, COMBO_END},
    [LUNE] = {KC_L, KC_U, KC_N, KC_E, COMBO_END},
    [UYEI] = {KC_U, KC_Y, KC_E, KC_I, COMBO_END},
    [YSCLNIO] = {KC_Y, KC_SCLN, KC_I, KC_O, COMBO_END},
    [HNKM] = {KC_H, KC_N, KC_K, KC_M, COMBO_END},
    [NEMCOMM] = {KC_N, KC_E, KC_M, KC_COMM, COMBO_END},
    [EICOMMDOT] = {KC_E, KC_I, KC_COMM, KC_DOT, COMBO_END},
    [IODOTSLSH] = {KC_I, KC_O, KC_DOT, KC_SLSH, COMBO_END}
    */
};
