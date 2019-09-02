#include "latin.h"
#include "taps.h"

bool useLatinChar = false;

// static int td_latin_state = 0;

#ifdef TAP_DANCE_ENABLE
#include "td_extras.h"

void td_latin_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state td_latin_state = process_td_state(state, user_data);
    // tap_key(KC_Q);

    switch (td_latin_state) {
        case SINGLE:      useLatinChar = true; break;
        case SINGLE_HOLD: register_code(KC_LSHIFT); break;
        default: break;
    }
}

void td_latin_reset(qk_tap_dance_state_t *state, void *user_data) {
    // if (td_latin_state == SINGLE_HOLD) {
        unregister_code(KC_LSHIFT);
    // }
    // td_latin_state = 0;
}
#endif

bool latin_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LATIN_E:
        case LATIN_A:
        case LATIN_I:
        case LATIN_O:
        case LATIN_U:
        case LATIN_N:
        case LATIN_IEXC:
        case LATIN_IQS:
            if (record->event.pressed) {
                if (useLatinChar) {
                    switch (keycode) {
                        case LATIN_E:       SEND_LATIN(LATIN_E_STRING); break;
                        case LATIN_A:       SEND_LATIN(LATIN_A_STRING); break;
                        case LATIN_I:       SEND_LATIN(LATIN_I_STRING); break;
                        case LATIN_O:       SEND_LATIN(LATIN_O_STRING); break;
                        case LATIN_U:       SEND_LATIN(LATIN_U_STRING); break;
                        case LATIN_N:       SEND_LATIN(LATIN_N_STRING); break;
                        case LATIN_IEXC:    SEND_LATIN(LATIN_IEXC_STRING); break;
                        case LATIN_IQS:     SEND_LATIN(LATIN_IQS_STRING); break;
                    }
                } else {
                    switch (keycode) {
                        case LATIN_E:       tap_key(LATIN_E_PRIMARY_KC); break;
                        case LATIN_A:       tap_key(LATIN_A_PRIMARY_KC); break;
                        case LATIN_I:       tap_key(LATIN_I_PRIMARY_KC); break;
                        case LATIN_O:       tap_key(LATIN_O_PRIMARY_KC); break;
                        case LATIN_U:       tap_key(LATIN_U_PRIMARY_KC); break;
                        case LATIN_N:       tap_key(LATIN_N_PRIMARY_KC); break;
                        case LATIN_IEXC:    tap_key(LATIN_IEXC_PRIMARY_KC); break;
                        case LATIN_IQS:     tap_key(LATIN_IQS_PRIMARY_KC); break;
                    }
                }
            }
            useLatinChar = false;
            return false;
            break;
    }

    if (keycode < QK_LAYER_TAP_TOGGLE || keycode > QK_LAYER_TAP_TOGGLE_MAX) {
        useLatinChar = false;
    }

    return true;
}
