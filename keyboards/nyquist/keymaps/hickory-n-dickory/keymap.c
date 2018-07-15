#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Layer names
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,

    TMUX_NEXT,
    TMUX_PREV,
    DYNAMIC_MACRO_RANGE,
};

#include "dynamic_macro.h"

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | GEsc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |Enter |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | SWAP | MACR | Alt  | GUI  |Lower |Space |Space |Raise | TX_N | TX_P | Mute | SWAP |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_GESC,  KC_1,            KC_2,    KC_3,    KC_4,       KC_5,    KC_6,    KC_7,       KC_8,       KC_9,       KC_0,     KC_BSPC, \
  KC_TAB,   KC_Q,            KC_W,    KC_E,    KC_R,       KC_T,    KC_Y,    KC_U,       KC_I,       KC_O,       KC_P,     KC_ENT, \
  KC_LCTL,  KC_A,            KC_S,    KC_D,    KC_F,       KC_G,    KC_H,    KC_J,       KC_K,       KC_L,       KC_SCLN,  KC_QUOT, \
  KC_LSFT,  KC_Z,            KC_X,    KC_C,    KC_V,       KC_B,    KC_N,    KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,  KC_RSFT, \
  SH_TT,    DYN_MACRO_PLAY1, KC_LALT, KC_LGUI, TT(_LOWER), KC_SPC,  KC_SPC,  TT(_RAISE), TMUX_NEXT,  TMUX_PREV,  KC_MUTE,  SH_TT \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |      |      |      |      |      |      |      |      |      |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Bksp |      |      |      |      |      |      |   _  |   +  |   {  |   }  |Enter |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Caps |      |      |      |      |      | Home | PgDn | PgUp | End  |      |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Enter |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |MSTOP |      |      |      |      |      |      |      |      | Vol- |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_TILD, _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, \
  KC_BSPC, _______,       _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______, \
  KC_CAPS, _______,       _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, KC_PIPE, \
  _______, _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, DYN_REC_STOP,  _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, SH_TG \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | F11  | F12  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |      |      |      |      |      |      |   -  |   =  |   [  |   ]  |Enter |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |      |      |      |      |      | Left | Down |  Up  |Right |      |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | MREC |      |      |      |      |      |      |      |      | Vol+ |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_F1,   KC_F2,          KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  KC_GRV,  _______,        _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______, \
  _______, _______,        _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_BSLS, \
  _______, _______,        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, DYN_REC_START1, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU, SH_TG \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Reset |Debug |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, RESET,   DEBUG,   _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)


};

// Each half duplicates the other half
const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
  {{5, 5}, {4, 5}, {3, 5}, {2, 5}, {1, 5}, {0, 5}},
  {{5, 6}, {4, 6}, {3, 6}, {2, 6}, {1, 6}, {0, 6}},
  {{5, 7}, {4, 7}, {3, 7}, {2, 7}, {1, 7}, {0, 7}},
  {{5, 8}, {4, 8}, {3, 8}, {2, 8}, {1, 8}, {0, 8}},
  {{5, 9}, {4, 9}, {3, 9}, {2, 9}, {1, 9}, {0, 9}},

  {{5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
  {{5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
  {{5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
  {{5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3}, {0, 3}},
  {{5, 4}, {4, 4}, {3, 4}, {2, 4}, {1, 4}, {0, 4}},
};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL<<_QWERTY);
            }
            return false;
            break;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            break;

        // MACROS
        case TMUX_NEXT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("a")"n");
            }
            return false;
            break;

        case TMUX_PREV:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("a")"p");
            }
            return false;
            break;
    }
    return true;
}
