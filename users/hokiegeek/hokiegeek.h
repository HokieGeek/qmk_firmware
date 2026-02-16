#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

#ifdef TAP_DANCE_ENABLE
#include "td_extras.h"
#include "tmux.h"
#ifdef DYNAMIC_MACRO_ENABLE
#include "skdm.h"
#else
#define KC_SKDM1 KC_NO
#define KC_SKDM2 KC_NO
#endif
#else
#define TD(n) KC_NO
#define KC_TMUX KC_NO
#define KC_SKDM1 KC_NO
#define KC_SKDM2 KC_NO
#endif

#ifdef ENCODER_ENABLE
#include "hgencoder.h"
#else
#define KC_ENC KC_NO
#endif

#ifdef COMBO_ENABLE
#include "combos.h"
#endif

#include "os.h"
#include "vscode.h"
#include "latin.h"
#include "hg_keycodes.h"

// Layer names
#define _COLEMAK 0
#define _QWERTY 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 15

// Fillers to make layering more clear
#define KC_TRNS KC_TRANSPARENT
#define XXXXXXX KC_NO

#define SEND_DELAYED(delay, str) send_string_with_delay_P(PSTR(str), delay)

#define LAYOUT_wrapper(...)  LAYOUT(__VA_ARGS__)

#define CSTAB LCTL(LSFT(KC_TAB))
#define GUIBSPC LGUI_T(KC_BSPC)
#define GUIDEL LGUI_T(KC_DELETE)
#define ALTPSCR LALT(KC_PSCR)

#define __BASE_LCR1__ KC_TRNS
#define __BASE_LCR2__ KC_ESC
#define __BASE_LCR3__ LCTL_T(KC_TAB)
#define __BASE_LCR4__ SFT_LAT

#define __BASE_RCR1__ KC_TRNS
#define __BASE_RCR2__ KC_SKDM1
#define __BASE_RCR4__ SC_SENT

// * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |
#define ______NUMBERS______  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0
// * |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   +  |   =  |
#define ______SYMBOLS______  KC_EXLM, KC_AT, KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR, KC_PLUS, KC_EQL

/*
 * |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|------+------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------|------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |
 */
#define _____QWERTY_R1_____  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,    KC_O,    KC_P
#define _____QWERTY_R2_____  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,    KC_L,    KC_SCLN,  KC_QUOT
#define _____QWERTY_R3_____  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH

/*
 * |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  |
 * |------+------+------+------+------|------+------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------|------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |
 */
#define _____COLEMAK_R1_____  KC_Q, KC_W,  KC_F,  KC_P,  KC_G,  KC_J,  KC_L,  KC_U,    KC_Y,    KC_SCLN
#define _____COLEMAK_R2_____  KC_A, KC_R,  KC_S,  KC_T,  KC_D,  KC_H,  KC_N,  KC_E,    KC_I,    KC_O,    KC_QUOT
#define _____COLEMAK_R3_____  KC_Z, KC_X,  KC_C,  KC_V,  KC_B,  KC_K,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH

enum {
#ifdef TAP_DANCE_ENABLE
    td_encoder = 0,
    td_tmux,
    td_shift_latin,
#ifdef DYNAMIC_MACRO_ENABLE
    td_skdm1,
    td_skdm2,
#endif
#endif
    TD_SAFE_RANGE
};

void tap_mousekey(uint8_t);

void userspace_matrix_init_user(void);
bool userspace_process_record_user(uint16_t keycode, keyrecord_t *record);

#endif // USERSPACE
