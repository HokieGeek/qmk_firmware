#include "td_extras.h"

td_state process_td_state(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
            return SINGLE;
        }
        return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted || !state->pressed) {
            return DOUBLE;
        }
        return DOUBLE_HOLD;
    } else if (state->count == 3) {
        if (state->interrupted || !state->pressed) {
            return TRIPLE;
        }
        return TRIPLE_HOLD;
    }
    return OTHER;
}

static int td_tap_hold_funcs_state = 0;
void td_tap_hold_funcs_finished(tap_dance_state_t *state, void *user_data) {
    td_funcs_t *funcs = (td_funcs_t *)user_data;
    td_tap_hold_funcs_state = process_td_state(state, user_data);

    switch (td_tap_hold_funcs_state) {
        case SINGLE:      funcs->f1(TD_FINISHED); break;
        case SINGLE_HOLD: funcs->f2(TD_FINISHED); break;
    }
}

void td_tap_hold_funcs_reset(tap_dance_state_t *state, void *user_data) {
    td_funcs_t *funcs = (td_funcs_t *)user_data;
    switch (td_tap_hold_funcs_state) {
        case SINGLE_HOLD: funcs->f2(TD_RESET); break;
    }
    td_tap_hold_funcs_state = 0;
}

void td_single_double_funcs(tap_dance_state_t *state, void *user_data) {
    td_funcs_t *funcs = (td_funcs_t *)user_data;
    td_tap_hold_funcs_state = process_td_state(state, user_data);

    switch (td_tap_hold_funcs_state) {
        case SINGLE: funcs->f1(TD_FINISHED); break;
        case DOUBLE: funcs->f2(TD_FINISHED); break;
    }
}

void td_key_mod(td_stage stage, uint16_t key) {
    switch (stage) {
        case TD_ON_EACH_TAP: break;
        case TD_FINISHED: register_code(key); break;
        case TD_RESET: unregister_code(key); break;
    }
}

void td_key(td_stage stage, uint16_t key) {
    if (stage == TD_FINISHED) {
        tap_code16(key);
    }
}

void td_layer_on_hold(td_stage stage, uint16_t layer) {
    switch (stage) {
        case TD_FINISHED: layer_on(layer); break;
        case TD_RESET: layer_off(layer); break;
        default: break;
    }
}
