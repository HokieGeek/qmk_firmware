#include "combos.h"

#include "quantum.h"

/* Qwerty
 * ,-----------------------------------------.   ,-----------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |Ctl/Tb|   A  |   S  |   D  |   F  |   G  |   |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |SftLat|   Z  |   X  |   C  |   V  |   B  |   |   N  |   M  |   ,  |   .  |   /  |ShEnt |
 * `-----------------------------------------'   `-----------------------------------------'
 */

/*
 * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |
 * |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |
 */
const uint16_t PROGMEM combos[][3] = {
    // Colemak
    {KC_Q,      KC_A, COMBO_END},
    {KC_W,      KC_R, COMBO_END},
    {KC_F,      KC_S, COMBO_END},
    {KC_P,      KC_T, COMBO_END},
    {KC_G,      KC_D, COMBO_END},
    {KC_J,      KC_H, COMBO_END},
    {KC_L,      KC_N, COMBO_END},
    {KC_U,      KC_E, COMBO_END},
    {KC_Y,      KC_I, COMBO_END},
    {KC_SCOLON, KC_O, COMBO_END},

    {KC_A, KC_Z,    COMBO_END},
    {KC_R, KC_X,    COMBO_END},
    {KC_S, KC_C,    COMBO_END},
    {KC_T, KC_V,    COMBO_END},
    {KC_D, KC_B,    COMBO_END},
    {KC_H, KC_K,    COMBO_END},
    {KC_N, KC_M,    COMBO_END},
    {KC_E, KC_COMM, COMBO_END},
    {KC_I, KC_DOT,  COMBO_END},
    {KC_O, KC_SLSH, COMBO_END},

    // Qwerty
    {KC_W, KC_S,    COMBO_END},
    {KC_E, KC_D,    COMBO_END},
    {KC_R, KC_F,    COMBO_END},
    {KC_T, KC_G,    COMBO_END},
    {KC_Y, KC_H,    COMBO_END},
    {KC_U, KC_J,    COMBO_END},
    {KC_I, KC_K,    COMBO_END},
    {KC_O, KC_L,    COMBO_END},
    {KC_P, KC_SCLN, COMBO_END},

    {KC_S,    KC_X,     COMBO_END},
    {KC_D,    KC_C,     COMBO_END},
    {KC_F,    KC_V,     COMBO_END},
    {KC_G,    KC_B,     COMBO_END},
    {KC_H,    KC_N,     COMBO_END},
    {KC_J,    KC_M,     COMBO_END},
    {KC_K,    KC_COMM,  COMBO_END},
    {KC_L,    KC_DOT,   COMBO_END},
    {KC_SCLN, KC_SLSH,  COMBO_END}
};

combo_t key_combos[COMBO_COUNT] = {
    [QA_1]    = COMBO(combos[0], KC_1),
    [WR_2]    = COMBO(combos[1], KC_2),
    [FS_3]    = COMBO(combos[2], KC_3),
    [PT_4]    = COMBO(combos[3], KC_4),
    [GD_5]    = COMBO(combos[4], KC_5),
    [JH_6]    = COMBO(combos[5], KC_6),
    [LN_7]    = COMBO(combos[6], KC_7),
    [UE_8]    = COMBO(combos[7], KC_8),
    [YI_9]    = COMBO(combos[8], KC_9),
    [SCLNO_0] = COMBO(combos[9], KC_0),

    [AZ_EXLM]    = COMBO(combos[10], KC_EXLM),
    [RX_AT]      = COMBO(combos[11], KC_AT),
    [SC_HASH]    = COMBO(combos[12], KC_HASH),
    [TV_DLR]     = COMBO(combos[13], KC_DLR),
    [DB_PERC]    = COMBO(combos[14], KC_PERC),
    [HK_CIRC]    = COMBO(combos[15], KC_CIRC),
    [NM_AMPR]    = COMBO(combos[16], KC_AMPR),
    [ECOMM_ASTR] = COMBO(combos[17], KC_ASTR),
    [IDOT_LPRN]  = COMBO(combos[18], KC_LPRN),
    [OSLSH_RPRN] = COMBO(combos[19], KC_RPRN),

    // Qwerty
    [WS_2]    = COMBO(combos[20], KC_2),
    [ED_3]    = COMBO(combos[21], KC_3),
    [RF_4]    = COMBO(combos[22], KC_4),
    [TG_5]    = COMBO(combos[23], KC_5),
    [YH_6]    = COMBO(combos[24], KC_6),
    [UJ_7]    = COMBO(combos[25], KC_7),
    [IK_8]    = COMBO(combos[26], KC_8),
    [OL_9]    = COMBO(combos[27], KC_9),
    [PSCLN_0] = COMBO(combos[28], KC_0),

    [SX_AT]         = COMBO(combos[29], KC_AT),
    [DC_HASH]       = COMBO(combos[30], KC_HASH),
    [FV_DLR]        = COMBO(combos[31], KC_DLR),
    [GB_PERC]       = COMBO(combos[32], KC_PERC),
    [HN_CIRC]       = COMBO(combos[33], KC_CIRC),
    [JM_AMPR]       = COMBO(combos[34], KC_AMPR),
    [KCOMM_ASTR]    = COMBO(combos[35], KC_ASTR),
    [LDOT_LPRN]     = COMBO(combos[36], KC_LPRN),
    [SCLNSLSH_RPRN] = COMBO(combos[37], KC_RPRN)
};
