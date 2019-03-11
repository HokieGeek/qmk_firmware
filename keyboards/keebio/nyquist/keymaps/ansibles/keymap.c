#include QMK_KEYBOARD_H
#include "hokiegeek.h"
#include <print.h>

extern keymap_config_t keymap_config;

enum {
    td_ctltab_extras = TD_SAFE_RANGE
};

enum custom_keycodes {
    CTLTAB = NEW_SAFE_RANGE
};

#undef __BASE_RCR1__
#define __BASE_RCR1__ KC_ENC
// #undef __BASE_LCR1__
// #define __BASE_LCR1__ KC_PWR

// | Lower|      |      |      | GUI  |AltSpc|     |CtlTb | TMUX |      |      | MACR |Raise |
#define _____BASE_BOTTOM_____  TT(_LOWER),  _______, _______,   _______, KC_LGUI,  LALT_T(KC_SPC), TD(td_ctltab_extras),  KC_TMUX, _______,  _______,  KC_SKDM1,  TT(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,------------------------------------------     ------------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |     |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------     -------+------+------+------+------+------|
 * |Ctl/Tb|   A  |   S  |   D  |   F  |   G  |     |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |SftLat|   Z  |   X  |   C  |   V  |   B  |     |   N  |   M  |   ,  |   .  |   /  |ShEnt |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * | Lower|      |      |      | GUI  |AltSpc|     |CtlTb | TMUX |      |      | MACR |Raise |
 * `------------------------------------------     ------------------------------------------'
 */
[_QWERTY] = LAYOUT_wrapper( \
  __BASE_LCR1__,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, __BASE_RCR1__, \
  __BASE_LCR2__, _____QWERTY_R1_____, __BASE_RCR2__, \
  __BASE_LCR3__, _____QWERTY_R2_____, \
  __BASE_LCR4__, _____QWERTY_R3_____, __BASE_RCR4__, \
  _____BASE_BOTTOM_____ \
),

/* Colemak
 * ,------------------------------------------     ------------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * | Esc  |   Q  |   W  |   F  |   P  |   G  |     |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------     -------+------+------+------+------+------|
 * |Ctl/Tb|   A  |   R  |   S  |   T  |   D  |     |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |SftLat|   Z  |   X  |   C  |   V  |   B  |     |   K  |   M  |   ,  |   .  |   /  |ShEnt |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * | Lower|      |      |      | GUI  |AltSpc|     |CtlTb | TMUX |      |      | MACR |Raise |
 * `------------------------------------------     ------------------------------------------'
 */
[_COLEMAK] = LAYOUT_wrapper( \
  __BASE_LCR1__,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, __BASE_RCR1__, \
  __BASE_LCR2__, _____COLEMAK_R1_____, __BASE_RCR2__, \
  __BASE_LCR3__, _____COLEMAK_R2_____, \
  __BASE_LCR4__, _____COLEMAK_R3_____, __BASE_RCR4__, \
  _____BASE_BOTTOM_____ \
),

/* Lower
 * ,------------------------------------------     ------------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+-------     +------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |     |   ^  |   &  |   *  |   (  |   )  |  =   |
 * |------+------+------+------+------+-------     -------+------+------+------+------+------|
 * |      |      |      |      |AltPrt|      |     | Home | PgDn | PgUp | End  |   -  |  |   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |  {   |  }   |  [   |  ]   |      |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * `------------------------------------------     ------------------------------------------'
 */
[_LOWER] = LAYOUT_wrapper( \
  _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,  _______, \
  KC_TILD, ______SYMBOLS______,       KC_EQL, \
  _______, _______, _______, _______, ALTPSCR, _______,      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_MINS, KC_PIPE, \
  _______, _______, _______, _______, _______, _______,      _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______, \
  _______, _______, _______, _______, _______, _______,      _______, _______, KC_VOLD, _______, _______, _______ \
),

/* Raise
 * ,------------------------------------------     ------------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+-------     +------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |     |   6  |   7  |   8  |   9  |   0  |   +  |
 * |------+------+------+------+------+-------     -------+------+------+------+------+------|
 * |      |      |      |      |Print |      |     | Left | Down |  Up  |Right |   _  |  \   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |     |  F7  |  F8  |  F9  |  F10 | F11  | F12  |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      | TX_P |      |      |      |      |
 * `------------------------------------------     ------------------------------------------'
 */
[_RAISE] = LAYOUT_wrapper( \
  _______,  _______, _______, _______, _______, _______,      _______, _______,   _______,  _______, _______, _______, \
  KC_GRAVE, ______NUMBERS______, KC_PLUS,
  _______,  _______, _______, _______, KC_PSCR, _______,      KC_LEFT, KC_DOWN,   KC_UP,    KC_RGHT, KC_UNDS, KC_BSLS, \
  KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,        KC_F7,   KC_F8,     KC_F9,    KC_F10,  KC_F11,  KC_F12, \
  _______,  _______, _______, _______, _______, _______,      CSTAB,   TMUX_PREV, KC_VOLU,  _______, _______, _______ \
),

/* Extras
 * ,------------------------------------------     ------------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+-------     +------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+-------     -------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * `------------------------------------------     ------------------------------------------'
 */
[_EXTRAS] = LAYOUT( \
  _______,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
  _______,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
  _______,  _______, _______, _______, _______, _______,      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, \
  _______,  _______, _______, _______, _______, _______,      KC_BTN1, KC_BTN3, KC_BTN2, _______, _______, _______, \
  _______,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______  \
),


/* Adjust
 * ,------------------------------------------     ------------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+-------     +------+------+------+------+------+------|
 * |      |QWERTY|COLMAK|      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+-------     -------+------+------+------+------+------|
 * | Caps |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |QMAKE |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * `------------------------------------------     ------------------------------------------'
 */
[_ADJUST] = LAYOUT( \
  _______,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
  _______,  QWERTY,  COLEMAK, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
  KC_CAPS,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
  QMK_MAKE, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
  _______,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______  \
),

};

#ifdef SWAP_HANDS_ENABLE
// Each half duplicates the other half
const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = SWAP_HANDS_ORTHO_5X12_SPLIT;
#endif

#ifdef ENCODER_ENABLE
void encoder_td_actions (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (IS_LAYER_ON(_ADJUST)) {
            if (enc_opts.backlightBrightness) {
                backlight_toggle();
            } else {
                rgblight_toggle();
            }
        } else if (IS_LAYER_ON(_LOWER)) {
            // TODO
        } else { // Default layers
            if (enc_opts.defaultVolume) {
                key_tap(KC_MUTE);
            } else {
                enc_opts.scrollVertical = !enc_opts.scrollVertical;
            }
        }
    } else if (state->count == 2) {
        if (IS_LAYER_ON(_ADJUST)) {
            enc_opts.backlightBrightness = !enc_opts.backlightBrightness;
        } else if (IS_LAYER_ON(_LOWER)) {
            enc_opts.monBrightness = !enc_opts.monBrightness;
        } else { // Default layers
            enc_opts.defaultVolume = !enc_opts.defaultVolume;
        }
    }

    reset_tap_dance (state);
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (IS_LAYER_ON(_ADJUST)) {
            if (enc_opts.backlightBrightness) {
                if (clockwise) {
                    backlight_increase();
                } else {
                    backlight_decrease();
                }
            }
        } else if (IS_LAYER_ON(_LOWER)) {
            if (enc_opts.monBrightness) {
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
        } else { // Default layers
            if (enc_opts.defaultVolume) {
                if (clockwise) {
                    key_tap(KC_VOLU);
                } else {
                    key_tap(KC_VOLD);
                }
            } else {
                if (enc_opts.scrollVertical) {
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
            }
        }
    }
}

void extras_layer_on_hold(td_stage stage) {
    switch (stage) {
        case TD_FINISHED: layer_on(_EXTRAS); break;
        case TD_RESET: layer_off(_EXTRAS); break;
        default: break;
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    TD_ENCODER_ENTRY,
    TD_TMUX_ENTRY,
    TD_SHIFT_LATIN,
    TD_SKDM1_ENTRY,
    [td_ctltab_extras] = ACTION_TAP_DANCE_TAP_HOLD(tap_ctltab_td, extras_layer_on_hold)
};
#endif

void matrix_init_user(void) {
    // debug_enable = true;

    layer_on(_COLEMAK);

    userspace_matrix_init_user();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return userspace_process_record_user(keycode, record);
}
