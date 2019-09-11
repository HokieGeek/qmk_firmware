#include "vscode.h"

#include "hokiegeek.h"
#include "keycodes.h"
#include "taps.h"

void vscode_layer_on_hold(td_stage stage) {
    switch (stage) {
        case TD_FINISHED: layer_on(_VSCODE); break;
        case TD_RESET:    layer_off(_VSCODE); break;
        default: break;
    }
}

bool vscode_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case VSC_PROBS:
            if (record->event.pressed) {
                switch (getTargetOS()) {
                    case OS_MAC: {
                        uint8_t mods[] = {2, KC_LGUI, KC_LSHIFT};
                        tap_mods_key(mods, KC_M);
                    }
                    break;
                    case OS_NIX: {
                        uint8_t mods[] = {2, KC_LCTRL, KC_LSHIFT};
                        tap_mods_key(mods, KC_M);
                    }
                    break;
                }
            }
            return false;
        case VSC_SCM:
            if (record->event.pressed) {
                switch (getTargetOS()) {
                    case OS_MAC: {
                        uint8_t mods[] = {2, KC_LCTRL, KC_LSHIFT};
                        tap_mods_key(mods, KC_G);
                    }
                    break;
                    case OS_NIX: {
                        uint8_t mods[] = {2, KC_LCTRL, KC_LSHIFT};
                        tap_mods_key(mods, KC_G);
                        tap_key(KC_G);
                    }
                    break;
                }
            }
            return false;
        case VSC_FIND:
            if (record->event.pressed) {
                switch (getTargetOS()) {
                    case OS_MAC: {
                        uint8_t mods[] = {2, KC_LGUI, KC_LSHIFT};
                        tap_mods_key(mods, KC_F);
                    }
                    break;
                    case OS_NIX: {
                        uint8_t mods[] = {2, KC_LCTRL, KC_LSHIFT};
                        tap_mods_key(mods, KC_F);
                    }
                    break;
                }
            }
            return false;
        case VSC_TERM:
            if (record->event.pressed) {
                switch (getTargetOS()) {
                    case OS_MAC:
                        tap_mod_key(KC_LCTRL, KC_GRAVE);
                        break;
                    case OS_NIX:
                        tap_mod_key(KC_LCTRL, KC_GRAVE);
                        break;
                }
            }
            return false;
        case VSC_PKDEFS:
            if (record->event.pressed) {
                switch (getTargetOS()) {
                    case OS_MAC:
                        tap_mod_key(KC_LALT, KC_F12);
                        break;
                    case OS_NIX: {
                        uint8_t mods[] = {2, KC_LCTRL, KC_LSHIFT};
                        tap_mods_key(mods, KC_F10);
                    }
                    break;
                }
            }
            return false;
        case VSC_PKSYMS:
            if (record->event.pressed) {
                switch (getTargetOS()) {
                    case OS_MAC:
                    case OS_NIX:
                        tap_mod_key(KC_LSHIFT, KC_F12);
                        break;
                }
            }
            return false;
        case VSC_G2SYM:
            if (record->event.pressed) {
                switch (getTargetOS()) {
                    case OS_MAC: {
                        uint8_t mods[] = {2, KC_LSHIFT, KC_LGUI};
                        tap_mods_key(mods, KC_O);
                    }
                    break;
                    case OS_NIX: {
                        uint8_t mods[] = {2, KC_LCTRL, KC_LSHIFT};
                        tap_mods_key(mods, KC_O);
                    }
                    break;
                }
            }
            return false;
        case VSC_RENAME:
            if (record->event.pressed) {
                switch (getTargetOS()) {
                    case OS_MAC:
                    case OS_NIX:
                        tap_key(KC_F2);
                        break;
                }
            }
            return false;
        case VSC_PALETT:
            if (record->event.pressed) {
                switch (getTargetOS()) {
                    case OS_MAC:
                        tap_mod_key(KC_LGUI, KC_P);
                        break;
                    case OS_NIX:
                        tap_mod_key(KC_LCTRL, KC_P);
                        break;
                }
            }
            return false;
        case VSC_XPLORE:
            if (record->event.pressed) {
                switch (getTargetOS()) {
                    case OS_MAC: {
                        uint8_t mods[] = {2, KC_LGUI, KC_LSHIFT};
                        tap_mods_key(mods, KC_E);
                    }
                    break;
                    case OS_NIX: {
                        uint8_t mods[] = {2, KC_LCTRL, KC_LSHIFT};
                        tap_mods_key(mods, KC_E);
                    }
                    break;
                }
            }
            return false;
        case VSC_ED_1:
            if (record->event.pressed) {
                switch (getTargetOS()) {
                    case OS_MAC:
                        tap_mod_key(KC_LGUI, KC_1);
                        break;
                    case OS_NIX:
                        tap_mod_key(KC_LCTRL, KC_1);
                        break;
                }
            }
            return false;
    }
    return true;
}
