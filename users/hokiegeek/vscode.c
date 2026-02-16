#include "vscode.h"

#include "os.h"
#include "hg_keycodes.h"

void vscode_os_tap_code(keyrecord_t *record, uint16_t mac_kc, uint16_t nix_kc) {
    if (record->event.pressed) {
        switch (getTargetOS()) {
            case OS_MAC: tap_code16(mac_kc); break;
            case OS_NIX: tap_code16(nix_kc); break;
        }
    }
}

bool vscode_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case VSC_PROBS:
            vscode_os_tap_code(record, LGUI(LSFT(KC_M)), LCTL(LSFT(KC_M)));
            return false;
        case VSC_FIND:
            vscode_os_tap_code(record, LGUI(LSFT(KC_F)), LCTL(LSFT(KC_F)));
            return false;
        case VSC_TERM:
            vscode_os_tap_code(record, LCTL(KC_GRAVE), LCTL(KC_GRAVE));
            return false;
        case VSC_PKDEFS:
            vscode_os_tap_code(record, LALT(KC_F12), LCTL(LSFT(KC_F10)));
            return false;
        case VSC_PKSYMS:
            vscode_os_tap_code(record, LSFT(KC_F12), LSFT(KC_F12));
            return false;
        case VSC_G2SYM:
            vscode_os_tap_code(record, LSFT(LGUI(KC_O)), LSFT(LCTL(KC_O)));
            return false;
        case VSC_RENAME:
            vscode_os_tap_code(record, KC_F2, KC_F2);
            return false;
        case VSC_PALETT:
            vscode_os_tap_code(record, LGUI(KC_P), LCTL(KC_P));
            return false;
        case VSC_XPLORE:
            vscode_os_tap_code(record, LSFT(LGUI(KC_E)), LSFT(LCTL(KC_E)));
            return false;
        case VSC_ED_1:
            vscode_os_tap_code(record, LGUI(KC_1), LCTL(KC_1));
            return false;
        case VSC_SCM:
            if (record->event.pressed) {
                tap_code16(LCTL(LSFT(KC_G))); // Same for MAC and NIX
                if (getTargetOS() == OS_NIX) {
                    tap_code(KC_G);
                }
            }
            return false;
        case VSC_TGL_GTST:
            if (record->event.pressed) {
                // Same for MAC and NIX
                tap_code16(HYPR(KC_G));
                tap_code(KC_T);
            }
            return false;
    }
    return true;
}
