#include QMK_KEYBOARD_H
#include "hokiegeek.h"

extern keymap_config_t keymap_config;

#define _MOUSE 4
#define _NUMPAD 5
#define _YABAI 6
#define _EXTRAS 7
// #define _CAMTASIA 8

enum custom_keycodes {
    SLACK_GIPHY = NEW_SAFE_RANGE,
    SLACK_SHRUG,
    SLACK_REACT,
    SLACK_RCTMB,
    SLACK_RCTHS,
    SLACK_RCHI5,
};

#ifdef TAP_DANCE_ENABLE
enum {
    td_mac_notif = TD_SAFE_RANGE,
    td_ctltab_mouse,
};
#define MAC_NOTIFS TD(td_mac_notif)
#define CTLTAB_MOUSE TD(td_ctltab_mouse)
#else
#define MAC_NOTIFS G(S(KC_GRAVE))
#define CTLTAB_MOUSE LCTL(KC_TAB)
#endif

#define BSCP_YABAI LT(_YABAI, KC_BSPC)
#define SSHOT MEH(KC_F14)

#undef __BASE_RCR2__
#define __BASE_RCR2__ MAC_NOTIFS

#define SEND_APP_FRONT(app)   SEND_DELAYED(50, SS_LGUI(SS_TAP(X_SPACE)) app SS_TAP(X_ENTER))
#define SEND_SLACK_SLASH(str) SEND_DELAYED(50, SS_TAP(X_SLASH) str SS_TAP(X_TAB))
#define SEND_SLACK_REACT(str) SEND_DELAYED(30, SS_LGUI(SS_LSFT(SS_TAP(X_BSLASH))) str SS_TAP(X_ENTER))
#define SEND_SLACK_GOTO(str)  SEND_DELAYED(50, SS_LGUI(SS_TAP(X_K)) str SS_TAP(X_ENTER))

#define _____BASE_BOTTOM_____  MO(_LOWER),                KC_ENC,  GUIBSPC, LALT_T(KC_SPC),          CTLTAB_MOUSE,  KC_TMUX, _______,                   MO(_RAISE)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Colemak
 * ,-----------------------------------------.     ,-----------------------------------------.
 * | Esc  |   Q  |   W  |   F  |   P  |   G  |     |   J  |   L  |   U  |   Y  |   ;  |NOTIF |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |Ctl/Tb|   A  |   R  |   S  |   T  |   D  |     |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |Sftlat|   Z  |   X  |   C  |   V  |   B  |     |   K  |   M  |   ,  |   .  |   /  |ShEnt |
 * |------+-------------+------+------+------|     |------+------+--------------------+------|
 * | Lower|             | ENC  | GUI  |AltSpc|     |CtlTb | TMUX |                    |Raise |
 * `------'             `--------------------'     `-------------'                    `------'
 */
[_COLEMAK] = LAYOUT_wrapper(
  __BASE_LCR2__, _____COLEMAK_R1_____, __BASE_RCR2__, \
  __BASE_LCR3__, _____COLEMAK_R2_____, \
  __BASE_LCR4__, _____COLEMAK_R3_____, __BASE_RCR4__, \
  _____BASE_BOTTOM_____
  ),

/* Qwerty
 * ,-----------------------------------------.     ,-----------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |     |   Y  |   U  |   I  |   O  |   P  |NOTIF |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |Ctl/Tb|   A  |   S  |   D  |   F  |   G  |     |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |Sftlat|   Z  |   X  |   C  |   V  |   B  |     |   N  |   M  |   ,  |   .  |   /  |ShEnt |
 * |------+-------------+------+------+------|     |------+------+--------------------+------|
 * | Lower|             | ENC  | GUI  |AltSpc|     |CtlTb | TMUX |                    |Raise |
 * `------'             `--------------------'     `-------------'                    `------'
 */
[_QWERTY] = LAYOUT_wrapper(
  __BASE_LCR2__, _____QWERTY_R1_____, __BASE_RCR2__, \
  __BASE_LCR3__, _____QWERTY_R2_____, \
  __BASE_LCR4__, _____QWERTY_R3_____, __BASE_RCR4__, \
  _____BASE_BOTTOM_____
  ),

/* Lower
 * ,-----------------------------------------.     ,-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |     |   ^  |   &  |   *  |   (  |   )  |  =   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     | Home | PgDn | PgUp | End  |   -  |  |   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |  {   |  }   |  [   |  ]   |      |
 * |------+-------------+------+------+------|     |------+------+--------------------+------|
 * |      |             | ENC  |YABBSP|      |     |      |      |                    |      |
 * `------'             `--------------------'     `-------------'                    `------'
 */
[_LOWER] = LAYOUT_wrapper(
  KC_TILD,                                         ______SYMBOLS______,                                         KC_EQL, \
  KC_CAPS, SSHOT,   KC_LBRC, KC_LPRN, KC_LCBR,    _______,         KC_HOME,     KC_PGDN, KC_PGUP, KC_END,  KC_MINS, KC_PIPE, \
  _______, _______, _______, _______, _______,    _______,         _______,     _______, _______, _______, _______, _______, \
  _______,                   _______, BSCP_YABAI, _______,         _______,     _______, _______,                   _______
  ),

/* Raise
 * ,-----------------------------------------.     ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |     |   6  |   7  |   8  |   9  |   0  |   +  |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |   )  |  ]   |  [   |      |     | Left | Down |  Up  |Right |   _  |  \   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |     |  F7  |  F8  |  F9  |  F10 | F11  | F12  |
 * |------+-------------+------+------+------|     |------+------+--------------------+------|
 * |      |             | ENC  |YABBSP|      |     |CSTAB | TX_P |                    |      |
 * `------'             `--------------------'     `-------------'                    `------'
 */
[_RAISE] = LAYOUT_wrapper(
  KC_GRAVE,                                        ______NUMBERS______,                                              KC_PLUS, \
  _______, _______, KC_RBRC, KC_RPRN, KC_RCBR,    _______,         KC_LEFT,     KC_DOWN,   KC_UP,    KC_RGHT,  KC_UNDS,  KC_BSLS, \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,           KC_F7,       KC_F8,     KC_F9,    KC_F10,   KC_F11,   KC_F12, \
  _______,                   _______, BSCP_YABAI, _______,         CSTAB,       TMUX_PREV, _______,                      _______
  ),

[_MOUSE] = LAYOUT( \
  _______,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
  _______,  _______, _______, _______, _______, _______,      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, \
  _______,  _______, _______, _______, _______, _______,      _______, KC_BTN1, KC_BTN3, KC_BTN2, _______, _______, \
  _______,                    _______, _______, _______,      _______, _______, _______,                   _______
  ),

[_NUMPAD] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,      _______, KC_7,    KC_8,    KC_9,    _______, _______, \
  _______, _______, _______, _______, _______, _______,      _______, KC_4,    KC_5,    KC_6,    _______, _______, \
  _______, _______, _______, _______, _______, _______,      _______, KC_1,    KC_2,    KC_3,    _______, _______, \
  _______,                   _______, _______, _______,      KC_0,    KC_DOT,  _______,                   _______
  ),

/* yabai
 * ,-----------------------------------------.     ,-----------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+-------------+------+------+------|     |------+------+--------------------+------|
 * |      |             | ENC  |      |      |     |      |      |                    |      |
 * `------'             `--------------------'     `-------------'                    `------'
 */
[_YABAI] = LAYOUT_wrapper( \
  _______,     LGUI(KC_1),   LGUI(KC_2), LGUI(KC_3), LGUI(KC_4),    LGUI(KC_5),         LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9),   LGUI(KC_0),    _______, \
  MEH(KC_TAB), _______,      _______,    _______,    LGUI(KC_SPC),  _______,            MEH(KC_H),  S(C(KC_N)), S(C(KC_E)), MEH(KC_I),    _______,       _______, \
  _______,     LCA(KC_Z),    LCA(KC_X),  LCA(KC_C),  MEH(KC_V),     _______,            _______,    MEH(KC_M),  _______,    MEH(KC_F15),  HYPR(KC_F15),  LGUI(KC_ENTER), \
  _______,                               _______,    _______,       LCAG(KC_SPC),       _______,    _______,    _______,                                 _______
  ),

/* extras
 * ,-----------------------------------------.     ,-----------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |SSHRUG|SGIPHY|SRCTMB|SRCTHS|SRCTHI|SREACT|
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+-------------+------+------+------|     |------+------+--------------------+------|
 * |      |             |      |      |      |     |      |      |                    |      |
 * `------'             `--------------------'     `-------------'                    `------'
 */
[_EXTRAS] = LAYOUT_wrapper(
  _______, _______, _______, _______, _______, _______,     _______,     _______,     _______,     _______,     _______,     _______, \
  _______, _______, _______, _______, _______, _______,     SLACK_SHRUG, SLACK_GIPHY, SLACK_RCTMB, SLACK_RCTHS, SLACK_RCHI5, SLACK_REACT, \
  _______, _______, _______, _______, _______, _______,     _______,     _______,     _______,     _______,     _______,     _______, \
  _______,                   _______, _______, _______,     _______,     _______,     _______,                               _______
  ),

/* camtasia
 * ,-----------------------------------------.     ,-----------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+-------------+------+------+------|     |------+------+--------------------+------|
 * |      |             | ENC  |      |      |     |      |      |                    |      |
 * `------'             `--------------------'     `-------------'                    `------'
 */
/*
[_CAMTASIA] = LAYOUT_wrapper(
  // LSFT(LGUI(KC_2)), LALT(LGUI(KC_2)),  KC_2,
  _______, _______, _______, _______  _______, _______,     _______,     _______,     _______,     _______,     _______,     _______, \
  _______, _______, _______, _______, _______, _______,     _______,     _______,     _______,     _______,     _______,     _______, \
  _______, _______, _______, _______, _______, _______,     _______,     _______,     _______,     _______,     _______,     _______, \
  _______,                   _______, _______, _______,     _______,     _______,     _______,                               _______
  ),
*/

// vscode
[_VSCODE] = LAYOUT_wrapper(
  _____VSCODE_R1_____, \
  _____VSCODE_R2_____, \
  _____VSCODE_R3_____, \
  _______,                   _______, _______, _______,     _______, _______, _______,                   _______
  ),

/* Adjust
 * ,-----------------------------------------.     ,-----------------------------------------.
 * |QMAKE |RESET |COLMAK|QWERTY|      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |OSNIX |OSMAC |OSWIN |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+-------------+------+------+------|     |------+------+--------------------+------|
 * |      |             | ENC  |      |      |     |      |      |                    |      |
 * `------'             `--------------------'     `-------------'                    `------'
 */
[_ADJUST] = LAYOUT_wrapper(
  QMK_MAKE, RESET,     COLEMAK,   QWERTY,    _______, _______,     RGB_HUI,  RGB_HUD,          RGB_SAI,          RGB_SAD,          RGB_VAI,            RGB_VAD, \
  _______,  KC_OS_NIX, KC_OS_MAC, KC_OS_WIN, _______, _______,     RGB_TOG,  RGB_MODE_PLAIN,   RGB_MODE_BREATHE, RGB_MOD, _______,   RGB_MODE_XMAS, \
  _______,  _______,   _______,   _______,   _______, _______,     _______, _______, _______, _______, _______, _______, \
  _______,                        _______,   _______, _______,     _______, _______, _______,                   _______
  )
};

#ifdef ENCODER_ENABLE
#ifdef TAP_DANCE_ENABLE
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
            // enc_opts.monBrightness = !enc_opts.monBrightness;
        } else { // Default layers
            enc_opts.defaultVolume = !enc_opts.defaultVolume;
        }
    }

    reset_tap_dance(state);
}
#endif

void encoder_update_user(uint8_t index, bool clockwise) {
    // if (index == 1) {
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
                    tap_code(KC_BRMU);
                } else {
                    tap_code(KC_BRMD);
                }
            // } else {
            //     if (clockwise) {
            //         tap_code(KC_UNDO);
            //     } else {
            //         tap_code(KC_STOP);
            //     }
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
    // }
}
#endif

#ifdef TAP_DANCE_ENABLE
ACTION_TAP_DANCE_TAPKEY_HOLDLAYER_FUNCS(td_ctltab_mouse, LCTL(KC_TAB), _MOUSE)

void td_notifs(td_stage stage) {
    td_key(stage, KC_F18);
}
void td_no_notif(td_stage stage) {
    if (stage == TD_FINISHED) {
        SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_GRAVE))));
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
#ifdef ENCODER_ENABLE
    TD_ENCODER_ENTRY,
#endif
    TD_TMUX_ENTRY,
    TD_SHIFT_LATIN,
    [td_mac_notif] = ACTION_TAP_DANCE_DOUBLE_FUNCS(td_notifs, td_no_notif),
    [td_ctltab_mouse] = ACTION_TAP_DANCE_TAPKEY_HOLDLAYER(td_ctltab_mouse)
};
#endif

#ifdef COMBO_ENABLE
COMBO_CHORD2(J, H);
COMBO_CHORD2(H, K);
COMBO_CHORD2(T, D);
COMBO_CHORD2(F, P);
COMBO_CHORD2(W, R);
COMBO_CHORD2(V, B);

enum combo_events {
    JH_TERM = 0,
    HK_BROWSER,
    TD_NUMPAD,
    FP_VSCODE,
    WR_SLACK,
    VB_EXTRAS
};

combo_t key_combos[COMBO_COUNT] = {
    [JH_TERM]    = COMBO_ACTION(chord2_JH),
    [HK_BROWSER] = COMBO_ACTION(chord2_HK),
    [TD_NUMPAD]  = COMBO_ACTION(chord2_TD),
    [FP_VSCODE]  = COMBO_ACTION(chord2_FP),
    [WR_SLACK]   = COMBO_ACTION(chord2_WR),
    [VB_EXTRAS]  = COMBO_ACTION(chord2_VB)
};

void process_combo_event(uint8_t combo_index, bool pressed) {
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
        case WR_SLACK:
            if (pressed) {
                tap_code16(MEH(KC_P1));
            }
            break;
        case TD_NUMPAD:
            if (pressed) {
                layer_on(_NUMPAD);
            } else {
                layer_off(_NUMPAD);
            }
            break;
        case VB_EXTRAS:
            if (pressed) {
                layer_on(_EXTRAS);
            } else {
                layer_off(_EXTRAS);
            }
            break;
      }
}
#endif

void matrix_init_user(void) {
    setTargetOS(OS_MAC);

    set_single_persistent_default_layer(_COLEMAK);

    userspace_matrix_init_user();
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // SLACK
        case SLACK_GIPHY:
        case SLACK_SHRUG:
        case SLACK_REACT:
        case SLACK_RCTMB:
        case SLACK_RCTHS:
        case SLACK_RCHI5:
            if (record->event.pressed) {
                switch (keycode) {
                case SLACK_GIPHY: SEND_SLACK_SLASH("giphy"); break;
                case SLACK_SHRUG: SEND_SLACK_SLASH("shrug");
                                  SEND_STRING(SS_TAP(X_ENTER));
                                  break;
                case SLACK_REACT: SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_BSLASH)))); break;
                case SLACK_RCTMB: SEND_SLACK_REACT("+1"); break;
                case SLACK_RCTHS: SEND_SLACK_REACT("this"); break;
                case SLACK_RCHI5: SEND_SLACK_REACT("hi-5"); break;
                }
            }
            return false;
            break;
    }

    return userspace_process_record_user(keycode, record);
}
