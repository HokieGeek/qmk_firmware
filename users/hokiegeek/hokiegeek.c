#include <mousekey.h>
#include "hokiegeek.h"

void mousekey_tap(uint8_t code) {
    mousekey_on(code);
    mousekey_send();
    mousekey_off(code);
    mousekey_send();
}

void key_tap(uint8_t code) {
    register_code(code);
    unregister_code(code);
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

__attribute__ ((weak))
void check_encoder(void) { }

__attribute__ ((weak))
void encoder_init(void) { }

void userspace_matrix_init_user(void) {
    encoder_init();
}

void userspace_matrix_scan_user(void) {
    check_encoder();
}

bool userspace_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // LAYOUTS
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;

        // ACCENTS
        case LATIN_E:
        case LATIN_A:
        case LATIN_I:
        case LATIN_O:
        case LATIN_U:
        case LATIN_N:
        case LATIN_IEXC:
        case LATIN_IQS:
            if (record->event.pressed) {
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
            }
            return false;
            break;

        // ASCII
        case ASCII_SHRUG:
            if (record->event.pressed) {
                SEND_STRING("¯\\_(ツ)_/¯");
            }
            return false;
            break;

        // RANDOM
        case QMK_MAKE:
            if (record->event.pressed) {
                // Thanks, @drashna!
                SEND_DELAYED(10, "make " QMK_KEYBOARD ":" QMK_KEYMAP
#if  (defined(BOOTLOADER_DFU) || defined(BOOTLOADER_LUFA_DFU) || defined(BOOTLOADER_QMK_DFU))
                   ":dfu"
#elif defined(BOOTLOADER_HALFKAY)
                   ":teensy"
#elif defined(BOOTLOADER_CATERINA)
                   ":avrdude"
#endif // bootloader options
                   SS_TAP(X_ENTER));
                reset_keyboard();
            }
            return false;
            break;
    }

#ifdef TAP_DANCE_ENABLE
    return tmux_process_record_user(keycode, record);
#else
    return true;
#endif
}
