#include "skdm.h"

#include "hg_keycodes.h"
#include "td_extras.h"

static int td_skdm1_state = 0;
static int td_skdm2_state = 0;

int td_skdm_handler(tap_dance_state_t *state, void *user_data, int kc_play, int kc_start) {
    // TODO: try to remember why you put this check in to begin with...
    // if (keycode < DYNAMIC_MACRO_RANGE) {
    //     return;
    // }

    keyrecord_t record;
    record.event.pressed = false;
    uint16_t keycode = DM_RSTP;
    int curr_td_state = process_td_state(state, user_data);
    switch (curr_td_state) {
        case SINGLE: keycode = kc_play; break;
        case TRIPLE: keycode = kc_start; break;
        default: record.event.pressed = true; break;
    }

    process_dynamic_macro(keycode, &record);

    return curr_td_state;
}

void td_skdm1_finished(tap_dance_state_t *state, void *user_data) {
    td_skdm1_state = td_skdm_handler(state, user_data, DM_PLY1, DM_REC1);
}

void td_skdm2_finished(tap_dance_state_t *state, void *user_data) {
    td_skdm2_state = td_skdm_handler(state, user_data, DM_PLY2, DM_REC2);
}

void td_skdm1_reset(tap_dance_state_t *state, void *user_data) {
    td_skdm1_state = 0;
}

void td_skdm2_reset(tap_dance_state_t *state, void *user_data) {
    td_skdm2_state = 0;
}
