#ifdef MOUSEKEY_ENABLE
#include <mousekey.h>
#endif
#include "hokiegeek.h"

void userspace_matrix_init_user(void) {
// #ifdef ENCODER_ENABLE
//     hgencoder_init();
// #endif
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
                set_unicode_input_mode(UNICODE_MODE_LINUX);
#endif
            }
            return false;
        case KC_OS_MAC:
            if (record->event.pressed) {
                setTargetOS(OS_MAC);
#ifdef UNICODE_ENABLE
                set_unicode_input_mode(UNICODE_MODE_MACOS);
#endif
            }
            return false;
        case KC_OS_WIN:
            if (record->event.pressed) {
                setTargetOS(OS_WIN);
#ifdef UNICODE_ENABLE
                set_unicode_input_mode(UNICODE_MODE_WINCOMPOSE);
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
                SEND_DELAYED(10, "qmk flash -kb " QMK_KEYBOARD " -km " QMK_KEYMAP SS_TAP(X_ENTER));
                reset_keyboard();
            }
            return false;
    }

    return true;
}
