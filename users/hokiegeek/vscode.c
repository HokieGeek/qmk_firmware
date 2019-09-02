#include "vscode.h"

#include "keycodes.h"
#include "taps.h"

uint8_t vsc_scm_mods[] = {2, KC_LCTRL, KC_LSHIFT};

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
                tap_mods_key(vsc_scm_mods, KC_G);
                tap_key(KC_G);
            }
            return false;
    }
    return true;
}
