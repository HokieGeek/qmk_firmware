#include QMK_KEYBOARD_H
#include <print.h>
#include <mousekey.h>
#include "hokiegeek.h"

extern keymap_config_t keymap_config;

enum layers {
    _SCROLL = 0,
    _VOL,
    _MON,
    // _TODO,
    _LAST_
};

static bool encoderScrollVertical = true;
static bool encoderMonBrightness = true;

void encoder_actions (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (IS_LAYER_ON(_SCROLL)) {
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
[_SCROLL] = def_layout,
[_VOL] = def_layout,
[_MON] = def_layout,
// [_TODO] = def_layout,
};

void encoder_update(bool clockwise) {
    if (IS_LAYER_ON(_SCROLL)) {
        // dprintf("scroll\n");
        if (encoderScrollVertical) {
            if (clockwise) {
                register_code(KC_PGDN);
                unregister_code(KC_PGDN);
            } else {
                register_code(KC_PGUP);
                unregister_code(KC_PGUP);
            }
        } else {
            if (clockwise) {
                mousekey_on(KC_WH_D);
                mousekey_off(KC_WH_D);
            } else {
                mousekey_on(KC_WH_U);
                mousekey_off(KC_WH_U);
            }
        }
    } else if (IS_LAYER_ON(_VOL)) {
        // dprintf("volume\n");
        if (clockwise) {
            register_code(KC_VOLU);
            unregister_code(KC_VOLU);
        } else {
            register_code(KC_VOLD);
            unregister_code(KC_VOLD);
        }
    } else if (IS_LAYER_ON(_MON)) {
        // dprintf("monitor\n");
        if (encoderMonBrightness) {
            if (clockwise) {
                register_code(KC_FIND);
                unregister_code(KC_FIND);
            } else {
                register_code(KC_HELP);
                unregister_code(KC_HELP);
            }
        } else {
            if (clockwise) {
                register_code(KC_STOP);
                unregister_code(KC_STOP);
            } else {
                register_code(KC_UNDO);
                unregister_code(KC_UNDO);
            }
        }
        /*
    } else if (IS_LAYER_ON(_TODO)) {
        // dprintf("warmth\n");
        if (clockwise) {
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        } else {
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        }
        */
    }
}

void matrix_init_user(void) {
    debug_enable = true;

    layer_on(_SCROLL);

    userspace_matrix_init_user();
}

void matrix_scan_user(void) {
    userspace_matrix_scan_user();
}
