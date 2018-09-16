#include QMK_KEYBOARD_H
#include "hokiegeek.h"
#include <print.h>

extern keymap_config_t keymap_config;

#define _CONTROL 10

enum custom_keycodes {
    DYNAMIC_MACRO_RANGE = NEW_SAFE_RANGE,
};

#include "dynamic_macro.h"

static bool encoderScrollVertical = false;
static bool encoderMonBrightness = true;

void encoder_actions (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        dprintf("HERE\n");
        if (IS_LAYER_ON(_CONTROL)) {
            encoderMonBrightness = !encoderMonBrightness;
        } else if (IS_LAYER_ON(_LOWER)) {
            encoderScrollVertical = !encoderScrollVertical;
        } else if (IS_LAYER_ON(_QWERTY) || IS_LAYER_ON(_COLEMAK)) {
            key_tap(KC_MUTE);
        }
        /*
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
        */
    }
}

enum { encoder = 0 };
qk_tap_dance_action_t tap_dance_actions[] = { [encoder]  = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, encoder_actions, NULL, 400) };

#undef __BASE_RCR1__
#define __BASE_RCR1__ TD(encoder)

// | Lower| MACR | SWAP | Alt  | GUI  |Space |     |Space | TX_N | TX_P | SWAP | Mute |Raise |
#define _____BASE_BOTTOM_____  TT(_LOWER),  DYN_MACRO_PLAY1, SH_TT,   KC_LALT, KC_LGUI,  LT(_CONTROL, KC_SPC),        KC_SPC,  TMUX_NEXT,  TMUX_PREV,  SH_TT,   KC_MUTE,  TT(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,------------------------------------------     ------------------------------------------.
 * | GEsc |   1  |   2  |   3  |   4  |   5  |     |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |     |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------     -------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |     |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |     |   N  |   M  |   ,  |   .  |   /  |ShEnt |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * | Lower| MACR | SWAP | Alt  | GUI  |Space |     |Space | TX_N | TX_P | SWAP | Mute |Raise |
 * `------------------------------------------     ------------------------------------------'
 */
[_QWERTY] = LAYOUT_wrapper( \
  __BASE_LCR1__, ______NUMBERS______, __BASE_RCR1__, \
  __BASE_LCR2__, _____QWERTY_R1_____, __BASE_RCR2__, \
  __BASE_LCR3__, _____QWERTY_R2_____, \
  __BASE_LCR4__, _____QWERTY_R3_____, __BASE_RCR4__, \
  _____BASE_BOTTOM_____ \
),

/* Colemak
 * ,------------------------------------------     ------------------------------------------.
 * | GEsc |   1  |   2  |   3  |   4  |   5  |     |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |     |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------     -------+------+------+------+------+------|
 * | Ctrl |   A  |   R  |   S  |   T  |   D  |     |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |     |   K  |   M  |   ,  |   .  |   /  |ShEnt |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * | Lower| MACR | SWAP | Alt  | GUI  |Space |     |Space | TX_N | TX_P | SWAP | Mute |Raise |
 * `------------------------------------------     ------------------------------------------'
 */
[_COLEMAK] = LAYOUT_wrapper( \
  __BASE_LCR1__, ______NUMBERS______,  __BASE_RCR1__, \
  __BASE_LCR2__, _____COLEMAK_R1_____, __BASE_RCR2__, \
  __BASE_LCR3__, _____COLEMAK_R2_____, \
  __BASE_LCR4__, _____COLEMAK_R3_____, __BASE_RCR4__, \
  _____BASE_BOTTOM_____ \
),

/* Lower
 * ,------------------------------------------     ------------------------------------------.
 * |   `  |   ¡  |      |      |      |      |     |      |      |      |   _  |   +  |      |
 * |------+------+------+------+------+-------     +------+------+------+------+------+------|
 * | Caps |      |      |   é  |      |      |     |      |   ú  |   í  |   ó  |   [  |      |
 * |------+------+------+------+------+-------     -------+------+------+------+------+------|
 * |      |   á  |      |      |      |      |     | Home | PgDn | PgUp | End  |   {  |  |   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |  ñ   |      |      |      |   ¿  |Sysreq|
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * |      |MSTOP |      |      |      |      |     |      |      |      |      | Vol- |      |
 * `------------------------------------------     ------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_GRAVE,  LATIN_IEXC,    _______, _______, _______, _______,      _______,  _______,  _______,  KC_UNDS,  KC_PLUS,   _______, \
  KC_CAPS,   _______,       _______, LATIN_E, _______, _______,      _______,  LATIN_U,  LATIN_I,  LATIN_O,  KC_LBRC,   _______, \
  _______,   LATIN_A,       _______, KC_STOP, KC_PSCR, KC_FIND,      KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_LCBR,   KC_PIPE, \
  _______,   _______,       _______, KC_UNDO, _______, KC_HELP,      LATIN_N,  _______,  _______,  _______,  LATIN_IQS, KC_SYSREQ, \
  _______,   DYN_REC_STOP,  _______, _______, _______, _______,      _______,  _______,  _______,  _______,  KC_VOLD,   _______ \
),

/* Raise
 * ,------------------------------------------     ------------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |   -  |   =  |      |
 * |------+------+------+------+------+-------     +------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |   ]  | Del  |
 * |------+------+------+------+------+-------     -------+------+------+------+------+------|
 * |      |      |      |      |      |      |     | Left | Down |  Up  |Right |   }  |  \   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |     |  F7  |  F8  |  F9  |  F10 | F11  | F12  |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * |      | MREC |      |      |      |      |     |      | TX_L |TX_PK |      | Vol+ |      |
 * `------------------------------------------     ------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  _______, _______,        _______, _______, _______, _______,      _______, _______,   _______,   KC_MINS, KC_EQL,  _______, \
  _______, _______,        _______, _______, _______, _______,      _______, _______,   _______,   _______, KC_RBRC, KC_DEL, \
  _______, _______,        _______, _______, _______, _______,      KC_LEFT, KC_DOWN,   KC_UP,     KC_RGHT, KC_RCBR, KC_BSLS, \
  KC_F1,   KC_F2,          KC_F3,   KC_F4,   KC_F5,   KC_F6,        KC_F7,   KC_F8,     KC_F9,     KC_F10,  KC_F11,  KC_F12, \
  _______, DYN_REC_START1, _______, _______, _______, _______,      _______, TMUX_LAST, TMUX_PEEK, _______, KC_VOLU, _______ \
),

/* Control
 * ,------------------------------------------     ------------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+-------     +------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+-------     -------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |QMAKE |QWERTY|COLMAK|      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * `------------------------------------------     ------------------------------------------'
 */
[_CONTROL] = LAYOUT( \
  _______,  RGB_TOG, _______, KC_WH_L, KC_WH_R, KC_WH_U,      _______, _______, _______, _______, _______, _______, \
  _______,  BL_TOGG, _______, _______, KC_MS_U, KC_WH_D,      _______, _______, _______, _______, _______, _______, \
  _______,  BL_STEP, _______, KC_MS_L, KC_MS_D, KC_MS_R,      _______, _______, _______, _______, _______, _______, \
  QMK_MAKE, QWERTY,  COLEMAK, KC_BTN3, KC_BTN2, KC_BTN1,      _______, _______, _______, _______, _______, _______, \
  _______,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______  \
),

};

// Each half duplicates the other half
const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = SWAP_HANDS_ORTHO_5X12_SPLIT;

void encoder_update(bool clockwise) {
    if (IS_LAYER_ON(_CONTROL)) {
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
    } else if (IS_LAYER_ON(_LOWER)) {
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
    } else if (IS_LAYER_ON(_QWERTY) || IS_LAYER_ON(_COLEMAK)) {
        if (clockwise) {
            key_tap(KC_VOLU);
        } else {
            key_tap(KC_VOLD);
        }
    }
}

void matrix_init_user(void) {
    // debug_enable = true;

    layer_on(_QWERTY);

    userspace_matrix_init_user();
}

void matrix_scan_user(void) {
    userspace_matrix_scan_user();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }

    return userspace_process_record_user(keycode, record);
}
