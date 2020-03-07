#include QMK_KEYBOARD_H
#include "hokiegeek.h"

extern keymap_config_t keymap_config;

#define _EXTRAS 4
#define _NUMPAD 5
#define _YABAI 6
#define _CAMTASIA 7

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
    td_ctltab_extras,
};
#define MAC_NOTIFS TD(td_mac_notif)
#define CTLTAB_EXTRAS TD(td_ctltab_extras)
#else
#define MAC_NOTIFS G(S(KC_GRAVE))
#define CTLTAB_EXTRAS LCTL(KC_TAB)
#endif

#define BSCP_YABAI LT(_YABAI, KC_BSPC)

#undef __BASE_RCR2__
#define __BASE_RCR2__ MAC_NOTIFS

#define SEND_APP_FRONT(app)   SEND_DELAYED(50, SS_LGUI(SS_TAP(X_SPACE)) app SS_TAP(X_ENTER))
#define SEND_SLACK_SLASH(str) SEND_DELAYED(50, SS_TAP(X_SLASH) str SS_TAP(X_TAB))
#define SEND_SLACK_REACT(str) SEND_DELAYED(40, SS_LGUI(SS_LSFT(SS_TAP(X_BSLASH))) str SS_TAP(X_ENTER))
#define SEND_SLACK_GOTO(str)  SEND_DELAYED(50, SS_LGUI(SS_TAP(X_K)) str SS_TAP(X_ENTER))

#define _____BASE_TOP_____     _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______
#define _____BASE_BOTTOM_____  MO(_LOWER),  KC_F13, KC_ENC,   _______,  GUIBSPC,  LALT_T(KC_SPC),       CTLTAB_EXTRAS,  KC_TMUX,  _______,  _______,   KC_SKDM1,  MO(_RAISE)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,------------------------------------------     ------------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |     |   Y  |   U  |   I  |   O  |   P  |NOTIF |
 * |------+------+------+------+------+-------     -------+------+------+------+------+------|
 * |Ctl/Tb|   A  |   S  |   D  |   F  |   G  |     |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |SftLat|   Z  |   X  |   C  |   V  |   B  |     |   N  |   M  |   ,  |   .  |   /  |ShEnt |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * | Lower|      | ENC  |YABAI |SpcGUI|AltSpc|     |CtlTb | TMUX |      |TRMVSC| MACR |Raise |
 * `------------------------------------------     ------------------------------------------'
 */
[_QWERTY] = LAYOUT_wrapper( \
  _____BASE_TOP_____, \
  __BASE_LCR2__, _____QWERTY_R1_____, __BASE_RCR2__, \
  __BASE_LCR3__, _____QWERTY_R2_____, \
  __BASE_LCR4__, _____QWERTY_R3_____, __BASE_RCR4__, \
  _____BASE_BOTTOM_____ \
),

/* Colemak
 * ,------------------------------------------     ------------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * | Esc  |   Q  |   W  |   F  |   P  |   G  |     |   J  |   L  |   U  |   Y  |   ;  |NOTIF |
 * |------+------+------+------+------+-------     -------+------+------+------+------+------|
 * |Ctl/Tb|   A  |   R  |   S  |   T  |   D  |     |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |SftLat|   Z  |   X  |   C  |   V  |   B  |     |   K  |   M  |   ,  |   .  |   /  |ShEnt |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * | Lower|      | ENC  |      |SpcGUI|AltSpc|     |CtlTb | TMUX |      |TRMVSC| MACR |Raise |
 * `------------------------------------------     ------------------------------------------'
 */
[_COLEMAK] = LAYOUT_wrapper( \
  _____BASE_TOP_____, \
  __BASE_LCR2__, _____COLEMAK_R1_____, __BASE_RCR2__, \
  __BASE_LCR3__, _____COLEMAK_R2_____, \
  __BASE_LCR4__, _____COLEMAK_R3_____, __BASE_RCR4__, \
  _____BASE_BOTTOM_____ \
),

/* Lower
 * ,------------------------------------------     ------------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+-------     +------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |     |   ^  |   &  |   *  |   +  |   =  |      |
 * |------+------+------+------+------+-------     -------+------+------+------+------+------|
 * |      |      |  [   |  (   |  {   |      |     | Home | PgDn | PgUp | End  |   -  |  |   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * |      |      | ENC  |      |YABBSP|      |     |      |      |      |      |      |      |
 * `------------------------------------------     ------------------------------------------'
 */
[_LOWER] = LAYOUT_wrapper( \
  _______,  _______,      _______,  _______,   _______,     _______,      _______,  _______,  _______,  _______,  _______,  _______, \
  KC_TILD,                                                  ______SYMBOLS______,                                            _______, \
  KC_CAPS,  _______,      KC_LBRC,  KC_LPRN,   KC_LCBR,     _______,      KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_MINS,  KC_PIPE, \
  _______,  _______,      _______,  _______,   _______,     _______,      _______,  _______,  _______,  _______,  _______,  _______, \
  _______,  MEH(KC_F13),  _______,  _______,   BSCP_YABAI,  _______,      _______,  _______,  _______,  _______,  _______,  _______ \
),

/* Raise
 * ,------------------------------------------     ------------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+-------     +------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |     |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------     -------+------+------+------+------+------|
 * |      |      |  ]   |  )   |  }   |      |     | Left | Down |  Up  |Right |   _  |  \   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |     |  F7  |  F8  |  F9  |  F10 | F11  | F12  |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * |      |      | ENC  |      |YABBSP|      |     |CSTAB | TX_P |      |      | MREC |      |
 * `------------------------------------------     ------------------------------------------'
 */
[_RAISE] = LAYOUT_wrapper( \
  _______,   _______,       _______,  _______,   _______,     _______,      _______,  _______,    _______,  _______,  _______,  _______, \
  KC_GRAVE,                                                   ______NUMBERS______,                                              _______, \
  _______,   _______,       KC_RBRC,  KC_RPRN,   KC_RCBR,     _______,      KC_LEFT,  KC_DOWN,    KC_UP,    KC_RGHT,  KC_UNDS,  KC_BSLS, \
  KC_F1,     KC_F2,         KC_F3,    KC_F4,     KC_F5,       KC_F6,        KC_F7,    KC_F8,      KC_F9,    KC_F10,   KC_F11,   KC_F12, \
  _______,   HYPR(KC_F13),  _______,  _______,   BSCP_YABAI,  _______,      CSTAB,    TMUX_PREV,  _______,  _______,  _______,  _______ \
),

/* extras
 * ,------------------------------------------     ------------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |  7   |  8   |  9   |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |  4   |  5   |  6   |      |     |SSHRUG|SGIPHY|SRCTMB|SRCTHS|SRCTHI|SREACT|
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |  1   |  2   |  3   |  0   |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      | ENC  |      |      |      |     |      |      |      |      |      |      |
 * `------------------------------------------     ------------------------------------------'
 */
[_EXTRAS] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,      _______,     _______,     _______,     _______,     _______,     _______, \
  _______, _______, KC_7,    KC_8,    KC_9,    _______,      _______,     _______,     _______,     _______,     _______,     _______, \
  _______, _______, KC_4,    KC_5,    KC_6,    _______,      SLACK_SHRUG, SLACK_GIPHY, SLACK_RCTMB, SLACK_RCTHS, SLACK_RCHI5, SLACK_REACT, \
  _______, _______, KC_1,    KC_2,    KC_3,    KC_0,         _______,     _______,     _______,     _______,     _______,     _______, \
  _______, _______, _______, _______, _______, _______,      _______,     _______,     _______,     _______,     _______,     _______  \
),

[_NUMPAD] = LAYOUT( \
  _______,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
  _______,  _______, _______, _______, _______, _______,      _______, KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  _______,  _______, _______, _______, _______, _______,      _______, KC_4,    KC_5,    KC_6,    _______, _______, \
  _______,  _______, _______, _______, _______, _______,      _______, KC_1,    KC_2,    KC_3,    _______, _______, \
  _______,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______  \
),

/* yabai
 * ,------------------------------------------     ------------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |LSTTOP|      |      |      |SPOTLT|      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |START | STOP |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * `------------------------------------------     ------------------------------------------'
 */
[_YABAI] = LAYOUT( \
  _______,     _______,      _______,    _______,    _______,       _______,            _______,    _______,    _______,    _______,      _______,       _______, \
  _______,     LGUI(KC_1),   LGUI(KC_2), LGUI(KC_3), LGUI(KC_4),    LGUI(KC_5),         LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9),   LGUI(KC_0),    _______, \
  MEH(KC_TAB), _______,      _______,    _______,    LGUI(KC_SPC),  _______,            MEH(KC_H),  S(C(KC_N)), S(C(KC_E)), MEH(KC_I),    _______,       _______, \
  _______,     LCA(KC_Z),    LCA(KC_X),  LCA(KC_C),  MEH(KC_V),     _______,            _______,    MEH(KC_M),  _______,    MEH(KC_F15),  HYPR(KC_F15),  LGUI(KC_ENTER), \
  _______,     _______,      _______,    _______,    _______,       LCAG(KC_SPC),       _______,    _______,    _______,    _______,      _______,       _______  \
),

/* camtasia
 * ,------------------------------------------     ------------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * `------------------------------------------     ------------------------------------------'
 */
[_CAMTASIA] = LAYOUT( \
  _______, _______,    _______,     _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______, \
  _______, LSFT(LGUI(KC_2)), LALT(LGUI(KC_2)),  KC_2, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  \
  _______, _______,    _______,     _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  \
  _______, _______,    _______,     _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  \
  _______, _______,    _______,     _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______  \
),

/* VSCODE */
[_VSCODE] = LAYOUT_wrapper( \
  _______,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,  \
  _____VSCODE_R1_____, \
  _____VSCODE_R2_____, \
  _____VSCODE_R3_____, \
  _______,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______  \
),

/* Adjust
 * ,------------------------------------------     ------------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+-------     +------+------+------+------+------+------|
 * |QMAKE |QWERTY|COLMAK|RESET |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+-------     -------+------+------+------+------+------|
 * |      |OSNIX |OSMAC |OSWIN |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * `------------------------------------------     ------------------------------------------'
 */
[_ADJUST] = LAYOUT( \
  _______,   _______,   _______,   _______,   _______, _______,      _______, _______, _______, _______, _______, _______, \
  QMK_MAKE,  QWERTY,    COLEMAK,   RESET,     _______, _______,      _______, _______, _______, _______, _______, _______, \
  _______,   KC_OS_NIX, KC_OS_MAC, KC_OS_WIN, _______, _______,      _______, _______, _______, _______, _______, _______, \
  _______,   TG(_CAMTASIA),   _______,   _______,   _______, _______,      _______, _______, _______, _______, _______, _______, \
  _______,   _______,   _______,   _______,   _______, _______,      _______, _______, _______, _______, _______, _______  \
),

};

#if defined(TAP_DANCE_ENABLE) && defined(ENCODER_ENABLE)
void encoder_td_actions (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (IS_LAYER_ON(_ADJUST)) {
            // TODO
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
            // enc_opts.backlightBrightness = !enc_opts.backlightBrightness;
        } else if (IS_LAYER_ON(_LOWER)) {
            // enc_opts.monBrightness = !enc_opts.monBrightness;
        } else { // Default layers
            enc_opts.defaultVolume = !enc_opts.defaultVolume;
        }
    }

    reset_tap_dance (state);
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (IS_LAYER_ON(_ADJUST)) {
            /*
            if (enc_opts.backlightBrightness) {
                if (clockwise) {
                    backlight_increase();
                } else {
                    backlight_decrease();
                }
            }
            */
        } else if (IS_LAYER_ON(_LOWER)) {
            if (enc_opts.monBrightness) {
                if (clockwise) {
                    tap_code(KC_BRMU);
                } else {
                    tap_code(KC_BRMD);
                }
            /*
            } else {
                if (clockwise) {
                    tap_code(KC_UNDO);
                } else {
                    tap_code(KC_STOP);
                }
            */
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
ACTION_TAP_DANCE_TAPKEY_HOLDLAYER_FUNCS(td_ctltab_extras, LCTL(KC_TAB), _EXTRAS)

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
    [td_ctltab_extras] = ACTION_TAP_DANCE_TAPKEY_HOLDLAYER(td_ctltab_extras)
};
#endif

enum combo_events {
    JL_TERM = 0,
    SCLNO_SSHOT,
    JH_BROWSER,
    HK_BROWSER,
    DB_VSCODE,
    FP_VSCODE,
    WR_SLACK,
    FS_SLACK
};

combo_t key_combos[COMBO_COUNT] = {
    [JL_TERM] = COMBO_ACTION(CHORD_JL),
    [SCLNO_SSHOT] = COMBO_ACTION(CHORD_SCLNO),
    [JH_BROWSER] = COMBO_ACTION(CHORD_JH),
    [HK_BROWSER] = COMBO_ACTION(CHORD_HK),
    [DB_VSCODE] = COMBO_ACTION(CHORD_DB),
    [FP_VSCODE] = COMBO_ACTION(CHORD_FP),
    [WR_SLACK] = COMBO_ACTION(CHORD_WR),
    [FS_SLACK] = COMBO_ACTION(CHORD_FS)
};

void process_combo_event(uint8_t combo_index, bool pressed) {
      switch(combo_index) {
        case JL_TERM:
            if (pressed) {
                tap_code16(LGUI(LSFT(KC_ENT)));
            }
            break;
        case JH_BROWSER:
        case HK_BROWSER:
            if (pressed) {
                tap_code16(HYPR(KC_ENT));
            }
            break;
        case DB_VSCODE:
        case FP_VSCODE:
            if (pressed) {
                layer_on(_VSCODE);
            } else {
                layer_off(_VSCODE);
            }
            break;
        case FS_SLACK:
        case WR_SLACK:
            if (pressed) {
                tap_code16(MEH(KC_P1));
            }
            break;
        case SCLNO_SSHOT:
            if (pressed) {
                tap_code16(MEH(KC_F14));
            }
            break;
      }
}

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
