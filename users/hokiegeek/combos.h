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

extern const uint16_t PROGMEM chords2[][3];
extern const uint16_t PROGMEM chords3[][4];
extern const uint16_t PROGMEM chords4[][5];

/// qwerty
#define COMBO_QA_1    COMBO(chords2[QA], KC_1)
#define COMBO_WR_2    COMBO(chords2[WR], KC_2)
#define COMBO_FS_3    COMBO(chords2[FS], KC_3)
#define COMBO_PT_4    COMBO(chords2[PT], KC_4)
#define COMBO_GD_5    COMBO(chords2[GD], KC_5)
#define COMBO_JH_6    COMBO(chords2[JH], KC_6)
#define COMBO_LN_7    COMBO(chords2[LN], KC_7)
#define COMBO_UE_8    COMBO(chords2[UE], KC_8)
#define COMBO_YI_9    COMBO(chords2[YI], KC_9)
#define COMBO_SCLNO_0 COMBO(chords2[SCLNO], KC_0)

#define COMBO_JL_7       COMBO(chords2[JL], KC_7)
#define COMBO_LU_8       COMBO(chords2[LU], KC_8)
#define COMBO_UY_9       COMBO(chords2[UY], KC_9)
#define COMBO_YSCLN_0    COMBO(chords2[YSCLN], KC_0)
#define COMBO_HN_6       COMBO(chords2[HN], KC_6)
#define COMBO_NE_5       COMBO(chords2[NE], KC_5)
#define COMBO_EI_4       COMBO(chords2[EI], KC_4)
#define COMBO_KM_3       COMBO(chords2[KM], KC_3)
#define COMBO_MCOMM_2    COMBO(chords2[MCOMM], KC_2)
#define COMBO_COMMDOT_1  COMBO(chords2[COMMDOT], KC_1)

#define COMBO_AZ_EXLM    COMBO(chords2[AZ], KC_EXLM)
#define COMBO_RX_AT      COMBO(chords2[RX], KC_AT)
#define COMBO_SC_HASH    COMBO(chords2[SC], KC_HASH)
#define COMBO_TV_DLR     COMBO(chords2[TV], KC_DLR)
#define COMBO_DB_PERC    COMBO(chords2[DB], KC_PERC)
#define COMBO_HK_CIRC    COMBO(chords2[HK], KC_CIRC)
#define COMBO_NM_AMPR    COMBO(chords2[NM], KC_AMPR)
#define COMBO_ECOMM_ASTR COMBO(chords2[ECOMM], KC_ASTR)
#define COMBO_IDOT_LPRN  COMBO(chords2[IDOT],  KC_LPRN)
#define COMBO_OSLSH_RPRN COMBO(chords2[OSLSH], KC_RPRN)

#define COMBO_WS_2    COMBO(chords2[WS], KC_2)
#define COMBO_ED_3    COMBO(chords2[ED], KC_3)
#define COMBO_RF_4    COMBO(chords2[RF], KC_4)
#define COMBO_TG_5    COMBO(chords2[TG], KC_5)
#define COMBO_YH_6    COMBO(chords2[YH], KC_6)
#define COMBO_UJ_7    COMBO(chords2[UJ], KC_7)
#define COMBO_IK_8    COMBO(chords2[IK], KC_8)
#define COMBO_OL_9    COMBO(chords2[OL], KC_9)
#define COMBO_PSCLN_0 COMBO(chords2[PSCLN], KC_0)

#define COMBO_SX_AT         COMBO(chords2[SX], KC_AT)
#define COMBO_DC_HASH       COMBO(chords2[DC], KC_HASH)
#define COMBO_FV_DLR        COMBO(chords2[FV], KC_DLR)
#define COMBO_GB_PERC       COMBO(chords2[GB], KC_PERC)
#define COMBO_HN_CIRC       COMBO(chords2[HN], KC_CIRC)
#define COMBO_JM_AMPR       COMBO(chords2[JM], KC_AMPR)
#define COMBO_KCOMM_ASTR    COMBO(chords2[KCOMM], KC_ASTR)
#define COMBO_LDOT_LPRN     COMBO(chords2[LDOT], KC_LPRN)
#define COMBO_SCLNSLSH_RPRN COMBO(chords2[SCLNSLSH], KC_RPRN)
