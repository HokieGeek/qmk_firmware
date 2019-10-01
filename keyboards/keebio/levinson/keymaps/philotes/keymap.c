#include QMK_KEYBOARD_H
#include "hokiegeek.h"

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

// | Lower|      |      |      | GUI  |AltSpc|CtlTb | TMUX | ENC  | TERM_VSCODE | MACR |Raise |
#define _____BASE_BOTTOM_____   MO(_LOWER), _______, _______,  _______, GUIBSPC, LALT_T(KC_SPC),     TD(td_ctltab_extras),  KC_TMUX, KC_ENC,  TERM_VSCODE,  KC_SKDM1,  MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.   ,-----------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |Ctl/Tb|   A  |   S  |   D  |   F  |   G  |   |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |SftLat|   Z  |   X  |   C  |   V  |   B  |   |   N  |   M  |   ,  |   .  |   /  |ShEnt |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Lower|      |      |      |GUIBsp|AltSpc|   |CtlTb | TMUX | ENC  |VSCTRM| SKDM |Raise |
 * `-----------------------------------------'   `-----------------------------------------'
 */
[_QWERTY] = LAYOUT_wrapper( \
  __BASE_LCR2__, _____QWERTY_R1_____, __BASE_RCR2__, \
  __BASE_LCR3__, _____QWERTY_R2_____, \
  __BASE_LCR4__, _____QWERTY_R3_____, __BASE_RCR4__, \
  _____BASE_BOTTOM_____ \
),

/* Colemak
 * ,-----------------------------------------.   ,-----------------------------------------.
 * | Esc  |   Q  |   W  |   F  |   P  |   G  |   |   J  |   L  |   U  |   Y  |   ;  |      |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |Ctl/Tb|   A  |   R  |   S  |   T  |   D  |   |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |SftLat|   Z  |   X  |   C  |   V  |   B  |   |   K  |   M  |   ,  |   .  |   /  |ShEnt |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Lower|      |      |      |GUIBsp|AltSpc|   |CtlTb | TMUX | ENC  |VSCTRM| SKDM |Raise |
 * `-----------------------------------------'   `-----------------------------------------'
 */
[_COLEMAK] = LAYOUT_wrapper( \
  __BASE_LCR2__, _____COLEMAK_R1_____, __BASE_RCR2__, \
  __BASE_LCR3__, _____COLEMAK_R2_____, \
  __BASE_LCR4__, _____COLEMAK_R3_____, __BASE_RCR4__, \
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
  _______, _______, _______, _______, _______, _______,      _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______, \
  _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______ \
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

/* VSCODE */
[_VSCODE] = LAYOUT_wrapper( \
  _____VSCODE_R1_____, \
  _____VSCODE_R2_____, \
  _____VSCODE_R3_____, \
  _______,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______  \
),

/* Extras
 * ,-----------------------------------------.   ,-----------------------------------------.
 * |      |      |  7   |  8   |  9   |      |   |      |      |      |      |      |      |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      |      |  4   |  5   |  6   |      |   |      |      |      |      |      |      |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      |      |  1   |  2   |  3   |  0   |   |      |      |      |      |      |      |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |   |      |      |      |      |      |      |
 * `-----------------------------------------'   `-----------------------------------------'
 */
[_EXTRAS] = LAYOUT( \
  _______,  _______, KC_7,    KC_8,    KC_9,    _______,      _______, _______, _______, _______, _______, _______, \
  _______,  _______, KC_4,    KC_5,    KC_6,    _______,      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, \
  _______,  _______, KC_1,    KC_2,    KC_3,    KC_0,         KC_BTN1, KC_BTN3, KC_BTN2, _______, _______, _______, \
  _______,  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______  \
),

/* Adjust
 * ,-----------------------------------------.   ,-----------------------------------------.
 * |QMAKE |QWERTY|COLMAK|RESET |      |      |   |      |      |      |      |      |      |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      |OSNIX |OSMAC |OSWIN |      |      |   |      |      |      |      |      |      |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |   |      |      |      |      |      |      |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |   |      |      |      |      |      |      |
 * `-----------------------------------------'   `-----------------------------------------'
 */
[_ADJUST] = LAYOUT( \
  QMK_MAKE, QWERTY,    COLEMAK,   RESET,     _______, _______,      _______, _______, _______, _______, _______, _______, \
  _______,  KC_OS_NIX, KC_OS_MAC, KC_OS_WIN, _______, _______,      _______, _______, _______, _______, _______, _______, \
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
                tap_key(KC_MUTE);
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
    if (index == 0) {
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
                    tap_key(KC_FIND);
                } else {
                    tap_key(KC_HELP);
                }
            } else {
                if (clockwise) {
                    tap_key(KC_UNDO);
                } else {
                    tap_key(KC_STOP);
                }
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
    TD_SKDM1_ENTRY,
    TD_TERM_VSCODE_ENTRY,
    [td_ctltab_extras] = ACTION_TAP_DANCE_TAP_HOLD(tap_ctltab_td, extras_layer_on_hold)
};
#endif

void matrix_init_user(void) {
    layer_on(_COLEMAK);

    userspace_matrix_init_user();
}

combo_t key_combos[COMBO_COUNT] = {
    COMBO_QA_1,
    COMBO_WR_2,
    COMBO_FS_3,
    COMBO_PT_4,
    COMBO_GD_5,
    COMBO_JH_6,
    COMBO_LN_7,
    COMBO_UE_8,
    COMBO_YI_9,
    COMBO_SCLNO_0,

    COMBO_AZ_EXLM,
    COMBO_RX_AT,
    COMBO_SC_HASH,
    COMBO_TV_DLR,
    COMBO_DB_PERC,
    COMBO_HK_CIRC,
    COMBO_NM_AMPR,
    COMBO_ECOMM_ASTR,
    COMBO_IDOT_LPRN,
    COMBO_OSLSH_RPRN,

    // Qwerty
    COMBO_WS_2,
    COMBO_ED_3,
    COMBO_RF_4,
    COMBO_TG_5,
    COMBO_YH_6,
    COMBO_UJ_7,
    COMBO_IK_8,
    COMBO_OL_9,
    COMBO_PSCLN_0,

    COMBO_SX_AT,
    COMBO_DC_HASH,
    COMBO_FV_DLR,
    COMBO_GB_PERC,
    COMBO_HN_CIRC,
    COMBO_JM_AMPR,
    COMBO_KCOMM_ASTR,
    COMBO_LDOT_LPRN,
    COMBO_SCLNSLSH_RPRN
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return userspace_process_record_user(keycode, record);
}
