#include "vscode.h"

#include "keycodes.h"

void vscode_layer_on_hold(td_stage stage) {
    switch (stage) {
        case TD_FINISHED: layer_on(_VSCODE); break;
        case TD_RESET:    layer_off(_VSCODE); break;
        default: break;
    }
}

bool vscode_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case VSC_SCM:
            if (record->event.pressed) {
                register_code(KC_LCTRL);
                register_code(KC_LSHIFT);
                register_code(KC_G);
                unregister_code(KC_G);
                unregister_code(KC_LSHIFT);
                unregister_code(KC_LCTRL);
                register_code(KC_G);
                unregister_code(KC_G);
            }
            return false;
    }
    return true;
}
