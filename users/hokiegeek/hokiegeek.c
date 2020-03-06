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

bool userspace_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // OS
        case KC_OS_NIX:
            if (record->event.pressed) {
                setTargetOS(OS_NIX);
#ifdef UNICODE_ENABLE
                set_unicode_input_mode(UC_LNX);
#endif
            }
            return false;
        case KC_OS_MAC:
            if (record->event.pressed) {
                setTargetOS(OS_MAC);
#ifdef UNICODE_ENABLE
                set_unicode_input_mode(UC_OSX);
#endif
            }
            return false;
        case KC_OS_WIN:
            if (record->event.pressed) {
                setTargetOS(OS_WIN);
#ifdef UNICODE_ENABLE
                set_unicode_input_mode(UC_WINC);
#endif
            }
            return false;
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
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;

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
    }

    return true;
}
