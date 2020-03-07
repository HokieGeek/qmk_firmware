#pragma once

#include "quantum.h"

enum {
    //// colemak
    QA = 0,
    WR,
    FS,
    PT,
    GD,
    JH,
    LN,
    UE,
    YI,
    SCLNO,

    AZ,
    RX,
    SC,
    TV,
    DB,
    HK,
    NM,
    ECOMM,
    IDOT,
    OSLSH,

    QW,
    WF,
    FP,
    PG,
    AR,
    RS,
    ST,
    TD,
    ZX,
    XC,
    CV,
    VB,

    JL,
    LU,
    UY,
    YSCLN,
    HN,
    NE,
    EI,
    IO,
    KM,
    MCOMM,
    COMMDOT,
    DOTSLSH,

    //// qwerty
    WS,
    ED,
    RF,
    TG,
    YH,
    UJ,
    IK,
    OL,
    PSCLN,

    SX,
    DC,
    FV,
    GB,
    JM,
    KCOMM,
    LDOT,
    SCLNSLSH,

    QWP,
    WFP,
    FPG,
    ARS,
    RST,
    STD,
    ZXC,
    XCV,
    CVB,

    JLU,
    LUY,
    UYSCLN,
    HNE,
    NEI,
    EIO,
    KMCOMM,
    MCOMMDOT,
    COMMDOTSLSH,

    //// Colemak
    QWAR,
    WFRS,
    FPST,
    PGTD,
    ARZX,
    RSXC,
    STCV,
    TDVB,
    JLHN,
    LUNE,
    UYEI,
    YSCLNIO,
    HNKM,
    NEMCOMM,
    EICOMMDOT,
    IODOTSLSH,

    SAFE_COMBO_RANGE
};

// extern const uint16_t PROGMEM chords2[][3];
// extern const uint16_t PROGMEM chords3[][4];
// extern const uint16_t PROGMEM chords4[][5];

//// Chords
/// Colemak
#define CHORD_QA       (uint16_t PROGMEM [3]){KC_Q,    KC_A, COMBO_END}
#define CHORD_WR       (uint16_t PROGMEM [3]){KC_W,    KC_R, COMBO_END}
#define CHORD_FS       (uint16_t PROGMEM [3]){KC_F,    KC_S, COMBO_END}
#define CHORD_PT       (uint16_t PROGMEM [3]){KC_P,    KC_T, COMBO_END}
#define CHORD_GD       (uint16_t PROGMEM [3]){KC_G,    KC_D, COMBO_END}
#define CHORD_JH       (uint16_t PROGMEM [3]){KC_J,    KC_H, COMBO_END}
#define CHORD_LN       (uint16_t PROGMEM [3]){KC_L,    KC_N, COMBO_END}
#define CHORD_UE       (uint16_t PROGMEM [3]){KC_U,    KC_E, COMBO_END}
#define CHORD_YI       (uint16_t PROGMEM [3]){KC_Y,    KC_I, COMBO_END}
#define CHORD_SCLNO    (uint16_t PROGMEM [3]){KC_SCLN, KC_O, COMBO_END}
#define CHORD_AZ       (uint16_t PROGMEM [3]){KC_A, KC_Z,    COMBO_END}
#define CHORD_RX       (uint16_t PROGMEM [3]){KC_R, KC_X,    COMBO_END}
#define CHORD_SC       (uint16_t PROGMEM [3]){KC_S, KC_C,    COMBO_END}
#define CHORD_TV       (uint16_t PROGMEM [3]){KC_T, KC_V,    COMBO_END}
#define CHORD_DB       (uint16_t PROGMEM [3]){KC_D, KC_B,    COMBO_END}
#define CHORD_HK       (uint16_t PROGMEM [3]){KC_H, KC_K,    COMBO_END}
#define CHORD_NM       (uint16_t PROGMEM [3]){KC_N, KC_M,    COMBO_END}
#define CHORD_ECOMM    (uint16_t PROGMEM [3]){KC_E, KC_COMM, COMBO_END}
#define CHORD_IDOT     (uint16_t PROGMEM [3]){KC_I, KC_DOT,  COMBO_END}
#define CHORD_OSLSH    (uint16_t PROGMEM [3]){KC_O, KC_SLSH, COMBO_END}
#define CHORD_QW       (uint16_t PROGMEM [3]){KC_Q, KC_W, COMBO_END}
#define CHORD_WF       (uint16_t PROGMEM [3]){KC_W, KC_F, COMBO_END}
#define CHORD_FP       (uint16_t PROGMEM [3]){KC_F, KC_P, COMBO_END}
#define CHORD_PG       (uint16_t PROGMEM [3]){KC_P, KC_G, COMBO_END}
#define CHORD_AR       (uint16_t PROGMEM [3]){KC_A, KC_R, COMBO_END}
#define CHORD_RS       (uint16_t PROGMEM [3]){KC_R, KC_S, COMBO_END}
#define CHORD_ST       (uint16_t PROGMEM [3]){KC_S, KC_T, COMBO_END}
#define CHORD_TD       (uint16_t PROGMEM [3]){KC_T, KC_D, COMBO_END}
#define CHORD_ZX       (uint16_t PROGMEM [3]){KC_Z, KC_X, COMBO_END}
#define CHORD_XC       (uint16_t PROGMEM [3]){KC_X, KC_C, COMBO_END}
#define CHORD_CV       (uint16_t PROGMEM [3]){KC_C, KC_V, COMBO_END}
#define CHORD_VB       (uint16_t PROGMEM [3]){KC_V, KC_B, COMBO_END}
#define CHORD_JL       (uint16_t PROGMEM [3]){KC_J, KC_L, COMBO_END}
#define CHORD_LU       (uint16_t PROGMEM [3]){KC_L, KC_U, COMBO_END}
#define CHORD_UY       (uint16_t PROGMEM [3]){KC_U, KC_Y, COMBO_END}
#define CHORD_YSCLN    (uint16_t PROGMEM [3]){KC_Y, KC_SCLN, COMBO_END}
#define CHORD_NE       (uint16_t PROGMEM [3]){KC_N, KC_E, COMBO_END}
#define CHORD_EI       (uint16_t PROGMEM [3]){KC_E, KC_I, COMBO_END}
#define CHORD_IO       (uint16_t PROGMEM [3]){KC_I, KC_O, COMBO_END}
#define CHORD_KM       (uint16_t PROGMEM [3]){KC_K, KC_M, COMBO_END}
#define CHORD_MCOMM    (uint16_t PROGMEM [3]){KC_M, KC_COMM, COMBO_END}
#define CHORD_COMMDOT  (uint16_t PROGMEM [3]){KC_COMM, KC_DOT, COMBO_END}
#define CHORD_DOTSLSH  (uint16_t PROGMEM [3]){KC_DOT, KC_SLSH, COMBO_END}

#define CHORD_QWP          (uint16_t PROGMEM [4]){KC_Q,    KC_W,    KC_F,    COMBO_END}
#define CHORD_WFP          (uint16_t PROGMEM [4]){KC_W,    KC_F,    KC_P,    COMBO_END}
#define CHORD_FPG          (uint16_t PROGMEM [4]){KC_F,    KC_P,    KC_G,    COMBO_END}
#define CHORD_ARS          (uint16_t PROGMEM [4]){KC_A,    KC_R,    KC_S,    COMBO_END}
#define CHORD_RST          (uint16_t PROGMEM [4]){KC_R,    KC_S,    KC_T,    COMBO_END}
#define CHORD_STD          (uint16_t PROGMEM [4]){KC_S,    KC_T,    KC_D,    COMBO_END}
#define CHORD_ZXC          (uint16_t PROGMEM [4]){KC_Z,    KC_X,    KC_C,    COMBO_END}
#define CHORD_XCV          (uint16_t PROGMEM [4]){KC_X,    KC_C,    KC_V,    COMBO_END}
#define CHORD_CVB          (uint16_t PROGMEM [4]){KC_C,    KC_V,    KC_B,    COMBO_END}
#define CHORD_JLU          (uint16_t PROGMEM [4]){KC_J,    KC_L,    KC_U,    COMBO_END}
#define CHORD_LUY          (uint16_t PROGMEM [4]){KC_L,    KC_U,    KC_Y,    COMBO_END}
#define CHORD_UYSCLN       (uint16_t PROGMEM [4]){KC_U,    KC_Y,    KC_SCLN, COMBO_END}
#define CHORD_HNE          (uint16_t PROGMEM [4]){KC_H,    KC_N,    KC_E,    COMBO_END}
#define CHORD_NEI          (uint16_t PROGMEM [4]){KC_N,    KC_E,    KC_I,    COMBO_END}
#define CHORD_EIO          (uint16_t PROGMEM [4]){KC_E,    KC_I,    KC_O,    COMBO_END}
#define CHORD_KMCOMM       (uint16_t PROGMEM [4]){KC_K,    KC_M,    KC_COMM, COMBO_END}
#define CHORD_MCOMMDOT     (uint16_t PROGMEM [4]){KC_M,    KC_COMM, KC_DOT,  COMBO_END}
#define CHORD_COMMDOTSLSH  (uint16_t PROGMEM [4]){KC_COMM, KC_DOT,  KC_SLSH, COMBO_END}

#define CHORD_QWAR         (uint16_t PROGMEM [5]){KC_Q, KC_W, KC_A, KC_R, COMBO_END}
#define CHORD_WFRS         (uint16_t PROGMEM [5]){KC_W, KC_F, KC_R, KC_S, COMBO_END}
#define CHORD_FPST         (uint16_t PROGMEM [5]){KC_F, KC_P, KC_S, KC_T, COMBO_END}
#define CHORD_PGTD         (uint16_t PROGMEM [5]){KC_P, KC_G, KC_T, KC_D, COMBO_END}
#define CHORD_ARZX         (uint16_t PROGMEM [5]){KC_A, KC_R, KC_Z, KC_X, COMBO_END}
#define CHORD_RSXC         (uint16_t PROGMEM [5]){KC_R, KC_S, KC_X, KC_C, COMBO_END}
#define CHORD_STCV         (uint16_t PROGMEM [5]){KC_S, KC_T, KC_C, KC_V, COMBO_END}
#define CHORD_TDVB         (uint16_t PROGMEM [5]){KC_T, KC_D, KC_V, KC_B, COMBO_END}
#define CHORD_JLHN         (uint16_t PROGMEM [5]){KC_J, KC_L, KC_H, KC_N, COMBO_END}
#define CHORD_LUNE         (uint16_t PROGMEM [5]){KC_L, KC_U, KC_N, KC_E, COMBO_END}
#define CHORD_UYEI         (uint16_t PROGMEM [5]){KC_U, KC_Y, KC_E, KC_I, COMBO_END}
#define CHORD_YSCLNIO      (uint16_t PROGMEM [5]){KC_Y, KC_SCLN, KC_I, KC_O, COMBO_END}
#define CHORD_HNKM         (uint16_t PROGMEM [5]){KC_H, KC_N, KC_K, KC_M, COMBO_END}
#define CHORD_NEMCOMM      (uint16_t PROGMEM [5]){KC_N, KC_E, KC_M, KC_COMM, COMBO_END}
#define CHORD_EICOMMDOT    (uint16_t PROGMEM [5]){KC_E, KC_I, KC_COMM, KC_DOT, COMBO_END}
#define CHORD_IODOTSLSH    (uint16_t PROGMEM [5]){KC_I, KC_O, KC_DOT, KC_SLSH, COMBO_END}

/// Qwerty
#define CHORD_WS        (uint16_t PROGMEM [3]){KC_W,    KC_S,     COMBO_END}
#define CHORD_ED        (uint16_t PROGMEM [3]){KC_E,    KC_D,     COMBO_END}
#define CHORD_RF        (uint16_t PROGMEM [3]){KC_R,    KC_F,     COMBO_END}
#define CHORD_TG        (uint16_t PROGMEM [3]){KC_T,    KC_G,     COMBO_END}
#define CHORD_YH        (uint16_t PROGMEM [3]){KC_Y,    KC_H,     COMBO_END}
#define CHORD_UJ        (uint16_t PROGMEM [3]){KC_U,    KC_J,     COMBO_END}
#define CHORD_IK        (uint16_t PROGMEM [3]){KC_I,    KC_K,     COMBO_END}
#define CHORD_OL        (uint16_t PROGMEM [3]){KC_O,    KC_L,     COMBO_END}
#define CHORD_PSCLN     (uint16_t PROGMEM [3]){KC_P,    KC_SCLN,  COMBO_END}
#define CHORD_SX        (uint16_t PROGMEM [3]){KC_S,    KC_X,     COMBO_END}
#define CHORD_DC        (uint16_t PROGMEM [3]){KC_D,    KC_C,     COMBO_END}
#define CHORD_FV        (uint16_t PROGMEM [3]){KC_F,    KC_V,     COMBO_END}
#define CHORD_GB        (uint16_t PROGMEM [3]){KC_G,    KC_B,     COMBO_END}
#define CHORD_HN        (uint16_t PROGMEM [3]){KC_H,    KC_N,     COMBO_END}
#define CHORD_JM        (uint16_t PROGMEM [3]){KC_J,    KC_M,     COMBO_END}
#define CHORD_KCOMM     (uint16_t PROGMEM [3]){KC_K,    KC_COMM,  COMBO_END}
#define CHORD_LDOT      (uint16_t PROGMEM [3]){KC_L,    KC_DOT,   COMBO_END}
#define CHORD_SCLNSLSH  (uint16_t PROGMEM [3]){KC_SCLN, KC_SLSH,  COMBO_END}

//// Combos
/// qwerty
#define COMBO_QA_1    COMBO(CHORD_QA, KC_1)
#define COMBO_WR_2    COMBO(CHORD_WR, KC_2)
#define COMBO_FS_3    COMBO(CHORD_FS, KC_3)
#define COMBO_PT_4    COMBO(CHORD_PT, KC_4)
#define COMBO_GD_5    COMBO(CHORD_GD, KC_5)
#define COMBO_JH_6    COMBO(CHORD_JH, KC_6)
#define COMBO_LN_7    COMBO(CHORD_LN, KC_7)
#define COMBO_UE_8    COMBO(CHORD_UE, KC_8)
#define COMBO_YI_9    COMBO(CHORD_YI, KC_9)
#define COMBO_SCLNO_0 COMBO(CHORD_SCLNO, KC_0)

#define COMBO_JL_7       COMBO(CHORD_JL, KC_7)
#define COMBO_LU_8       COMBO(CHORD_LU, KC_8)
#define COMBO_UY_9       COMBO(CHORD_UY, KC_9)
#define COMBO_YSCLN_0    COMBO(CHORD_YSCLN, KC_0)
#define COMBO_HN_6       COMBO(CHORD_HN, KC_6)
#define COMBO_NE_5       COMBO(CHORD_NE, KC_5)
#define COMBO_EI_4       COMBO(CHORD_EI, KC_4)
#define COMBO_KM_3       COMBO(CHORD_KM, KC_3)
#define COMBO_MCOMM_2    COMBO(CHORD_MCOMM, KC_2)
#define COMBO_COMMDOT_1  COMBO(CHORD_COMMDOT, KC_1)

#define COMBO_AZ_EXLM    COMBO(CHORD_AZ, KC_EXLM)
#define COMBO_RX_AT      COMBO(CHORD_RX, KC_AT)
#define COMBO_SC_HASH    COMBO(CHORD_SC, KC_HASH)
#define COMBO_TV_DLR     COMBO(CHORD_TV, KC_DLR)
#define COMBO_DB_PERC    COMBO(CHORD_DB, KC_PERC)
#define COMBO_HK_CIRC    COMBO(CHORD_HK, KC_CIRC)
#define COMBO_NM_AMPR    COMBO(CHORD_NM, KC_AMPR)
#define COMBO_ECOMM_ASTR COMBO(CHORD_ECOMM, KC_ASTR)
#define COMBO_IDOT_LPRN  COMBO(CHORD_IDOT,  KC_LPRN)
#define COMBO_OSLSH_RPRN COMBO(CHORD_OSLSH, KC_RPRN)

#define COMBO_WS_2    COMBO(CHORD_WS, KC_2)
#define COMBO_ED_3    COMBO(CHORD_ED, KC_3)
#define COMBO_RF_4    COMBO(CHORD_RF, KC_4)
#define COMBO_TG_5    COMBO(CHORD_TG, KC_5)
#define COMBO_YH_6    COMBO(CHORD_YH, KC_6)
#define COMBO_UJ_7    COMBO(CHORD_UJ, KC_7)
#define COMBO_IK_8    COMBO(CHORD_IK, KC_8)
#define COMBO_OL_9    COMBO(CHORD_OL, KC_9)
#define COMBO_PSCLN_0 COMBO(CHORD_PSCLN, KC_0)

#define COMBO_SX_AT         COMBO(CHORD_SX, KC_AT)
#define COMBO_DC_HASH       COMBO(CHORD_DC, KC_HASH)
#define COMBO_FV_DLR        COMBO(CHORD_FV, KC_DLR)
#define COMBO_GB_PERC       COMBO(CHORD_GB, KC_PERC)
#define COMBO_HN_CIRC       COMBO(CHORD_HN, KC_CIRC)
#define COMBO_JM_AMPR       COMBO(CHORD_JM, KC_AMPR)
#define COMBO_KCOMM_ASTR    COMBO(CHORD_KCOMM, KC_ASTR)
#define COMBO_LDOT_LPRN     COMBO(CHORD_LDOT, KC_LPRN)
#define COMBO_SCLNSLSH_RPRN COMBO(CHORD_SCLNSLSH, KC_RPRN)
