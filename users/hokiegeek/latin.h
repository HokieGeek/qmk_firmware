#ifndef USERSPACE_LATIN
#define USERSPACE_LATIN

#ifndef UNICODE_ENABLE
#define SEND_LATIN_MAC(str)   SEND_STRING(str)
#define SEND_LATIN_NIX(str)   SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LSHIFT)SS_TAP(X_U)SS_TAP(X_0)SS_TAP(X_0) str SS_UP(X_LCTRL)SS_UP(X_LSHIFT));
#endif

#ifdef TAP_DANCE_ENABLE
#include "td_extras.h"

void td_latin_finished(qk_tap_dance_state_t *state, void *user_data);
void td_latin_reset(qk_tap_dance_state_t *state, void *user_data);

#define TD_SHIFT_LATIN [td_shift_latin] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, td_latin_finished, td_latin_reset, 110)
#define SFT_LAT TD(td_shift_latin)
#else
#define SFT_LAT KC_TRNS
#endif // TAP_DANCE_ENABLE

bool latin_process_record_user(uint16_t keycode, keyrecord_t *record);

#endif // USERSPACE_LATIN
