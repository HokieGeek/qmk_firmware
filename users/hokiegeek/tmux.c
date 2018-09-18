#include "tmux.h"

static int td_tmux_state = 0;

void td_tmux_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
            SEND_TMUX("n");
            td_tmux_state = SINGLE;
        } else {
            SEND_TMUX(SS_LCTRL("a"));
            td_tmux_state = HOLD;
        }
    } else if (state->count == 2) {
        SEND_TMUX(SS_LCTRL("a"));
        td_tmux_state = DOUBLE;
    }
}

void td_tmux_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (td_tmux_state == HOLD) {
        SEND_TMUX(SS_LCTRL("a"));
    }
    td_tmux_state = 0;
}

bool tmux_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // TMUX
        case TMUX_NEXT:
        case TMUX_PREV:
        case TMUX_LAST:
            if (record->event.pressed) {
                switch (keycode) {
                case TMUX_NEXT: SEND_TMUX("n"); break;
                case TMUX_PREV: SEND_TMUX("p"); break;
                case TMUX_LAST: SEND_TMUX(SS_LCTRL("a")); break;
                }
            }
            return false;
            break;
        case TMUX_PEEK:
            SEND_TMUX(SS_LCTRL("a"))
            return false;
            break;
    }
    return true;
}
