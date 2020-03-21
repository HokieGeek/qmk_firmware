#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _COLEMAK 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  LOWER,
  RAISE,
  ADJUST,
};

#define CTL_TAB LCTL_T(KC_TAB)
#define CTLTAB LCTL(KC_TAB)
#define CSTAB LCTL(LSFT(KC_TAB))
#define GUIBSPC LGUI_T(KC_BSPC)
#define ALTSPC LALT_T(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐       ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┤
     CTL_TAB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUES, KC_SFTENT,
  //├────────┼────────┴────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┴────────┼────────┤
     MO(_LOWER),                KC_MUTE, GUIBSPC, ALTSPC,          CTLTAB,  _______, _______,                   MO(_RAISE)
  //└────────┘                 └────────┴────────┴────────┘       └────────┴────────┴────────┘                 └────────┘
  ),

  [_COLEMAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐       ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,            KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┤
     CTLTAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,            KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_QUES, KC_SFTENT,
  //├────────┼────────┴────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┴────────┼────────┤
     MO(_LOWER),                KC_MUTE, GUIBSPC, ALTSPC,          CTLTAB,  _______, _______,                   MO(_RAISE)
  //└────────┘                 └────────┴────────┴────────┘       └────────┴────────┴────────┘                 └────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐       ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS, _______, _______, _______, _______, _______,         KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_MINS, KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,         _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______,
  //├────────┼────────┴────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┴────────┼────────┤
     _______,                   _______, _______, _______,         _______, _______, _______,                   _______
  //└────────┘                 └────────┴────────┴────────┘       └────────┴────────┴────────┘                 └────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐       ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRAVE,KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PLUS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_UNDS, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,           KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  //├────────┼────────┴────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┴────────┼────────┤
     _______,                   _______, _______, _______,         CSTAB,   _______, _______,                   _______
  //└────────┘                 └────────┴────────┴────────┘       └────────┴────────┴────────┘                 └────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐       ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, QWERTY,  COLEMAK, RESET,   _______, _______,         _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
  //├────────┼────────┴────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┴────────┼────────┤
     _______,                   _______, _______, _______,         _______, _______, _______,                   _______
  //└────────┘                 └────────┴────────┴────────┘       └────────┴────────┴────────┘                 └────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
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
  }
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}