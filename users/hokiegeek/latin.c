#include "latin.h"
#include "td_extras.h"

bool useLatinChar = false;

// static int td_latin_state = 0;

void td_latin_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state td_latin_state = process_td_state(state, user_data);
    // key_tap(KC_Q);

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
                        case LATIN_E:       key_tap(LATIN_E_PRIMARY_KC); break;
                        case LATIN_A:       key_tap(LATIN_A_PRIMARY_KC); break;
                        case LATIN_I:       key_tap(LATIN_I_PRIMARY_KC); break;
                        case LATIN_O:       key_tap(LATIN_O_PRIMARY_KC); break;
                        case LATIN_U:       key_tap(LATIN_U_PRIMARY_KC); break;
                        case LATIN_N:       key_tap(LATIN_N_PRIMARY_KC); break;
                        case LATIN_IEXC:    key_tap(LATIN_IEXC_PRIMARY_KC); break;
                        case LATIN_IQS:     key_tap(LATIN_IQS_PRIMARY_KC); break;
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
