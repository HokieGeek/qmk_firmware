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

void tap_ctltab() {
    register_code(KC_LCTL);
    register_code(KC_TAB);
    unregister_code(KC_TAB);
    unregister_code(KC_LCTL);
}

void tap_ctltab_td(td_stage stage) {
    tap_ctltab();
}

void userspace_matrix_init_user(void) {
}

void userspace_matrix_scan_user(void) {
}

bool userspace_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!latin_process_record_user(keycode, record)) {
        return false;
    }

#ifdef TAP_DANCE_ENABLE
    if (!tmux_process_record_user(keycode, record)) {
        return false;
    }
#endif

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

    return true;
}
