#include "latin.h"
#include "taps.h"
#include "os.h"

bool useLatinChar = false;

// static int td_latin_state = 0;

#ifdef TAP_DANCE_ENABLE
#include "td_extras.h"

void td_latin_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state td_latin_state = process_td_state(state, user_data);
    // tap_key(KC_Q);

    switch (td_latin_state) {
        case SINGLE:      useLatinChar = true; break;
        case SINGLE_HOLD: register_code(KC_LSHIFT); break;
        default: break;
    }
}

void td_latin_reset(qk_tap_dance_state_t *state, void *user_data) {
    // if (td_latin_state == SINGLE_HOLD) {
        unregister_code(KC_LSHIFT);
    // }
    // td_latin_state = 0;
}
#endif

bool latin_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LATIN_E:
        case LATIN_A:
        case LATIN_I:
        case LATIN_O:
        case LATIN_U:
        case LATIN_N:
        case LATIN_IEXC:
        case LATIN_IQS:
            if (record->event.pressed) {
                if (useLatinChar) {
                    switch (keycode) {
                        // case LATIN_E:       SEND_LATIN(LATIN_E_STRING); break;
                        case LATIN_E:
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
                        case LATIN_A:
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
                        case LATIN_I:
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
                        case LATIN_O:
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
                        case LATIN_U:
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
                        case LATIN_N:
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
                        case LATIN_IEXC:
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
                        case LATIN_IQS:
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
                    }
                } else {
                    switch (keycode) {
                        case LATIN_E:       tap_key(LATIN_E_PRIMARY_KC); break;
                        case LATIN_A:       tap_key(LATIN_A_PRIMARY_KC); break;
                        case LATIN_I:       tap_key(LATIN_I_PRIMARY_KC); break;
                        case LATIN_O:       tap_key(LATIN_O_PRIMARY_KC); break;
                        case LATIN_U:       tap_key(LATIN_U_PRIMARY_KC); break;
                        case LATIN_N:       tap_key(LATIN_N_PRIMARY_KC); break;
                        case LATIN_IEXC:    tap_key(LATIN_IEXC_PRIMARY_KC); break;
                        case LATIN_IQS:     tap_key(LATIN_IQS_PRIMARY_KC); break;
                    }
                }
            }
            useLatinChar = false;
            return false;
            break;
    }

    if (keycode < QK_LAYER_TAP_TOGGLE || keycode > QK_LAYER_TAP_TOGGLE_MAX) {
        useLatinChar = false;
    }

    return true;
}
