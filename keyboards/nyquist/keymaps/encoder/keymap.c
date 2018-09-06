#include QMK_KEYBOARD_H
#include <print.h>
#include "hokiegeek.h"

extern keymap_config_t keymap_config;

enum layers {
    _VOL = 0,
    _SCROLL,
    _MON,
    _LAST_
};

static bool encoderScrollVertical = false;
static bool encoderMonBrightness = true;

void encoder_actions (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (IS_LAYER_ON(_VOL)) {
            key_tap(KC_MUTE);
        } else if (IS_LAYER_ON(_SCROLL)) {
            encoderScrollVertical = !encoderScrollVertical;
        } else if (IS_LAYER_ON(_MON)) {
            encoderMonBrightness = !encoderMonBrightness;
        }
    } else if (state->count == 2) {
        dprintf("NEXT: ");
        int i = 0;
        for (; i < _LAST_; i++) {
            if (IS_LAYER_ON(i)) {
                i = (i + 1) % _LAST_;
                layer_clear();
                layer_on(i);
                break;
            }
        }
        dprintf("%d, %d\n", i, (i + 1) % _LAST_);
        reset_tap_dance (state);
    } else if (state->count > 2 && state->pressed) {
        send_string_with_delay_P(PSTR("make nyquist/rev2:encoder:dfu"SS_TAP(X_ENTER)), 10);
        reset_keyboard();
    }
}

enum { encoder = 0 };
qk_tap_dance_action_t tap_dance_actions[] = { [encoder]  = ACTION_TAP_DANCE_FN(encoder_actions) };

#define def_layout LAYOUT( \
 _______, _______, _______, _______, _______, TD(encoder), _______, _______, _______, _______, _______, _______, \
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_VOL] = def_layout,
[_SCROLL] = def_layout,
[_MON] = def_layout,
};

void encoder_update(bool clockwise) {
    if (IS_LAYER_ON(_VOL)) {
        if (clockwise) {
            key_tap(KC_VOLU);
        } else {
            key_tap(KC_VOLD);
        }
    } else if (IS_LAYER_ON(_SCROLL)) {
        if (encoderScrollVertical) {
            if (clockwise) {
                mousekey_tap(KC_MS_WH_DOWN);
            } else {
                mousekey_tap(KC_MS_WH_UP);
            }
        } else {
            if (clockwise) {
                mousekey_tap(KC_MS_WH_RIGHT);
            } else {
                mousekey_tap(KC_MS_WH_LEFT);
            }
        }
    } else if (IS_LAYER_ON(_MON)) {
        if (encoderMonBrightness) {
            if (clockwise) {
                key_tap(KC_FIND);
            } else {
                key_tap(KC_HELP);
            }
        } else {
            if (clockwise) {
                key_tap(KC_UNDO);
            } else {
                key_tap(KC_STOP);
            }
        }
    }
}

void matrix_init_user(void) {
    debug_enable = true;

    layer_on(_VOL);

    userspace_matrix_init_user();
}

void matrix_scan_user(void) {
    userspace_matrix_scan_user();
}
