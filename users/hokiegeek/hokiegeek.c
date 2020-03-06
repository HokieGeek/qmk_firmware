#include <mousekey.h>
#include "hokiegeek.h"

void userspace_matrix_init_user(void) {
#ifdef ENCODER_ENABLE
    hgencoder_init();
#endif
}

inline void tap_mousekey(uint8_t code) {
#ifdef MOUSEKEY_ENABLE
    mousekey_on(code);
    mousekey_send();
    mousekey_off(code);
    mousekey_send();
#endif
}

// void userspace_matrix_scan_user(void) {
// }

bool userspace_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // OS
        case KC_OS_NIX:
            if (record->event.pressed) {
                setTargetOS(OS_NIX);
            }
            return false;
            break;
        case KC_OS_MAC:
            if (record->event.pressed) {
                setTargetOS(OS_MAC);
            }
            return false;
            break;
        case KC_OS_WIN:
            if (record->event.pressed) {
                setTargetOS(OS_WIN);
            }
            return false;
            break;
    }

    if (!latin_process_record_user(keycode, record)) {
        return false;
    }

    if (!vscode_process_record_user(keycode, record)) {
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

        // TODO: DO NOT REMOVE OR IT WILL INCREASE FIRMWARE SIZE
        case KC_LATIN:
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
