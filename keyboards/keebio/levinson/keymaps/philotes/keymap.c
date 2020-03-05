#include QMK_KEYBOARD_H
#include "hokiegeek.h"

#define _NUMPAD 5

extern keymap_config_t keymap_config;

#ifdef TAP_DANCE_ENABLE
enum {
    td_ctltab_extras = TD_SAFE_RANGE
};
#define TERM_VSCODE TD(td_terminal_vscode)
#else
#define TERM_VSCODE G(S(KC_ENT))
#endif

enum custom_keycodes {
    CTLTAB = NEW_SAFE_RANGE
};

#undef __BASE_RCR2__
#define __BASE_RCR2__ KC_SKDM1

// |------+------+------+------+------+------|   |------+------+------+------+------+------|
// | Lower|      |      |      |GUIBsp|AltSpc|   |CtlTb | TMUX | ENC  |      |      |Raise |
// `-----------------------------------------'   `-----------------------------------------'
#define _____BASE_BOTTOM_____   MO(_LOWER), _______, _______,  _______, GUIBSPC, LALT_T(KC_SPC),     TD(td_ctltab_extras),  KC_TMUX, KC_ENC,  _______,  _______,  MO(_RAISE)

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
 * |      |      |      |      |      |      |   |      |      |      |      |      |      |
 * `-----------------------------------------'   `-----------------------------------------'
 */
[_LOWER] = LAYOUT_wrapper( \
  KC_TILD,          ______SYMBOLS______,       _______, \
  KC_CAPS, ALTPSCR, KC_LBRC, KC_LPRN, KC_LCBR, _______,      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_MINS, KC_PIPE, \
  _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, MO(_NUMPAD), _______,      _______, _______, _______, _______, _______, _______ \
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
  _______,  _______, _______, _______, _______, _______,      CSTAB,   TMUX_PREV, _______,  _______, _______, _______ \
),

[_VSCODE] = LAYOUT_wrapper( \
  _____VSCODE_R1_____, \
  _____VSCODE_R2_____, \
  _____VSCODE_R3_____, \
  _______,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______  \
),

[_EXTRAS] = LAYOUT( \
  _______,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
  _______,  _______, _______, _______, _______, _______,      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, \
  _______,  _______, _______, _______, _______, _______,      KC_BTN1, KC_BTN3, KC_BTN2, _______, _______, _______, \
  _______,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______  \
),

[_NUMPAD] = LAYOUT( \
  _______,  _______, _______, _______, _______, _______,      _______, KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  _______,  _______, _______, _______, _______, _______,      _______, KC_4,    KC_5,    KC_6,    _______, _______, \
  _______,  _______, _______, _______, _______, _______,      _______, KC_1,    KC_2,    KC_3,    _______, _______, \
  _______,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______  \
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
  QMK_MAKE, RESET,     COLEMAK,    QWERTY,   _______, _______,      RGB_HUI,  RGB_HUD,          RGB_SAI,          RGB_SAD,          RGB_VAI,            RGB_VAD, \
  _______,  KC_OS_NIX, KC_OS_MAC, KC_OS_WIN, _______, _______,      RGB_TOG,  RGB_MODE_PLAIN,   RGB_MODE_BREATHE, RGB_MOD, _______,   RGB_MODE_XMAS, \
  _______,  _______,   _______,   _______,   _______, _______,      _______, _______, _______, _______, _______, _______, \
  _______,  _______,   _______,   _______,   _______, _______,      _______, _______, _______, _______, _______, _______  \
),

};

#if defined(TAP_DANCE_ENABLE) && defined(ENCODER_ENABLE)
void encoder_td_actions (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (IS_LAYER_ON(_ADJUST)) {
            if (enc_opts.backlightBrightness) {
                backlight_toggle();
#ifdef RGBLIGHT_ENABLE
            } else {
                rgblight_toggle();
#endif
            }
        } else if (IS_LAYER_ON(_LOWER)) {
            // TODO
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
            enc_opts.monBrightness = !enc_opts.monBrightness;
        } else { // Default layers
            enc_opts.defaultVolume = !enc_opts.defaultVolume;
        }
    }

    reset_tap_dance (state);
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 1) {
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
                    tap_code(KC_FIND);
                } else {
                    tap_code(KC_HELP);
                }
            } else {
                if (clockwise) {
                    tap_code(KC_UNDO);
                } else {
                    tap_code(KC_STOP);
                }
            }
        } else if (IS_LAYER_ON(_RAISE)) {
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
                        tap_mousekey(KC_MS_WH_DOWN);
                    } else {
                        tap_mousekey(KC_MS_WH_UP);
                    }
                } else {
                    if (clockwise) {
                        tap_mousekey(KC_MS_WH_RIGHT);
                    } else {
                        tap_mousekey(KC_MS_WH_LEFT);
                    }
                }
            }
        }
    }
}
#endif

#ifdef TAP_DANCE_ENABLE
void extras_layer_on_hold(td_stage stage) {
    switch (stage) {
        case TD_FINISHED: layer_on(_EXTRAS); break;
        case TD_RESET:    layer_off(_EXTRAS); break;
        default: break;
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
#ifdef ENCODER_ENABLE
    TD_ENCODER_ENTRY,
#endif
    TD_TMUX_ENTRY,
    TD_SHIFT_LATIN,
#ifdef DYNAMIC_MACRO_ENABLE
    TD_SKDM1_ENTRY,
    TD_SKDM2_ENTRY,
#endif
    [td_ctltab_extras] = ACTION_TAP_DANCE_TAP_HOLD(td_tap_ctltab, extras_layer_on_hold)
};
#endif

enum combo_events {
    JL_TERM = 0,
    JH_BROWSER,
    DB_VSCODE,
    RS_VSCODE,
    AR_VSCODE,
    WF_VSCODE,
    FP_VSCODE,
    ST_VSCODE
};

combo_t key_combos[COMBO_COUNT] = {
    [JL_TERM] = COMBO_ACTION(chords2[JL]),
    [JH_BROWSER] = COMBO_ACTION(chords2[JH]),
    [DB_VSCODE] = COMBO_ACTION(chords2[DB]),
    [RS_VSCODE] = COMBO_ACTION(chords2[RS]),
    [AR_VSCODE] = COMBO_ACTION(chords2[AR]),
    [WF_VSCODE] = COMBO_ACTION(chords2[WF]),
    [FP_VSCODE] = COMBO_ACTION(chords2[FP]),
    [ST_VSCODE] = COMBO_ACTION(chords2[ST])
};

void process_combo_event(uint8_t combo_index, bool pressed) {
      switch(combo_index) {
        case JL_TERM:
            if (pressed) {
                tap_code16(LGUI(LSFT(KC_ENT)));
            }
            break;
        case JH_BROWSER:
            if (pressed) {
                tap_code16(HYPR(KC_ENT));
            }
            break;
        case DB_VSCODE:
        case RS_VSCODE:
        case AR_VSCODE:
        case WF_VSCODE:
        case FP_VSCODE:
        case ST_VSCODE:
            if (pressed) {
                layer_on(_VSCODE);
            } else {
                layer_off(_VSCODE);
            }
            break;
      }
}

void matrix_init_user(void) {
    set_single_persistent_default_layer(_COLEMAK);

    userspace_matrix_init_user();
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return userspace_process_record_user(keycode, record);
}
