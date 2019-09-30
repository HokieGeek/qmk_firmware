#include QMK_KEYBOARD_H
#include "hokiegeek.h"

extern keymap_config_t keymap_config;

#define _SHORTS 5
#define _YABAI 6
// #define _CAMTASIA 7

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
    td_ctltab_shorts,
    td_bscp_yabai
};
#define MAC_NOTIFS TD(td_mac_notif)
#define CTLTAB_SHORTS TD(td_ctltab_shorts)
#define TERM_VSCODE TD(td_terminal_vscode)
#else
#define MAC_NOTIFS G(S(KC_GRAVE))
#define CTLTAB_SHORTS LCTL(KC_TAB)
#define TERM_VSCODE G(S(KC_ENT))
#endif
#define BSCP_YABAI LT(_YABAI, KC_BSPC)
#define GUIBSPC LGUI_T(KC_BSPC)

#define SEND_APP_FRONT(app)   SEND_DELAYED(50, SS_LGUI(SS_TAP(X_SPACE)) app SS_TAP(X_ENTER))
#define SEND_SLACK_SLASH(str) SEND_DELAYED(50, SS_TAP(X_SLASH) str SS_TAP(X_TAB))
#define SEND_SLACK_REACT(str) SEND_DELAYED(30, SS_LGUI(SS_LSFT(SS_TAP(X_BSLASH))) str SS_TAP(X_ENTER))
#define SEND_SLACK_GOTO(str)  SEND_DELAYED(50, SS_LGUI(SS_TAP(X_K)) str SS_TAP(X_ENTER))

#undef __BASE_RCR2__
#define __BASE_RCR2__ MAC_NOTIFS

/*
#define _____BASE_TOP_____     _______, MEH(KC_F14), _______, _______, _______, _______,   _______, _______, _______, MEH(KC_F19), MEH(KC_F20), _______
*/
#define _____BASE_BOTTOM_____  MO(_LOWER),                KC_ENC,  GUIBSPC, LALT_T(KC_SPC),          CTLTAB_SHORTS,  KC_TMUX, _______,                   MO(_RAISE)
#define _____BASE_THUMBS_____  KC_F13,  MO(_YABAI),               TERM_VSCODE, MEH(KC_P1)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.     ,-----------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |     |   Y  |   U  |   I  |   O  |   P  |NOTIF |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |Ctl/Tb|   A  |   S  |   D  |   F  |   G  |     |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |Sftlat|   Z  |   X  |   C  |   V  |   B  |     |   N  |   M  |   ,  |   .  |   /  |ShEnt |
 * |------+-------------+------+------+------|     |------+------+--------------------+------|
 * | Lower|             | ENC  | GUI  |AltSpc|     |CtlTb | TMUX |                    |Raise |
 * `------'             `------+------+------|     |------+------|                    `------'
 *                             | DEMO |YABAI |     |SLACK |VSCODE|
 *                             `-------------'     `-------------'
 */
[_QWERTY] = LAYOUT_wrapper(
  __BASE_LCR2__, _____QWERTY_R1_____, __BASE_RCR2__, \
  __BASE_LCR3__, _____QWERTY_R2_____, \
  __BASE_LCR4__, _____QWERTY_R3_____, __BASE_RCR4__, \
  _____BASE_BOTTOM_____, \
  _____BASE_THUMBS_____ \
  ),

/* Colemak
 * ,-----------------------------------------.     ,-----------------------------------------.
 * | Esc  |   Q  |   W  |   F  |   P  |   G  |     |   J  |   L  |   U  |   Y  |   ;  |NOTIF |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |Ctl/Tb|   A  |   R  |   S  |   T  |   D  |     |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |Sftlat|   Z  |   X  |   C  |   V  |   B  |     |   K  |   M  |   ,  |   .  |   /  |ShEnt |
 * |------+-------------+------+------+------|     |------+------+--------------------+------|
 * | Lower|             | ENC  | GUI  |AltSpc|     |CtlTb | TMUX |                    |Raise |
 * `------'             `------+------+------|     |------+------|                    `------'
 *                             | DEMO |YABAI |     |SLACK |VSCODE|
 *                             `-------------'     `-------------'
 */
[_COLEMAK] = LAYOUT_wrapper(
  __BASE_LCR2__, _____COLEMAK_R1_____, __BASE_RCR2__, \
  __BASE_LCR3__, _____COLEMAK_R2_____, \
  __BASE_LCR4__, _____COLEMAK_R3_____, __BASE_RCR4__, \
  _____BASE_BOTTOM_____, \
  _____BASE_THUMBS_____ \
),

/* Lower
 * ,-----------------------------------------.     ,-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |     |   ^  |   &  |   *  |   (  |   )  |  =   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     | Home | PgDn | PgUp | End  |   -  |  |   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |  {   |  }   |  [   |  ]   |      |
 * |------+-------------+------+------+------|     |------+------+--------------------+------|
 * |      |             |      |      |      |     |      |      |                    |      |
 * `------'             `------+------+------|     |------+------|                    `------'
 *                             |      |YABSTR|     |      |      |
 *                             `-------------'     `-------------'
 */
[_LOWER] = LAYOUT_wrapper(
  KC_TILD,                                      ______SYMBOLS______,                                         KC_EQL, \
  KC_CAPS, _______, _______, _______, _______, _______,         KC_HOME,     KC_PGDN, KC_PGUP, KC_END,  KC_MINS, KC_PIPE, \
  _______, _______, _______, _______, _______, _______,         _______,     KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______, \
  _______,                   _______, _______, _______,         _______,     _______, _______,                   _______, \
                                  MEH(KC_F13), MEH(KC_F15),     MEH(KC_P3), _______
),

/* Raise
 * ,-----------------------------------------.     ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |     |   6  |   7  |   8  |   9  |   0  |   +  |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     | Left | Down |  Up  |Right |   _  |  \   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |     |  F7  |  F8  |  F9  |  F10 | F11  | F12  |
 * |------+-------------+------+------+------|     |------+------+--------------------+------|
 * |      |             |      |      |      |     |CSTAB | TX_P |                    |      |
 * `------'             `------+------+------|     |------+------|                    `------'
 *                             |      |YABSTP|     |      |      |
 *                             `-------------'     `-------------'
 */
[_RAISE] = LAYOUT_wrapper(
  KC_GRAVE,                                     ______NUMBERS______,                                              KC_PLUS, \
  _______, _______, _______, _______, _______, _______,         KC_LEFT,     KC_DOWN,   KC_UP,    KC_RGHT,  KC_UNDS,  KC_BSLS, \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,           KC_F7,       KC_F8,     KC_F9,    KC_F10,   KC_F11,   KC_F12, \
  _______,                   _______, _______, _______,         CSTAB,       TMUX_PREV, _______,                      _______, \
                                 HYPR(KC_F13), HYPR(KC_F15),    MEH(KC_P2), _______
),

/* shortcuts
 * ,-----------------------------------------.     ,-----------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |SSHRUG|SGIPHY|SRCTMB|SRCTHS|SRCTHI|SREACT|
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+-------------+------+------+------|     |------+------+--------------------+------|
 * |      |             |      |      |      |     |      |      |                    |      |
 * `------'             `------+------+------|     |------+------|                    `------'
 *                             |      |      |     |      |      |
 *                             `-------------'     `-------------'
 */
[_SHORTS] = LAYOUT_wrapper(
  _______, _______, _______, _______, _______, _______,     _______,     _______,     _______,     _______,     _______,     _______, \
  _______, _______, _______, _______, _______, _______,     SLACK_SHRUG, SLACK_GIPHY, SLACK_RCTMB, SLACK_RCTHS, SLACK_RCHI5, SLACK_REACT, \
  _______, _______, _______, _______, _______, _______,     _______,     _______,     _______,     _______,     _______,     _______, \
  _______,                   _______, _______, _______,     _______,     _______,     _______,                               _______, \
                                      _______, _______,     _______,     _______
),

/* yabai
 * ,-----------------------------------------.     ,-----------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+-------------+------+------+------|     |------+------+--------------------+------|
 * |      |             |      |      |      |     |      |      |                    |      |
 * `------'             `------+------+------|     |------+------|                    `------'
 *                             |      |      |     |      |      |
 *                             `-------------'     `-------------'
 */
[_YABAI] = LAYOUT_wrapper(
  _______,     LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4),   LGUI(KC_5),       LGUI(KC_6),  LGUI(KC_7),  LGUI(KC_8), LGUI(KC_9), LGUI(KC_0), _______, \
  MEH(KC_TAB), _______,    _______,    _______,    LGUI(KC_SPC), _______,          _______,     _______,     _______,    _______,    _______,    _______, \
  _______,     _______,    _______,    _______,    MEH(KC_V),    _______,          _______,     _______,     _______,    _______,    _______,    _______, \
  _______,                             _______,    _______,      LCAG(KC_SPC),     _______,     _______,     _______,                            _______, \
                                                   _______,      _______,          _______,     _______
),

/* camtasia
 * ,-----------------------------------------.     ,-----------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+-------------+------+------+------|     |------+------+--------------------+------|
 * |      |             |      |      |      |     |      |      |                    |      |
 * `------'             `------+------+------|     |------+------|                    `------'
 *                             |      |      |     |      |      |
 *                             `-------------'     `-------------'
 */
/*
[_CAMTASIA] = LAYOUT_wrapper(
  // LSFT(LGUI(KC_2)), LALT(LGUI(KC_2)),  KC_2,
  _______, _______, _______, _______  _______, _______,     _______,     _______,     _______,     _______,     _______,     _______, \
  _______, _______, _______, _______, _______, _______,     _______,     _______,     _______,     _______,     _______,     _______, \
  _______, _______, _______, _______, _______, _______,     _______,     _______,     _______,     _______,     _______,     _______, \
  _______,                   _______, _______, _______,     _______,     _______,     _______,                               _______, \
                                      _______, _______,     _______,     _______
),
*/

// vscode
[_VSCODE] = LAYOUT_wrapper(
  _____VSCODE_R1_____, \
  _____VSCODE_R2_____, \
  _____VSCODE_R3_____, \
  _______,                   _______, _______, _______,     _______, _______, _______,                   _______, \
                                      _______, _______,     _______, _______
),

/* Adjust
 * ,-----------------------------------------.     ,-----------------------------------------.
 * |QMAKE |QWERTY|COLMAK|RESET |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |OSNIX |OSMAC |OSWIN |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+-------------+------+------+------|     |------+------+--------------------+------|
 * |      |             |      |      |      |     |      |      |                    |      |
 * `------'             `------+------+------|     |------+------|                    `------'
 *                             |      |      |     |      |      |
 *                             `-------------'     `-------------'
 */
[_ADJUST] = LAYOUT_wrapper(
  QMK_MAKE, QWERTY,    COLEMAK,   RESET,     _______, _______,     _______, _______, _______, _______, _______, _______,
  _______,  KC_OS_NIX, KC_OS_MAC, KC_OS_WIN, _______, _______,     _______, _______, _______, _______, _______, _______,
  _______,  _______,   _______,   _______,   _______, _______,     _______, _______, _______, _______, _______, _______,
  _______,                        _______,   _______, _______,     _______, _______, _______,                   _______,
                                             _______, _______,     _______, _______
)
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
                tap_key(KC_MUTE);
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
            // if (enc_opts.backlightBrightness) {
            //     if (clockwise) {
            //         backlight_increase();
            //     } else {
            //         backlight_decrease();
            //     }
            // }
        } else if (IS_LAYER_ON(_LOWER)) {
            if (enc_opts.monBrightness) {
                if (clockwise) {
                    tap_key(KC_BRMU);
                } else {
                    tap_key(KC_BRMD);
                }
            // } else {
            //     if (clockwise) {
            //         tap_key(KC_UNDO);
            //     } else {
            //         tap_key(KC_STOP);
            //     }
            }
        } else if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                tap_mod_key(KC_LCTL, KC_KP_PLUS);
            } else {
                tap_mod_key(KC_LCTL, KC_KP_MINUS);
            }
        } else { // Default layers
            if (enc_opts.defaultVolume) {
                if (clockwise) {
                    tap_key(KC_VOLU);
                } else {
                    tap_key(KC_VOLD);
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
void td_notifs(td_stage stage) {
    td_key(stage, KC_F18);
}
void td_no_notif(td_stage stage) {
    if (stage == TD_FINISHED) {
        SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_GRAVE))));
    }
}
void shorts_layer_on_hold(td_stage stage) {
    switch (stage) {
        case TD_FINISHED: layer_on(_SHORTS); break;
        case TD_RESET: layer_off(_SHORTS); break;
        default: break;
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
#ifdef ENCODER_ENABLE
    TD_ENCODER_ENTRY,
#endif
    TD_TMUX_ENTRY,
    TD_SHIFT_LATIN,
    TD_TERM_VSCODE_ENTRY,
    [td_mac_notif] = ACTION_TAP_DANCE_DOUBLE_FUNCS(td_notifs, td_no_notif),
    [td_ctltab_shorts] = ACTION_TAP_DANCE_TAP_HOLD(tap_ctltab_td, shorts_layer_on_hold)
};
#endif

void matrix_init_user(void) {
    setTargetOS(OS_MAC);

    layer_on(_COLEMAK);

    userspace_matrix_init_user();
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }

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
