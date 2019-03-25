#include "td_extras.h"

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

void td_single_double_funcs(qk_tap_dance_state_t *state, void *user_data) {
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
        register_code(key);
        unregister_code(key);
    }
}

// void td_send_stsing(td_stage stage, uint16_t key) {
//     if (stage == TD_FINISHED) {
//         SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_GRAVE))));
//     }
// }

inline void td_shift(td_stage stage) {
    td_key_mod(stage, KC_LSHIFT);
}
