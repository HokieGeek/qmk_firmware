#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Layer names
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Accent defines
#ifdef TARGET_MAC
#define ACCENT_E_STRING SS_LALT("e")"e"
#define ACCENT_A_STRING SS_LALT("e")"a"
#define ACCENT_I_STRING SS_LALT("e")"i"
#define ACCENT_O_STRING SS_LALT("e")"o"
#define ACCENT_U_STRING SS_LALT("e")"u"
#define ACCENT_N_STRING SS_LALT("n")"n"
#define SEND_ACCENT(str) SEND_STRING(str)
#else
#define ACCENT_E_STRING "u00e9"
#define ACCENT_A_STRING "u00e1"
#define ACCENT_I_STRING "u00ed"
#define ACCENT_O_STRING "u00f3"
#define ACCENT_U_STRING "u00fc"
#define ACCENT_N_STRING "u00f1"
#define SEND_ACCENT(str) SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LSHIFT)strSS_UP(X_LCTRL)SS_UP(X_LSHIFT));
#endif

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,

    ACCENT_E,
    ACCENT_A,
    ACCENT_I,
    ACCENT_O,
    ACCENT_U,
    ACCENT_N,

    TMUX_NEXT,
    TMUX_PREV,
    TMUX_LAST,

    DYNAMIC_MACRO_RANGE,
};

#include "dynamic_macro.h"

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
// TD(TD_ACCENT_E)
[_QWERTY] = LAYOUT( \
  KC_GESC,        KC_1,            KC_2,    KC_3,    KC_4,       KC_5,    KC_6,    KC_7,       KC_8,       KC_9,       KC_0,     KC_BSPC, \
  KC_TAB,         KC_Q,            KC_W,    KC_E,    KC_R,       KC_T,    KC_Y,    KC_U,       KC_I,       KC_O,       KC_P,     KC_ENT, \
  KC_LCTL,        KC_A,            KC_S,    KC_D,    KC_F,       KC_G,    KC_H,    KC_J,       KC_K,       KC_L,       KC_SCLN,  KC_QUOT, \
  OSM(MOD_LSFT),  KC_Z,            KC_X,    KC_C,    KC_V,       KC_B,    KC_N,    KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,  KC_SFTENT, \
  SH_TT,          DYN_MACRO_PLAY1, KC_LALT, KC_LGUI, TT(_LOWER), KC_SPC,  KC_SPC,  TT(_RAISE), TMUX_NEXT,  TMUX_PREV,  KC_MUTE,  SH_TT \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |      |      |      |      |      |      |      |      |   _  |   +  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |   é  |      |      |      |   ú  |   í  |   ó  |   }  |Enter |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Caps |   á  |      |      |      |      | Home | PgDn | PgUp | End  |   {  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |  ñ   |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |MSTOP |      |      |      |      |      |      |      |      | Vol- |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_TILD,  _______,       _______, _______,  _______, _______, _______,  _______,  _______,  KC_UNDS,  KC_PLUS, KC_DEL, \
  _______,  _______,       _______, ACCENT_E, _______, _______, _______,  ACCENT_U, ACCENT_I, ACCENT_O, KC_RCBR, _______, \
  KC_CAPS,  ACCENT_A,      _______, _______,  _______, _______, KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_LCBR, KC_PIPE, \
  _______,  _______,       _______, _______,  _______, _______, ACCENT_N, _______,  _______,  _______,  _______, _______, \
  _______,  DYN_REC_STOP,  _______, _______,  _______, _______, _______,  _______,  _______,  _______,  KC_VOLD, _______ \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |   -  |   =  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |   ]  |Enter |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | Left | Down |  Up  |Right |   [  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | F11  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | MREC |      |      |      |      |      |      | TX_L |      | Vol+ |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  _______, _______,        _______, _______, _______, _______, _______, _______, _______,   KC_MINS, KC_EQL,  KC_DEL, \
  _______, _______,        _______, _______, _______, _______, _______, _______, _______,   _______, KC_RBRC, _______, \
  _______, _______,        _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,     KC_RGHT, KC_LBRC, KC_BSLS, \
  KC_F1,   KC_F2,          KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,     KC_F10,  KC_F11,  KC_F12, \
  _______, DYN_REC_START1, _______, _______, _______, _______, _______, _______, TMUX_LAST, _______, KC_VOLU, _______ \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Reset |      |      |      |      |      |      |      |      | Pscr |      |
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
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, _______, \
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
        case ACCENT_E:
        case ACCENT_A:
        case ACCENT_I:
        case ACCENT_O:
        case ACCENT_U:
        case ACCENT_N:
            if (record->event.pressed) {
                switch (keycode) {
                case ACCENT_E: SEND_ACCENT(ACCENT_E_STRING); break;
                case ACCENT_A: SEND_ACCENT(ACCENT_A_STRING); break;
                case ACCENT_I: SEND_ACCENT(ACCENT_I_STRING); break;
                case ACCENT_O: SEND_ACCENT(ACCENT_O_STRING); break;
                case ACCENT_U: SEND_ACCENT(ACCENT_U_STRING); break;
                case ACCENT_N: SEND_ACCENT(ACCENT_N_STRING); break;
                }
            }
            return false;
            break;

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

        case TMUX_LAST:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("a")SS_LCTRL("a"));
            }
            return false;
            break;
    }
    return true;
}
