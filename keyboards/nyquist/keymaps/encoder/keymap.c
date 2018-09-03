#include QMK_KEYBOARD_H
#include <print.h>
#include "hokiegeek.h"

extern keymap_config_t keymap_config;

enum layers {
    _SCROLL = 0,
    _VOL,
    _LAST_
};

enum custom_keycodes {
    NEXT = SAFE_RANGE,
    PREV,
};


void encoder_actions (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        dprintf("NEXT: ");
        if (IS_LAYER_ON(_SCROLL)) {
            dprintf("VOL\n");
            layer_clear();
            layer_on(_VOL);
        } else if (IS_LAYER_ON(_VOL)) {
            dprintf("SCROLL\n");
            layer_clear();
            layer_on(_SCROLL);
        }
        reset_tap_dance (state);
    } else if (state->count == 2) {
        dprintf("PREV: ");
        if (IS_LAYER_ON(_SCROLL)) {
            dprintf("VOL\n");
            layer_clear();
            layer_on(_VOL);
        } else if (IS_LAYER_ON(_VOL)) {
            dprintf("SCROLL\n");
            layer_clear();
            layer_on(_SCROLL);
        }
        reset_tap_dance (state);
    } else if (state->count > 2 && state->pressed) {
        dprint("resetting");
        reset_keyboard();
    }
}

enum { foo = 0 };
qk_tap_dance_action_t tap_dance_actions[] = { [foo]  = ACTION_TAP_DANCE_FN(encoder_actions) };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_SCROLL] = LAYOUT( \
 _______, _______, _______, _______, _______, TD(foo), _______, _______, _______, _______, _______, _______, \
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_VOL] = LAYOUT( \
 _______, _______, _______, _______, _______, TD(foo), _______, _______, _______, _______, _______, _______, \
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

};

void encoder_update(bool clockwise) {
    dprintf("%s\n", clockwise ? "CW" : "CCW");
    // dprintf("%x\n", layer_state);

    if (IS_LAYER_ON(_SCROLL)) {
        dprintf("scroll\n");
        if (clockwise) {
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        } else {
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        }
    } else if (IS_LAYER_ON(_VOL)) {
        dprintf("volume\n");
        if (clockwise) {
            register_code(KC_VOLU);
            unregister_code(KC_VOLU);
        } else {
            register_code(KC_VOLD);
            unregister_code(KC_VOLD);
        }
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
