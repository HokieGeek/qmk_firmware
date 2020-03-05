#include "vscode.h"

#include "os.h"
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
        case VSC_PROBS:
            if (record->event.pressed) {
                switch (getTargetOS()) {
                    case OS_MAC:
                        tap_code16(LGUI(LSFT(KC_M)));
                        break;
                    case OS_NIX:
                        tap_code16(LCTL(LSFT(KC_M)));
                        break;
                }
            }
            return false;
        case VSC_SCM:
            if (record->event.pressed) {
                switch (getTargetOS()) {
                    case OS_MAC:
                        tap_code16(LCTL(LSFT(KC_G)));
                        break;
                    case OS_NIX:
                        tap_code16(LCTL(LSFT(KC_G)));
                        tap_code(KC_G);
                        break;
                }
            }
            return false;
        case VSC_FIND:
            if (record->event.pressed) {
                switch (getTargetOS()) {
                    case OS_MAC:
                        tap_code16(LGUI(LSFT(KC_F)));
                        break;
                    case OS_NIX:
                        tap_code16(LCTL(LSFT(KC_F)));
                        break;
                }
            }
            return false;
        case VSC_TERM:
            if (record->event.pressed) {
                switch (getTargetOS()) {
                    case OS_NIX:
                    case OS_MAC:
                        tap_code16(LCTL(KC_GRAVE));
                        break;
                }
            }
            return false;
        case VSC_PKDEFS:
            if (record->event.pressed) {
                switch (getTargetOS()) {
                    case OS_MAC:
                        tap_code16(LALT(KC_F12));
                        break;
                    case OS_NIX:
                        tap_code16(LCTL(LSFT(KC_F10)));
                        break;
                }
            }
            return false;
        case VSC_PKSYMS:
            if (record->event.pressed) {
                switch (getTargetOS()) {
                    case OS_MAC:
                    case OS_NIX:
                        tap_code16(LSFT(KC_F12));
                        break;
                }
            }
            return false;
        case VSC_G2SYM:
            if (record->event.pressed) {
                switch (getTargetOS()) {
                    case OS_MAC:
                        tap_code16(LSFT(LGUI(KC_O)));
                        break;
                    case OS_NIX:
                        tap_code16(LSFT(LCTL(KC_O)));
                        break;
                }
            }
            return false;
        case VSC_RENAME:
            if (record->event.pressed) {
                switch (getTargetOS()) {
                    case OS_MAC:
                    case OS_NIX:
                        tap_code(KC_F2);
                        break;
                }
            }
            return false;
        case VSC_PALETT:
            if (record->event.pressed) {
                switch (getTargetOS()) {
                    case OS_MAC:
                        tap_code16(LGUI(KC_P));
                        break;
                    case OS_NIX:
                        tap_code16(LCTL(KC_P));
                        break;
                }
            }
            return false;
        case VSC_XPLORE:
            if (record->event.pressed) {
                switch (getTargetOS()) {
                    case OS_MAC:
                        tap_code16(LSFT(LGUI(KC_E)));
                        break;
                    case OS_NIX:
                        tap_code16(LSFT(LCTL(KC_E)));
                        break;
                }
            }
            return false;
        case VSC_ED_1:
            if (record->event.pressed) {
                switch (getTargetOS()) {
                    case OS_MAC:
                        tap_code16(LGUI(KC_1));
                        break;
                    case OS_NIX:
                        tap_code16(LCTL(KC_1));
                        break;
                }
            }
            return false;
        case VSC_TGL_GTST:
            if (record->event.pressed) {
                switch (getTargetOS()) {
                    case OS_NIX:
                    case OS_MAC:
                        tap_code16(HYPR(KC_G));
                        tap_code(KC_T);
                        break;
                }
            }
            return false;
    }
    return true;
}