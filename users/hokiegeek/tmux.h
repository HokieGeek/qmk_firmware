#ifndef USERSPACE_TMUX
#define USERSPACE_TMUX

#include "quantum.h"

/*
enum tmux_custom_keycodes {
    TMUX_NEXT = SAFE_RANGE,
    TMUX_PREV,
    TMUX_LAST,
    TMUX_PEEK,

    TMUX_SAFE_RANGE,
};
*/

#define KC_TMUX TD(td_tmux)
#define TMUX_PREFIX X_A
#define SS_TMUX_PREFIX SS_DOWN(X_LCTL)SS_TAP(TMUX_PREFIX)SS_UP(X_LCTL)
#define SEND_TMUX(c) SEND_STRING(SS_TMUX_PREFIX""c);

#ifndef TMUX_ENTRY_TAPPING_TERM
#define TMUX_ENTRY_TAPPING_TERM 160
#endif
#define TD_TMUX_ENTRY [td_tmux] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_tmux_finished, td_tmux_reset)

void td_tmux_finished(tap_dance_state_t *state, void *user_data);
void td_tmux_reset(tap_dance_state_t *state, void *user_data);

bool tmux_process_record_user(uint16_t keycode, keyrecord_t *record);

#endif // USERSPACE_TMUX
