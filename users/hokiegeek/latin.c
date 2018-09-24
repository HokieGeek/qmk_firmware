#include "latin.h"
#include "td_extras.h"

static bool useLatinChar = false;
inline void latin_latch_td(td_stage stage) {
    useLatinChar = true;
}

bool latin_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LATIN_LATCH:
            useLatinChar = true;
            break;
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
                    useLatinChar = false;
                } else {
                    switch (keycode) {
                        case LATIN_E:       key_tap(KC_E); break;
                        case LATIN_A:       key_tap(KC_A); break;
                        case LATIN_I:       key_tap(KC_I); break;
                        case LATIN_O:       key_tap(KC_O); break;
                        case LATIN_U:       key_tap(KC_U); break;
                        case LATIN_N:       key_tap(KC_N); break;

                        case LATIN_IEXC:    register_code(KC_LSHIFT);
                                            key_tap(KC_1);
                                            unregister_code(KC_LSHIFT);
                                            break;

                        case LATIN_IQS:     register_code(KC_LSHIFT);
                                            key_tap(KC_SLASH);
                                            unregister_code(KC_LSHIFT);
                                            break;
                    }
                }
            }
            return false;
            break;
    }

    return true;
}
