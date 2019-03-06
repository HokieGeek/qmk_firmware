#ifndef USERSPACE_LATIN
#define USERSPACE_LATIN

#include "keycodes.h"

#define LATIN_E_PRIMARY_KC    KC_E
#define LATIN_A_PRIMARY_KC    KC_A
#define LATIN_I_PRIMARY_KC    KC_I
#define LATIN_O_PRIMARY_KC    KC_O
#define LATIN_U_PRIMARY_KC    KC_U
#define LATIN_N_PRIMARY_KC    KC_N
#define LATIN_IEXC_PRIMARY_KC KC_1
#define LATIN_IQS_PRIMARY_KC  KC_SLASH

#ifdef ACCENTS_MAC
#define LATIN_E_STRING    SS_LALT("e")"e"
#define LATIN_A_STRING    SS_LALT("e")"a"
#define LATIN_I_STRING    SS_LALT("e")"i"
#define LATIN_O_STRING    SS_LALT("e")"o"
#define LATIN_U_STRING    SS_LALT("e")"u"
#define LATIN_N_STRING    SS_LALT("n")"n"
#define LATIN_IEXC_STRING SS_LALT("1")
#define LATIN_IQS_STRING  SS_LALT("?")
#define SEND_LATIN(str)   SEND_STRING(str)
#else
#define LATIN_E_STRING    SS_TAP(X_E)SS_TAP(X_9)
#define LATIN_A_STRING    SS_TAP(X_E)SS_TAP(X_1)
#define LATIN_I_STRING    SS_TAP(X_E)SS_TAP(X_D)
#define LATIN_O_STRING    SS_TAP(X_F)SS_TAP(X_3)
#define LATIN_U_STRING    SS_TAP(X_F)SS_TAP(X_A)
#define LATIN_N_STRING    SS_TAP(X_F)SS_TAP(X_1)
#define LATIN_IEXC_STRING SS_TAP(X_A)SS_TAP(X_1)
#define LATIN_IQS_STRING  SS_TAP(X_B)SS_TAP(X_F)
#define SEND_LATIN(str)   SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LSHIFT)SS_TAP(X_U)SS_TAP(X_0)SS_TAP(X_0) str SS_UP(X_LCTRL)SS_UP(X_LSHIFT));
#endif

#ifdef TAP_DANCE_ENABLE
#include "td_extras.h"

void td_latin_finished(qk_tap_dance_state_t *state, void *user_data);
void td_latin_reset(qk_tap_dance_state_t *state, void *user_data);

#define TD_SHIFT_LATIN [td_shift_latin] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, td_latin_finished, td_latin_reset, 110)
#define SFT_LAT TD(td_shift_latin)
#else
#define SFT_LAT KC_TRNS
#endif

/*
enum latin_custom_keycodes {
    LATIN_LATCH = _LATIN_START,
    LATIN_E,
    LATIN_A,
    LATIN_I,
    LATIN_O,
    LATIN_U,
    LATIN_N,
    LATIN_IEXC,
    LATIN_IQS,

    LATIN_SAFE_RANGE,
};
*/

bool latin_process_record_user(uint16_t keycode, keyrecord_t *record);

#endif // USERSPACE_LATIN
