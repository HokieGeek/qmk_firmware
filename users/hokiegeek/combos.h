#pragma once

#include "quantum.h"

enum {
    //// colemak
    // numbers
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

    // symbols
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

    //// qwerty
    // numbers
    WS,
    ED,
    RF,
    TG,
    YH,
    UJ,
    IK,
    OL,
    PSCLN,

    // symbols
    SX,
    DC,
    FV,
    GB,
    HN,
    JM,
    KCOMM,
    LDOT,
    SCLNSLSH
};

extern const uint16_t PROGMEM combos[][3];

#define COMBO_QA_1    COMBO(combos[QA], KC_1)
#define COMBO_WR_2    COMBO(combos[WR], KC_2)
#define COMBO_FS_3    COMBO(combos[FS], KC_3)
#define COMBO_PT_4    COMBO(combos[PT], KC_4)
#define COMBO_GD_5    COMBO(combos[GD], KC_5)
#define COMBO_JH_6    COMBO(combos[JH], KC_6)
#define COMBO_LN_7    COMBO(combos[LN], KC_7)
#define COMBO_UE_8    COMBO(combos[UE], KC_8)
#define COMBO_YI_9    COMBO(combos[YI], KC_9)
#define COMBO_SCLNO_0 COMBO(combos[SCLNO], KC_0)

#define COMBO_AZ_EXLM    COMBO(combos[AZ], KC_EXLM)
#define COMBO_RX_AT      COMBO(combos[RX], KC_AT)
#define COMBO_SC_HASH    COMBO(combos[SC], KC_HASH)
#define COMBO_TV_DLR     COMBO(combos[TV], KC_DLR)
#define COMBO_DB_PERC    COMBO(combos[DB], KC_PERC)
#define COMBO_HK_CIRC    COMBO(combos[HK], KC_CIRC)
#define COMBO_NM_AMPR    COMBO(combos[NM], KC_AMPR)
#define COMBO_ECOMM_ASTR COMBO(combos[ECOMM], KC_ASTR)
#define COMBO_IDOT_LPRN  COMBO(combos[IDOT],  KC_LPRN)
#define COMBO_OSLSH_RPRN COMBO(combos[OSLSH], KC_RPRN)

#define COMBO_WS_2    COMBO(combos[WS], KC_2)
#define COMBO_ED_3    COMBO(combos[ED], KC_3)
#define COMBO_RF_4    COMBO(combos[RF], KC_4)
#define COMBO_TG_5    COMBO(combos[TG], KC_5)
#define COMBO_YH_6    COMBO(combos[YH], KC_6)
#define COMBO_UJ_7    COMBO(combos[UJ], KC_7)
#define COMBO_IK_8    COMBO(combos[IK], KC_8)
#define COMBO_OL_9    COMBO(combos[OL], KC_9)
#define COMBO_PSCLN_0 COMBO(combos[PSCLN], KC_0)

#define COMBO_SX_AT         COMBO(combos[SX], KC_AT)
#define COMBO_DC_HASH       COMBO(combos[DC], KC_HASH)
#define COMBO_FV_DLR        COMBO(combos[FV], KC_DLR)
#define COMBO_GB_PERC       COMBO(combos[GB], KC_PERC)
#define COMBO_HN_CIRC       COMBO(combos[HN], KC_CIRC)
#define COMBO_JM_AMPR       COMBO(combos[JM], KC_AMPR)
#define COMBO_KCOMM_ASTR    COMBO(combos[KCOMM], KC_ASTR)
#define COMBO_LDOT_LPRN     COMBO(combos[LDOT], KC_LPRN)
#define COMBO_SCLNSLSH_RPRN COMBO(combos[SCLNSLSH], KC_RPRN)
