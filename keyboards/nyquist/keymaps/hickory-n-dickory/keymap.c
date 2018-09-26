#include QMK_KEYBOARD_H
#include "hokiegeek.h"

extern keymap_config_t keymap_config;

#define _SHORTS 5

enum custom_keycodes {
    SLACK_GIPHY = NEW_SAFE_RANGE,
    SLACK_SHRUG,
    SLACK_REACT,

    DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

#undef __BASE_RCR1__
#ifdef TAP_DANCE_ENABLE
enum {
    td_last = td_tmux,
    td_mute_notif
};
#define __BASE_RCR1__ TD(td_mute_notif)
#else
#define __BASE_RCR1__ KC_MUTE
#endif

#define _____BASE_BOTTOM_____  TT(_LOWER),  DYN_MACRO_PLAY1, _______,   _______, KC_LGUI,  LALT_T(KC_SPC),       LT(_SHORTS, KC_SPC),  KC_TMUX,  _______,  _______,   _______,  TT(_RAISE)

#define SEND_SLACK_SLASH(str) SEND_DELAYED(50, SS_TAP(X_SLASH) str SS_TAP(X_TAB))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,------------------------------------------     ------------------------------------------.
 * | GEsc |   1  |   2  |   3  |   4  |   5  |     |   6  |   7  |   8  |   9  |   0  | Mute |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |     |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------     -------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |     |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |     |   N  |   M  |   ,  |   .  |   /  |ShEnt |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * | Lower| MACR | SWAP | Alt  | GUI  |Space |     |Space | TMUX |      | SWAP |      |Raise |
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
 * | GEsc |   1  |   2  |   3  |   4  |   5  |     |   6  |   7  |   8  |   9  |   0  | Mute |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |     |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------     -------+------+------+------+------+------|
 * | Ctrl |   A  |   R  |   S  |   T  |   D  |     |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |     |   K  |   M  |   ,  |   .  |   /  |ShEnt |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * | Lower| MACR | SWAP | Alt  | GUI  |Space |     |Space | TMUX |      | SWAP |      |Raise |
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
 * |   `  |   ¡  |      |      |      |      |     |      |      |      |   _  |   +  | Vol- |
 * |------+------+------+------+------+-------     +------+------+------+------+------+------|
 * | Caps |QWERTY|COLMAK|   é  |      |      |     |      |   ú  |   í  |   ó  |   [  | Del  |
 * |------+------+------+------+------+-------     -------+------+------+------+------+------|
 * |      |   á  |      |      |      |      |     | Home | PgDn | PgUp | End  |   {  |  |   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Make |      |      |      |      |      |     |  ñ   |      |      |      |   ¿  |Sysreq|
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * |      |MSTOP |      |      |      |      |     |      |      |      |      |      |      |
 * `------------------------------------------     ------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_TILD,   LATIN_IEXC,    _______, _______,  _______, _______,      _______,  _______,  _______,  KC_UNDS,  KC_PLUS,   KC_VOLD, \
  KC_CAPS,    QWERTY,        COLEMAK, LATIN_E,  _______, _______,      _______,  LATIN_U,  LATIN_I,  LATIN_O,  KC_LBRC,   KC_DEL, \
  _______,    LATIN_A,       _______, _______,  _______, _______,      KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_LCBR,   KC_PIPE, \
  QMK_MAKE,   _______,       _______, _______,  _______, _______,      LATIN_N,  _______,  _______,  _______,  LATIN_IQS, KC_SYSREQ, \
  _______,    DYN_REC_STOP,  _______, _______,  _______, _______,      _______,  _______,  _______,  _______,  _______,   _______ \
),

/* Raise
 * ,------------------------------------------     ------------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |   -  |   =  | Vol+ |
 * |------+------+------+------+------+-------     +------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |   ]  | Del  |
 * |------+------+------+------+------+-------     -------+------+------+------+------+------|
 * |      |      |      |      |      |      |     | Left | Down |  Up  |Right |   }  |  \   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |     |  F7  |  F8  |  F9  |  F10 | F11  | F12  |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * |      | MREC |      |      |      |      |     |      | TX_P |      |      |      |      |
 * `------------------------------------------     ------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  _______, _______,        _______, _______, _______, _______,      _______, _______,   _______, KC_MINS, KC_EQL,  KC_VOLU, \
  KC_GRAVE, _______,        _______, _______, _______, _______,      _______, _______,   _______, _______, KC_RBRC, KC_DEL, \
  _______, _______,        _______, _______, _______, _______,      KC_LEFT, KC_DOWN,   KC_UP,   KC_RGHT, KC_RCBR, KC_BSLS, \
  KC_F1,   KC_F2,          KC_F3,   KC_F4,   KC_F5,   KC_F6,        KC_F7,   KC_F8,     KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, DYN_REC_START1, _______, _______, _______, _______,      _______, TMUX_PREV, _______, _______, _______, _______ \
),

/* Shortcuts
 * ,------------------------------------------     ------------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |SGIPHY|SREACT|SSHRUG|      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * `------------------------------------------     ------------------------------------------'
 */
[_SHORTS] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,      _______,     _______,     _______,     _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,      _______,     _______,     _______,     _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,      SLACK_GIPHY, SLACK_REACT, SLACK_SHRUG, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,      _______,     _______,     _______,     _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,      _______,     _______,     _______,     _______, _______, _______  \
),

};

#ifdef SWAP_HANDS_ENABLE
// Each half duplicates the other half
const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = SWAP_HANDS_ORTHO_5X12_SPLIT;
#endif

#ifdef TAP_DANCE_ENABLE
void td_mute(td_stage stage) {
    td_key(stage, KC_MUTE);
}
void td_no_notif(td_stage stage) {
    if (stage == TD_FINISHED) {
        SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_GRAVE))));
    }
}
qk_tap_dance_action_t tap_dance_actions[] = {
    TD_TMUX_ENTRY,
    [td_mute_notif] = ACTION_TAP_DANCE_DOUBLE_FUNCS(td_mute, td_no_notif)
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }

    switch (keycode) {
        // SLACK
        case SLACK_GIPHY:
        case SLACK_SHRUG:
        case SLACK_REACT:
            if (record->event.pressed) {
                switch (keycode) {
                case SLACK_GIPHY: SEND_SLACK_SLASH("giphy"); break;
                case SLACK_SHRUG: SEND_SLACK_SLASH("shrug");
                                  SEND_STRING(SS_TAP(X_ENTER));
                                  break;
                case SLACK_REACT: SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_BSLASH)))); break;
                }
            }
            return false;
            break;
    }

    return userspace_process_record_user(keycode, record);
}
