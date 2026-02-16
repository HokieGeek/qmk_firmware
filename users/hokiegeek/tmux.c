#include "tmux.h"

#include "hg_keycodes.h"
#include "td_extras.h"

static int td_tmux_state = 0;

void td_tmux_finished(tap_dance_state_t *state, void *user_data) {
    td_tmux_state = process_td_state(state, user_data);

    switch (td_tmux_state) {
        case SINGLE:      SEND_TMUX("n"); break;
        case SINGLE_HOLD: SEND_TMUX(""); break;
        case DOUBLE:      SEND_TMUX(SS_LCTL("a")); break;
        case DOUBLE_HOLD: SEND_TMUX(SS_LCTL("a")); break;
    }
}

void td_tmux_reset(tap_dance_state_t *state, void *user_data) {
    if (td_tmux_state == DOUBLE_HOLD) {
        SEND_TMUX(SS_LCTL("a"));
    }
    td_tmux_state = 0;
}

bool tmux_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TMUX_NEXT:
        case TMUX_PREV:
        case TMUX_LAST:
            if (record->event.pressed) {
                switch (keycode) {
                case TMUX_NEXT: SEND_TMUX("n"); break;
                case TMUX_PREV: SEND_TMUX("p"); break;
                case TMUX_LAST: SEND_TMUX(SS_LCTL("a")); break;
                }
            }
            return false;
            break;
        case TMUX_PEEK:
            SEND_TMUX(SS_LCTL("a"))
            return false;
    }
    return true;
}
