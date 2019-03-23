#include QMK_KEYBOARD_H
#include "hokiegeek.h"

extern keymap_config_t keymap_config;

#define _SHORTS 5
#define _CHUNKWM 6

enum custom_keycodes {
    SLACK_GIPHY = NEW_SAFE_RANGE,
    SLACK_SHRUG,
    SLACK_REACT,
    SLACK_RCTMB,
    SLACK_RCTHS,
    SLACK_RCHI5,
    SLACK_G2SEW,
    SLACK_G2ISE,
    SLACK_G2ISU,
    SLACK_G2LNG,

    SF_SE
};

#ifdef TAP_DANCE_ENABLE
enum {
    td_mute_notif = TD_SAFE_RANGE,
    td_ctltab_shorts,
    td_bscp_chunkwm
};
#define MUTER TD(td_mute_notif)
#define CTLTAB_SHORTS TD(td_ctltab_shorts)
#else
#define MUTER KC_MUTE
#define CTLTAB_SHORTS LCTL(KC_TAB)
#endif
#define BSCP_CHUNKWM LT(_CHUNKWM, KC_BSPC)

#define SEND_APP_FRONT(app)   SEND_DELAYED(50, SS_LGUI(SS_TAP(X_SPACE)) app SS_TAP(X_ENTER))
#define SEND_SLACK_SLASH(str) SEND_DELAYED(50, SS_TAP(X_SLASH) str SS_TAP(X_TAB))
#define SEND_SLACK_REACT(str) SEND_DELAYED(30, SS_LGUI(SS_LSFT(SS_TAP(X_BSLASH))) str SS_TAP(X_ENTER))
#define SEND_SLACK_GOTO(str)  SEND_DELAYED(50, SS_LGUI(SS_TAP(X_K)) str SS_TAP(X_ENTER))

#define _____BASE_TOP_____     KC_F13, MEH(KC_F14), _______, _______, _______, _______,   MEH(KC_F15), MEH(KC_F16), _______, _______, _______, _______
#define _____BASE_BOTTOM_____  TT(_LOWER),  _______, KC_ENC,  KC_LGUI,   BSCP_CHUNKWM,  LALT_T(KC_SPC),       CTLTAB_SHORTS,  KC_TMUX,  MUTER,  _______,   KC_SKDM1,  TT(_RAISE)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,------------------------------------------     ------------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |     |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------     -------+------+------+------+------+------|
 * |Ctl/Tb|   A  |   S  |   D  |   F  |   G  |     |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |Sftlat|   Z  |   X  |   C  |   V  |   B  |     |   N  |   M  |   ,  |   .  |   /  |ShEnt |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * | Lower|      |      |      | GUI  |AltSpc|     |CtlTb | TMUX | MUTE |      | MACR |Raise |
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
 * | Esc  |   Q  |   W  |   F  |   P  |   G  |     |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------     -------+------+------+------+------+------|
 * |Ctl/Tb|   A  |   R  |   S  |   T  |   D  |     |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |Sftlat|   Z  |   X  |   C  |   V  |   B  |     |   K  |   M  |   ,  |   .  |   /  |ShEnt |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * | Lower|      |      |      | GUI  |AltSpc|     |CtlTb | TMUX | MUTE |      | MACR |Raise |
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
 * |   ~  |   !  |   @  |   #  |   $  |   %  |     |   ^  |   &  |   *  |   (  |   )  |  =   |
 * |------+------+------+------+------+-------     -------+------+------+------+------+------|
 * |      |      |      |      |      |      |     | Home | PgDn | PgUp | End  |   -  |  |   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |  {   |  }   |  [   |  ]   |      |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * |      |      |      |      | BSPC |      |     |      |      | Vol- |      |      |      |
 * `------------------------------------------     ------------------------------------------'
 */
[_LOWER] = LAYOUT_wrapper( \
  MEH(KC_F13),  _______,  _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______,  KC_VOLD, \
  KC_TILD,                                              ______SYMBOLS______,                                            KC_EQL, \
  _______,      _______,  _______,  _______,  _______,  _______,      KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_MINS,  KC_PIPE, \
  _______,      _______,  _______,  _______,  _______,  _______,      _______,  KC_LCBR,  KC_RCBR,  KC_LBRC,  KC_RBRC,  _______, \
  _______,      _______,  _______,  _______,  KC_BSPC,  _______,      _______,  _______,  KC_VOLD,  _______,  _______,  _______ \
),

/* Raise
 * ,------------------------------------------     ------------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+-------     +------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |     |   6  |   7  |   8  |   9  |   0  |   +  |
 * |------+------+------+------+------+-------     -------+------+------+------+------+------|
 * |      |      |      |      |      |      |     | Left | Down |  Up  |Right |   _  |  \   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |     |  F7  |  F8  |  F9  |  F10 | F11  | F12  |
 * |------+------+------+------+------+------+     +------+------+------+------+------+------|
 * |      |      |      |      | BSPC |      |     |CSTAB | TX_P | Vol+ |      | MREC |      |
 * `------------------------------------------     ------------------------------------------'
 */
[_RAISE] = LAYOUT_wrapper( \
  HYPR(KC_F13),  _______,  _______,  _______,  _______,  _______,      _______,  _______,    _______,  _______,  _______,  _______, \
  KC_GRAVE,                                              ______NUMBERS______,                                              KC_PLUS, \
  _______,       _______,  _______,  _______,  _______,  _______,      KC_LEFT,  KC_DOWN,    KC_UP,    KC_RGHT,  KC_UNDS,  KC_BSLS, \
  KC_F1,         KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,        KC_F7,    KC_F8,      KC_F9,    KC_F10,   KC_F11,   KC_F12, \
  _______,       _______,  _______,  _______,  KC_BSPC,  _______,      CSTAB,    TMUX_PREV,  KC_VOLU,  _______,  _______,  _______ \
),

/* Shortcuts
 * ,------------------------------------------     ------------------------------------------.
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |SF_SE |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |SSHRUG|SGIPHY|SRCTMB|SRCTHS|SRCTHI|SREACT|
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |SG2SEW|SG2LNG|SG2ISE|SG2ISU|      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |      |      |      |      |      |      |
 * `------------------------------------------     ------------------------------------------'
 */
[_SHORTS] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,      _______,     _______,     _______,     _______,     _______,     _______, \
  _______, _______, _______, _______, _______, _______,      SF_SE,       _______,     _______,     _______,     _______,     _______, \
  _______, _______, _______, _______, _______, _______,      SLACK_SHRUG, SLACK_GIPHY, SLACK_RCTMB, SLACK_RCTHS, SLACK_RCHI5, SLACK_REACT, \
  _______, _______, _______, _______, _______, _______,      SLACK_G2SEW, SLACK_G2LNG, SLACK_G2ISE, SLACK_G2ISU, _______,     _______, \
  _______, _______, _______, _______, _______, _______,      _______,     _______,     _______,     _______,     _______,     _______  \
),

/* chunkwm
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
[_CHUNKWM] = LAYOUT( \
  _______,     _______,    _______,    _______,    _______,       _______,            _______,    _______,    _______,    _______,    _______,    _______, \
  _______,     LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4),    LGUI(KC_5),         LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), LGUI(KC_0), _______, \
  MEH(KC_TAB), _______,    _______,    _______,    LGUI(KC_SPC),  _______,            MEH(KC_H),  S(C(KC_N)), S(C(KC_E)), MEH(KC_I),  _______,    _______, \
  _______,     _______,    _______,    _______,    MEH(KC_V),     _______,            _______,    MEH(KC_M),  _______,    _______,    _______,    LGUI(KC_ENTER), \
  _______,     _______,    _______,    _______,    _______,       LCAG(KC_SPC),       _______,    _______,    _______,    _______,    _______,    _______  \
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
  _______,   _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
  _______,   QWERTY,  COLEMAK, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
  KC_CAPS,   _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
  QMK_MAKE,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
  _______,   _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______  \
),

};

#ifdef SWAP_HANDS_ENABLE
// Each half duplicates the other half
const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = SWAP_HANDS_ORTHO_5X12_SPLIT;
#endif

#if defined(TAP_DANCE_ENABLE) && defined(ENCODER_ENABLE)
void encoder_td_actions (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (IS_LAYER_ON(_ADJUST)) {
            // TODO
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
            /*
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
            */
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
    [td_mute_notif] = ACTION_TAP_DANCE_DOUBLE_FUNCS(td_mute, td_no_notif),
    [td_ctltab_shorts] = ACTION_TAP_DANCE_TAP_HOLD(tap_ctltab_td, shorts_layer_on_hold)
};
#endif

void matrix_init_user(void) {
    layer_on(_COLEMAK);

    userspace_matrix_init_user();
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
        case SLACK_G2SEW:
        case SLACK_G2ISE:
        case SLACK_G2ISU:
        case SLACK_G2LNG:
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
                case SLACK_G2SEW: SEND_SLACK_GOTO("se-world"); break;
                case SLACK_G2ISE: SEND_SLACK_GOTO("ises"); break;
                case SLACK_G2ISU: SEND_SLACK_GOTO("inside-sales-us"); break;
                case SLACK_G2LNG: SEND_SLACK_GOTO("the-lounge"); break;
                }
            }
            return false;
            break;
        case SF_SE:
            if (record->event.pressed) {
                switch (keycode) {
                    case SF_SE: SEND_DELAYED(10, "#Sales Engineer"); break;
                }
                SEND_STRING(SS_TAP(X_ENTER));
            }
            return false;
            break;
    }

    return userspace_process_record_user(keycode, record);
}
