#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

#include "latin.h"

#ifdef TAP_DANCE_ENABLE
#include "td_extras.h"
#include "tmux.h"
#ifdef ENCODER_ENABLE
#include "hgencoder.h"
#endif
#endif

// Layer names
#define _QWERTY 0
#define _COLEMAK 1
#define _WORKMAN 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 15

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define SEND_DELAYED(delay, str) send_string_with_delay_P(PSTR(str), delay)

enum userspace_custom_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,

    QMK_MAKE,

    ASCII_SHRUG,

    LATIN_LATCH,
    LATIN_E,
    LATIN_A,
    LATIN_I,
    LATIN_O,
    LATIN_U,
    LATIN_N,
    LATIN_IEXC,
    LATIN_IQS,

#ifdef TAP_DANCE_ENABLE
    TMUX_NEXT,
    TMUX_PREV,
    TMUX_LAST,
    TMUX_PEEK,
#endif

    NEW_SAFE_RANGE,
};

#define LAYOUT_wrapper(...)  LAYOUT(__VA_ARGS__)

#define CSTAB LCTL(LSFT(KC_TAB))

#define __BASE_LCR1__ KC_TRNS
#define __BASE_LCR2__ LT(_ADJUST, KC_ESC)
#define __BASE_LCR3__ LCTL_T(KC_TAB)
#define __BASE_LCR4__ SFT_LAT

#define __BASE_RCR1__ KC_TRNS
#define __BASE_RCR2__ KC_BSPC
#define __BASE_RCR4__ KC_SFTENT

/*
 * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |
 * +------+------+------+------+------+------+------+------+------+------+
 * |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |
 * +------+------+------+------+------|------+------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * +------+------+------+------+------|------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |
 */
#define ______NUMBERS______  LATIN_IEXC,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,    KC_9,    KC_0
#define ______SYMBOLS______  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR,    KC_LPRN, KC_RPRN

/*
 * |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|------+------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------|------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |
 */
#define _____QWERTY_R1_____  KC_Q,  KC_W,  LATIN_E,  KC_R,  KC_T,  KC_Y,  LATIN_U,  LATIN_I,    LATIN_O,    KC_P
#define _____QWERTY_R2_____  LATIN_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,    KC_L,    KC_SCLN,  KC_QUOT
#define _____QWERTY_R3_____  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  LATIN_N,  KC_M,  KC_COMM, KC_DOT,  LATIN_IQS

/*
 * |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  |
 * |------+------+------+------+------|------+------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------|------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |
 */
#define _____COLEMAK_R1_____  KC_Q, KC_W,  KC_F,  KC_P,  KC_G,  KC_J,  KC_L,  LATIN_U,    KC_Y,    KC_SCLN
#define _____COLEMAK_R2_____  LATIN_A, KC_R,  KC_S,  KC_T,  KC_D,  KC_H,  LATIN_N,  LATIN_E,    LATIN_I,    LATIN_O,    KC_QUOT
#define _____COLEMAK_R3_____  KC_Z, KC_X,  KC_C,  KC_V,  KC_B,  KC_K,  KC_M,  KC_COMM, KC_DOT,  LATIN_IQS

#ifdef SWAP_HANDS_ENABLE
#define SWAP_HANDS_ORTHO_5X12_SPLIT { \
  {{5, 5}, {4, 5}, {3, 5}, {2, 5}, {1, 5}, {0, 5}}, \
  {{5, 6}, {4, 6}, {3, 6}, {2, 6}, {1, 6}, {0, 6}}, \
  {{5, 7}, {4, 7}, {3, 7}, {2, 7}, {1, 7}, {0, 7}}, \
  {{5, 8}, {4, 8}, {3, 8}, {2, 8}, {1, 8}, {0, 8}}, \
  {{5, 9}, {4, 9}, {3, 9}, {2, 9}, {1, 9}, {0, 9}}, \
 \
  {{5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}}, \
  {{5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}}, \
  {{5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}}, \
  {{5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3}, {0, 3}}, \
  {{5, 4}, {4, 4}, {3, 4}, {2, 4}, {1, 4}, {0, 4}}, \
}
#endif

#ifdef TAP_DANCE_ENABLE
enum {
    td_encoder = 0,
    td_tmux,
    td_shift_latin,
    TD_SAFE_RANGE
};
#endif

void mousekey_tap(uint8_t);
void key_tap(uint8_t);
void tap_ctltab(void);
void tap_ctltab_td(td_stage);

void userspace_matrix_init_user(void);
void userspace_matrix_scan_user(void);
bool userspace_process_record_user(uint16_t keycode, keyrecord_t *record);

#endif // USERSPACE
