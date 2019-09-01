#include "vscode.h"

#include "keycodes.h"

bool vscode_process_record_user(uint16_t keycode, keyrecord_t *record) {
    /*
    switch (keycode) {
        case KC_VSCODE:
            if (record->event.pressed) {
                layer_on(_VSCODE);
            } else {
                layer_off(_VSCODE);
            }
            return false;
        case VSC_TODO:
            SEND_STRING("TODO");
            return false;
    }
    */
    return true;
}
