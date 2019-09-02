#include <mousekey.h>
#include "hokiegeek.h"

#ifdef TAP_DANCE_ENABLE
void tap_gui_shift_enter_td(td_stage stage) {
    tap_gui_shift_enter();
}

void tap_ctltab_td(td_stage stage) {
    tap_ctltab();
}
#else
#include "dynamic_macro.h"
#endif

void userspace_matrix_init_user(void) {
#ifdef ENCODER_ENABLE
    hgencoder_init();
#endif
}

// void userspace_matrix_scan_user(void) {
// }

bool userspace_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_dynamic_macro(keycode, record)) {
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
