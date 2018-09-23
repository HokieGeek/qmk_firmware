#include QMK_KEYBOARD_H
#include "hokiegeek.h"
#include <print.h>

extern keymap_config_t keymap_config;

#define _MOUSE 9
#define _CONTROL 10

enum custom_keycodes {
    CTLTAB = NEW_SAFE_RANGE,
    DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

enum {
    td_ctltab_mouse = TD_SAFE_RANGE
};

#undef __BASE_RCR1__
#define __BASE_RCR1__ KC_ENC

// | Lower| MACR | SWAP | Alt  | GUI  |Space |     |Space | TX_N | TX_P | SWAP |      |Raise |
#define _____BASE_BOTTOM_____  TT(_LOWER),  _______, SH_TT,   _______, KC_LGUI,  LALT_T(KC_SPC),        TD(td_ctltab_mouse),  KC_TMUX,  _______,  SH_TT,  DYN_MACRO_PLAY1,  TT(_RAISE)

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
 * | Lower|      | SWAP |      | GUI  |AltSpc|     |Space | TMUX |      | SWAP | MACR |Raise |
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
 * | Lower|      | SWAP |      | GUI  |AltSpc|     |Space | TMUX |      | SWAP | MACR |Raise |
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
 * |      |      |      |   é  |      |      |     |      |   ú  |   í  |   ó  |   [  |      |
 * |------+------+------+------+------+-------     -------+------+------+------+------+------|
 * |      |   á  |      |      |      |      |     | Home | PgDn | PgUp | End  |   {  |  |   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |  ñ   |      |      |      |   ¿  |Sysreq|
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |MSTOP |      |
 * `------------------------------------------     ------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_GRAVE,  LATIN_IEXC, _______, _______, _______, _______,      _______,  _______,  _______,  KC_UNDS,  KC_PLUS,       _______, \
  KC_CAPS,   _______,    _______, LATIN_E, _______, _______,      _______,  LATIN_U,  LATIN_I,  LATIN_O,  KC_LBRC,       _______, \
  _______,   LATIN_A,    _______, _______, KC_PSCR, _______,      KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_LCBR,       KC_PIPE, \
  _______,   _______,    _______, _______, _______, _______,      LATIN_N,  _______,  _______,  _______,  LATIN_IQS,     KC_SYSREQ, \
  _______,   _______,    _______, _______, _______, _______,      _______,  _______,  _______,  _______,  DYN_REC_STOP,  _______ \
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
 * |      |      |      |      |      |      |     |      | TX_L |      |      | MREC |      |
 * `------------------------------------------     ------------------------------------------'
 */
  // _______, _______,        _______, _______, _______, _______,      _______, _______,   _______,   _______, KC_RBRC, KC_DEL,
[_RAISE] = LAYOUT_wrapper( \
  _______, _______, _______, _______, _______, _______,      _______, _______,   _______,   KC_MINS, KC_EQL,  _______, \
  ______NUMBERS______, KC_RBRC, KC_DEL, \
  _______, _______, _______, _______, _______, _______,      KC_LEFT, KC_DOWN,   KC_UP,     KC_RGHT, KC_RCBR, KC_BSLS, \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,        KC_F7,   KC_F8,     KC_F9,     KC_F10,  KC_F11,  KC_F12, \
  _______, _______, _______, _______, _______, _______,      _______, TMUX_PREV, _______, _______, DYN_REC_START1, _______ \
),

/* Mouse
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
[_MOUSE] = LAYOUT( \
  _______,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
  _______,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
  _______,  _______, _______, _______, _______, _______,      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, \
  _______,  _______, _______, _______, _______, _______,      KC_BTN1, KC_BTN3, KC_BTN2, _______, _______, _______, \
  _______,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______  \
),


/* Control
 * ,------------------------------------------     ------------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+-------     +------+------+------+------+------+------|
 * |QMAKE |QWERTY|COLMAK|      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+-------     -------+------+------+------+------+------|
 * | Caps |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * `------------------------------------------     ------------------------------------------'
 */
[_CONTROL] = LAYOUT( \
  _______,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
  QMK_MAKE, QWERTY,  COLEMAK, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
  KC_CAPS,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
  _______,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
  _______,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______  \
),

};

#ifdef SWAP_HANDS_ENABLE
// Each half duplicates the other half
const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = SWAP_HANDS_ORTHO_5X12_SPLIT;
#endif

static encoder_options enc_opts;

void encoder_td_actions (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (IS_LAYER_ON(_CONTROL)) {
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
        if (IS_LAYER_ON(_CONTROL)) {
            enc_opts.backlightBrightness = !enc_opts.backlightBrightness;
        } else if (IS_LAYER_ON(_LOWER)) {
            enc_opts.monBrightness = !enc_opts.monBrightness;
        } else { // Default layers
            enc_opts.defaultVolume = !enc_opts.defaultVolume;
        }
        /*
    } else if (state->count > 2 && state->pressed) {
        send_string_with_delay_P(PSTR("make nyquist/rev2:encoder:dfu"SS_TAP(X_ENTER)), 10);
        reset_keyboard();
        */
    }

    reset_tap_dance (state);
}

void encoder_update(bool clockwise) {
    if (IS_LAYER_ON(_CONTROL)) {
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

static int td_ctltab_mouse_state = 0;
void td_ctltab_mouse_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_ctltab_mouse_state = process_td_state(state, user_data);

    switch (td_ctltab_mouse_state) {
        case SINGLE:      tap_ctltab(); break;
        case SINGLE_HOLD: layer_on(_MOUSE); break;
    }
}

void td_ctltab_mouse_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_ctltab_mouse_state) {
        case SINGLE_HOLD: layer_off(_MOUSE); break;
    }
    td_ctltab_mouse_state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    TD_ENCODER_ENTRY,
    TD_TMUX_ENTRY,
    [td_ctltab_mouse] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_ctltab_mouse_finished, td_ctltab_mouse_reset)
};

void matrix_init_user(void) {
    // debug_enable = true;
    enc_opts.scrollVertical = false;
    enc_opts.monBrightness = true;
    enc_opts.backlightBrightness = true;
    enc_opts.defaultVolume = true;

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
