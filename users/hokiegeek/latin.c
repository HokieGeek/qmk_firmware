#include "latin.h"
#include "taps.h"
#include "os.h"
#include "keycodes.h"

bool useLatinChar = false;

#ifdef TAP_DANCE_ENABLE
#include "td_extras.h"

void td_latin_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state td_latin_state = process_td_state(state, user_data);

    switch (td_latin_state) {
        case SINGLE:      useLatinChar = true; break;
        case SINGLE_HOLD: register_code(KC_LSHIFT); break;
        default: break;
    }
}

void td_latin_reset(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code(KC_LSHIFT);
}
#endif

bool latin_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!useLatinChar) {
        return true;
    }
    useLatinChar = false;

    if (record->event.pressed) {
        switch (keycode) {
            case KC_LATIN:
                useLatinChar = true;
                break;
            case KC_E:
                switch (getTargetOS()) {
                    case OS_MAC:
                        SEND_LATIN_MAC(SS_LALT("e")"e");
                        break;
                    case OS_NIX:
                        SEND_LATIN_NIX(SS_TAP(X_E)SS_TAP(X_9));
                        break;
                    case OS_WIN:
                        break;
                }
                break;
            case KC_A:
                switch (getTargetOS()) {
                    case OS_MAC:
                        SEND_LATIN_MAC(SS_LALT("e")"a");
                        break;
                    case OS_NIX:
                        SEND_LATIN_NIX(SS_TAP(X_E)SS_TAP(X_1));
                        break;
                    case OS_WIN:
                        break;
                }
                break;
            case KC_I:
                switch (getTargetOS()) {
                    case OS_MAC:
                        SEND_LATIN_MAC(SS_LALT("e")"i");
                        break;
                    case OS_NIX:
                        SEND_LATIN_NIX(SS_TAP(X_E)SS_TAP(X_D));
                        break;
                    case OS_WIN:
                        break;
                }
                break;
            case KC_O:
                switch (getTargetOS()) {
                    case OS_MAC:
                        SEND_LATIN_MAC(SS_LALT("e")"o");
                        break;
                    case OS_NIX:
                        SEND_LATIN_NIX(SS_TAP(X_F)SS_TAP(X_3));
                        break;
                    case OS_WIN:
                        break;
                }
                break;
            case KC_U:
                switch (getTargetOS()) {
                    case OS_MAC:
                        SEND_LATIN_MAC(SS_LALT("e")"u");
                        break;
                    case OS_NIX:
                        SEND_LATIN_NIX(SS_TAP(X_F)SS_TAP(X_A));
                        break;
                    case OS_WIN:
                        break;
                }
                break;
            case KC_N:
                switch (getTargetOS()) {
                    case OS_MAC:
                        SEND_LATIN_MAC(SS_LALT("n")"n");
                        break;
                    case OS_NIX:
                        SEND_LATIN_NIX(SS_TAP(X_F)SS_TAP(X_1));
                        break;
                    case OS_WIN:
                        break;
                }
                break;
            case KC_Q:
            case KC_1:
            case KC_EXCLAIM:
                switch (getTargetOS()) {
                    case OS_MAC:
                        SEND_LATIN_MAC(SS_LALT("1"));
                        break;
                    case OS_NIX:
                        SEND_LATIN_NIX(SS_TAP(X_A)SS_TAP(X_1));
                        break;
                    case OS_WIN:
                        break;
                }
                break;
            case KC_SLASH:
            case KC_QUESTION:
                switch (getTargetOS()) {
                    case OS_MAC:
                        SEND_LATIN_MAC(SS_LALT("?"));
                        break;
                    case OS_NIX:
                        SEND_LATIN_NIX(SS_TAP(X_B)SS_TAP(X_F));
                        break;
                    case OS_WIN:
                        break;
                }
                break;
            default:
                return true;
        }
    }

    /*
    if (keycode < QK_LAYER_TAP_TOGGLE || keycode > QK_LAYER_TAP_TOGGLE_MAX) {
        useLatinChar = false;
    }
    */

    return false;
}
