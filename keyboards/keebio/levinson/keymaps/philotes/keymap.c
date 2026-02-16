#include QMK_KEYBOARD_H
#include "hokiegeek.h"

#define _MOUSE 4
#define _NUMPAD 5

extern keymap_config_t keymap_config;

#ifdef TAP_DANCE_ENABLE
enum {
    td_ctltab_mouse = TD_SAFE_RANGE
};
#endif

enum custom_keycodes {
    CTLTAB = NEW_SAFE_RANGE
};

// |------+------+------+------+------+------|   |------+------+------+------+------+------|
// | Lower|      |      |      |GUIBsp|AltSpc|   |CtlTb | TMUX | ENC  |      |      |Raise |
// `-----------------------------------------'   `-----------------------------------------'
#define _____BASE_BOTTOM_____   MO(_LOWER), _______, _______,  _______, GUIBSPC, LALT_T(KC_SPC),     TD(td_ctltab_mouse),  KC_TMUX, KC_ENC,  _______,  _______,  MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------.   ,-----------------------------------------.
 * | Esc  |   Q  |   W  |   F  |   P  |   G  |   |   J  |   L  |   U  |   Y  |   ;  | SKDM |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |Ctl/Tb|   A  |   R  |   S  |   T  |   D  |   |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |SftLat|   Z  |   X  |   C  |   V  |   B  |   |   K  |   M  |   ,  |   .  |   /  |ShEnt |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Lower|      |      |      |GUIBsp|AltSpc|   |CtlTb | TMUX | ENC  |      |      |Raise |
 * `-----------------------------------------'   `-----------------------------------------'
 */
[_COLEMAK] = LAYOUT_wrapper( \
  __BASE_LCR2__, _____COLEMAK_R1_____, __BASE_RCR2__, \
  __BASE_LCR3__, _____COLEMAK_R2_____, \
  __BASE_LCR4__, _____COLEMAK_R3_____, __BASE_RCR4__, \
  _____BASE_BOTTOM_____ \
),

/* Qwerty
 * ,-----------------------------------------.   ,-----------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   |   Y  |   U  |   I  |   O  |   P  | SKDM |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |Ctl/Tb|   A  |   S  |   D  |   F  |   G  |   |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |SftLat|   Z  |   X  |   C  |   V  |   B  |   |   N  |   M  |   ,  |   .  |   /  |ShEnt |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Lower|      |      |      |GUIBsp|AltSpc|   |CtlTb | TMUX | ENC  |      |      |Raise |
 * `-----------------------------------------'   `-----------------------------------------'
 */
[_QWERTY] = LAYOUT_wrapper( \
  __BASE_LCR2__, _____QWERTY_R1_____, __BASE_RCR2__, \
  __BASE_LCR3__, _____QWERTY_R2_____, \
  __BASE_LCR4__, _____QWERTY_R3_____, __BASE_RCR4__, \
  _____BASE_BOTTOM_____ \
),

/* Lower
 * ,-----------------------------------------.   ,-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   |   ^  |   &  |   *  |   +  |   =  |      |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | CAPS |AltPrt|  (   |  }   |  {   |      |   | Home | PgDn | PgUp | End  |   -  |  |   |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |   |      |      |      |      |      |      |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      |      |      |      |NPDBSP|      |   |      |      |      |      |      |      |
 * `-----------------------------------------'   `-----------------------------------------'
 */
[_LOWER] = LAYOUT_wrapper( \
  KC_TILD,                                          ______SYMBOLS______,           _______, \
  KC_CAPS, ALTPSCR, KC_LBRC, KC_LPRN, KC_LCBR,     _______,      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_MINS, KC_PIPE, \
  _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______, _______, \
  _______, BL_TOGG, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______ \
),

/* Raise
 * ,-----------------------------------------.   ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |   |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      |Print |  )   |  ]   |  [   |      |   | Left | Down |  Up  |Right |   _  |  \   |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   |  F7  |  F8  |  F9  |  F10 | F11  | F12  |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |   |CSTAB | TX_P |      |      |      |      |
 * `-----------------------------------------'   `-----------------------------------------'
 */
[_RAISE] = LAYOUT_wrapper( \
  KC_GRAVE,          ______NUMBERS______,       _______,
  _______,  KC_PSCR, KC_RBRC, KC_RPRN, KC_RCBR, _______,      KC_LEFT, KC_DOWN,   KC_UP,    KC_RGHT, KC_UNDS, KC_BSLS, \
  KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,        KC_F7,   KC_F8,     KC_F9,    KC_F10,  KC_F11,  KC_F12, \
  _______,  _______, _______, _______, GUIDEL, _______,      CSTAB,   TMUX_PREV, _______,  _______, _______, _______ \
),

[_VSCODE] = LAYOUT_wrapper( \
  _____VSCODE_R1_____, \
  _____VSCODE_R2_____, \
  _____VSCODE_R3_____, \
  _______,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______  \
),

[_MOUSE] = LAYOUT( \
  _______,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
  _______,  _______, _______, _______, _______, _______,      MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, _______, _______, \
  _______,  _______, _______, _______, _______, _______,      _______, MS_BTN1, MS_BTN3, MS_BTN2, _______, _______, \
  _______,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______  \
),

[_NUMPAD] = LAYOUT( \
  _______,  _______, _______, _______, _______, _______,      _______, KC_7,    KC_8,    KC_9,    _______, _______, \
  _______,  _______, _______, _______, _______, _______,      _______, KC_4,    KC_5,    KC_6,    _______, _______, \
  _______,  _______, _______, _______, _______, _______,      _______, KC_1,    KC_2,    KC_3,    _______, _______, \
  _______,  _______, _______, _______, _______, _______,      KC_0,    KC_DOT,  _______, _______, _______, _______  \
),

/* Adjust
 * ,-----------------------------------------.   ,-----------------------------------------.
 * |QMAKE |RESET |COLMAK|QWERTY|      |      |   |      |      |      |      |      |      |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      |OSNIX |OSMAC |OSWIN |      |      |   |      |      |      |      |      |      |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |   |      |      |      |      |      |      |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |   |      |      |      |      |      |      |
 * `-----------------------------------------'   `-----------------------------------------'
 */
[_ADJUST] = LAYOUT( \
  QMK_MAKE, QK_BOOT,     COLEMAK,    QWERTY,   _______, _______,      UG_HUEU,  UG_HUED,          UG_SATU,          UG_SATD,          UG_VALU,            UG_VALD, \
  _______,  KC_OS_NIX, KC_OS_MAC, KC_OS_WIN, _______, _______,      UG_TOGG,  RGB_MODE_PLAIN,   RGB_MODE_BREATHE, UG_NEXT, _______,   RGB_MODE_XMAS, \
  _______,  _______,   _______,   _______,   _______, _______,      _______, _______, _______, _______, _______, _______, \
  _______,  _______,   _______,   _______,   _______, _______,      _______, _______, _______, _______, _______, _______  \
),

};

#ifdef ENCODER_ENABLE
encoder_options enc_opts = {
    .scrollVertical = true,
    .monBrightness = true,
    .backlightBrightness = true,
    .defaultVolume = true
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 1) {
        if (IS_LAYER_ON(_ADJUST)) {
            if (enc_opts.backlightBrightness) {
#ifdef BACKLIGHT_ENABLE
                if (clockwise) {
                    backlight_increase();
                } else {
                    backlight_decrease();
                }
#endif
            }
        } else if (IS_LAYER_ON(_LOWER)) {
            if (enc_opts.monBrightness) {
                if (clockwise) {
                    tap_code(KC_FIND);
                } else {
                    tap_code(KC_HELP);
                }
            } else { // Monitor warmth
                if (clockwise) {
                    tap_code(KC_UNDO);
                } else {
                    tap_code(KC_STOP);
                }
            }
        } else if (IS_LAYER_ON(_RAISE)) { // Browser zooming
            if (clockwise) {
                tap_code16(LCTL(KC_KP_PLUS));
            } else {
                tap_code16(LCTL(KC_KP_MINUS));
            }
        } else { // Default layers
            if (enc_opts.defaultVolume) {
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
            } else {
                if (enc_opts.scrollVertical) {
                    if (clockwise) {
                        tap_mousekey(MS_WHLD);
                    } else {
                        tap_mousekey(MS_WHLU);
                    }
                } else {
                    if (clockwise) {
                        tap_mousekey(MS_WHLR);
                    } else {
                        tap_mousekey(MS_WHLL);
                    }
                }
            }
        }
    }
    return true;
}
#endif

#if defined(TAP_DANCE_ENABLE) && defined(ENCODER_ENABLE)
void encoder_td_actions (tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (IS_LAYER_ON(_ADJUST)) {
            if (enc_opts.backlightBrightness) {
#ifdef BACKLIGHT_ENABLE
                backlight_toggle();
#endif
#ifdef RGBLIGHT_ENABLE
            } else {
                rgblight_toggle();
#endif
            }
        } else if (IS_LAYER_ON(_LOWER)) {
            enc_opts.monBrightness = !enc_opts.monBrightness;
        } else { // Default layers
            if (enc_opts.defaultVolume) {
                tap_code(KC_MUTE);
            } else {
                enc_opts.scrollVertical = !enc_opts.scrollVertical;
            }
        }
    } else if (state->count == 2) {
        if (IS_LAYER_ON(_ADJUST)) {
            enc_opts.backlightBrightness = !enc_opts.backlightBrightness;
        } else if (IS_LAYER_ON(_LOWER)) {
            // TODO
        } else { // Default layers
            enc_opts.defaultVolume = !enc_opts.defaultVolume;
        }
    }

    reset_tap_dance (state);
}
#endif

#ifdef TAP_DANCE_ENABLE
ACTION_TAP_DANCE_TAPKEY_HOLDLAYER_FUNCS(td_ctltab_mouse, LCTL(KC_TAB), _MOUSE)

tap_dance_action_t tap_dance_actions[] = {
    TD_TMUX_ENTRY,
    TD_SHIFT_LATIN,
#ifdef ENCODER_ENABLE
    TD_ENCODER_ENTRY,
#endif
#ifdef DYNAMIC_MACRO_ENABLE
    TD_SKDM1_ENTRY,
    // TD_SKDM2_ENTRY,
#endif
    [td_ctltab_mouse] = ACTION_TAP_DANCE_TAPKEY_HOLDLAYER(td_ctltab_mouse)
};
#endif

#ifdef COMBO_ENABLE
COMBO_CHORD2(J, H);
COMBO_CHORD2(H, K);
COMBO_CHORD2(F, P);
COMBO_CHORD2(T, D);
COMBO_CHORD2(J, L);
COMBO_CHORD2(L, U);
COMBO_CHORD2(U, Y);
COMBO_CHORD2(Y, SCLN);
COMBO_CHORD2(H, N);
COMBO_CHORD2(N, E);
COMBO_CHORD2(E, I);
COMBO_CHORD2(K, M);
COMBO_CHORD2(M, COMM);
COMBO_CHORD2(COMM, DOT);

enum combo_events {
    JH_TERM = 0,
    HK_BROWSER,
    FP_VSCODE,
    TD_NUMPAD,
    JL_7,
    LU_8,
    UY_9,
    YSCLN_0,
    HN_6,
    NE_5,
    EI_4,
    KM_3,
    MCOMM_2,
    COMMDOT_1
};

combo_t key_combos[] = {
    [JH_TERM]     = COMBO_ACTION(chord2_JH),
    [HK_BROWSER]  = COMBO_ACTION(chord2_HK),
    [FP_VSCODE]   = COMBO_ACTION(chord2_FP),
    [TD_NUMPAD]   = COMBO_ACTION(chord2_TD),
    [JL_7]        = COMBO(chord2_JL, KC_7),
    [LU_8]        = COMBO(chord2_LU, KC_8),
    [UY_9]        = COMBO(chord2_UY, KC_9),
    [YSCLN_0]     = COMBO(chord2_YSCLN, KC_0),
    [HN_6]        = COMBO(chord2_HN, KC_6),
    [NE_5]        = COMBO(chord2_NE, KC_5),
    [EI_4]        = COMBO(chord2_EI, KC_4),
    [KM_3]        = COMBO(chord2_KM, KC_3),
    [MCOMM_2]     = COMBO(chord2_MCOMM, KC_2),
    [COMMDOT_1]   = COMBO(chord2_COMMDOT, KC_1)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
      switch(combo_index) {
        case JH_TERM:
            if (pressed) {
                tap_code16(LGUI(LSFT(KC_ENT)));
            }
            break;
        case HK_BROWSER:
            if (pressed) {
                tap_code16(HYPR(KC_ENT));
            }
            break;
        case FP_VSCODE:
            if (pressed) {
                layer_on(_VSCODE);
            } else {
                layer_off(_VSCODE);
            }
            break;
        case TD_NUMPAD:
            if (pressed) {
                layer_on(_NUMPAD);
            } else {
                layer_off(_NUMPAD);
            }
            break;
      }
}
#endif

void matrix_init_user(void) {
    userspace_matrix_init_user();
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return userspace_process_record_user(keycode, record);
}
