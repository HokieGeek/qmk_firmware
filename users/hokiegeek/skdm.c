#include "skdm.h"

#include "keycodes.h"
#include "td_extras.h"

#include "dynamic_macro.h"

static int td_skdm1_state = 0;
static int td_skdm2_state = 0;

void td_skdm_finished(uint16_t keycode) {
    keyrecord_t record;

    if (keycode >= DYNAMIC_MACRO_RANGE) {
        record.event.pressed = true;
        process_record_dynamic_macro(keycode, &record);
        record.event.pressed = false;
        process_record_dynamic_macro(keycode, &record);
    }
}

void td_skdm1_finished(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t keycode = DYNAMIC_MACRO_RANGE;
    td_skdm1_state = process_td_state(state, user_data);

    switch (td_skdm1_state) {
        case SINGLE: keycode = DYN_MACRO_PLAY1; break;
        case DOUBLE: keycode = DYN_REC_STOP; break;
        case TRIPLE: keycode = DYN_REC_START1; break;
    }

    td_skdm_finished(keycode);
}

void td_skdm2_finished(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t keycode = DYNAMIC_MACRO_RANGE;
    td_skdm2_state = process_td_state(state, user_data);

    switch (td_skdm2_state) {
        case SINGLE: keycode = DYN_MACRO_PLAY2; break;
        case DOUBLE: keycode = DYN_REC_STOP; break;
        case TRIPLE: keycode = DYN_REC_START2; break;
    }

    td_skdm_finished(keycode);
}

void td_skdm1_reset(qk_tap_dance_state_t *state, void *user_data) {
    td_skdm1_state = 0;
}

void td_skdm2_reset(qk_tap_dance_state_t *state, void *user_data) {
    td_skdm2_state = 0;
}
