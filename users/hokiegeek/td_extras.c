#include "td_extras.h"

static int td_tap_hold_funcs_state = 0;
void td_tap_hold_funcs_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_funcs_t *funcs = (td_funcs_t *)user_data;
    td_tap_hold_funcs_state = process_td_state(state, user_data);

    switch (td_tap_hold_funcs_state) {
        case SINGLE:      funcs->f1(TD_FINISHED); break;
        case SINGLE_HOLD: funcs->f2(TD_FINISHED); break;
    }
}

void td_tap_hold_funcs_reset(qk_tap_dance_state_t *state, void *user_data) {
    td_funcs_t *funcs = (td_funcs_t *)user_data;
    switch (td_tap_hold_funcs_state) {
        case SINGLE_HOLD: funcs->f2(TD_RESET); break;
    }
    td_tap_hold_funcs_state = 0;
}

td_state process_td_state(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
            return SINGLE;
        } else {
            return SINGLE_HOLD;
        }
    } else if (state->count == 2) {
        if (state->interrupted || !state->pressed) {
            return DOUBLE;
        } else {
            return DOUBLE_HOLD;
        }
    } else if (state->count == 3) {
        if (state->interrupted || !state->pressed) {
            return TRIPLE;
        } else {
            return TRIPLE_HOLD;
        }
    } else {
        return OTHER;
    }
}
