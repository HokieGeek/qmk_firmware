#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

#include "encoder.h"
#include "tmux.h"

// Layer names
#define _QWERTY 0
#define _COLEMAK 1
#define _WORKMAN 2
#define _LOWER 3
#define _RAISE 4

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Accent defines
#ifdef ACCENTS_MAC
#define LATIN_E_STRING SS_LALT("e")"e"
#define LATIN_A_STRING SS_LALT("e")"a"
#define LATIN_I_STRING SS_LALT("e")"i"
#define LATIN_O_STRING SS_LALT("e")"o"
#define LATIN_U_STRING SS_LALT("e")"u"
#define LATIN_N_STRING SS_LALT("n")"n"
#define LATIN_IEXC_STRING SS_LALT("1")
#define LATIN_IQS_STRING SS_LALT("?")
#define SEND_LATIN(str) SEND_STRING(str)
#else
#define LATIN_E_STRING    SS_TAP(X_E)SS_TAP(X_9)
#define LATIN_A_STRING    SS_TAP(X_E)SS_TAP(X_1)
#define LATIN_I_STRING    SS_TAP(X_E)SS_TAP(X_D)
#define LATIN_O_STRING    SS_TAP(X_F)SS_TAP(X_3)
#define LATIN_U_STRING    SS_TAP(X_F)SS_TAP(X_A)
#define LATIN_N_STRING    SS_TAP(X_F)SS_TAP(X_1)
#define LATIN_IEXC_STRING SS_TAP(X_A)SS_TAP(X_1)
#define LATIN_IQS_STRING  SS_TAP(X_B)SS_TAP(X_F)
#define SEND_LATIN(str) SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LSHIFT)SS_TAP(X_U)SS_TAP(X_0)SS_TAP(X_0) str SS_UP(X_LCTRL)SS_UP(X_LSHIFT));
#endif

#define SEND_DELAYED(delay, str) send_string_with_delay_P(PSTR(str), delay)

enum userspace_custom_keycodes {
    QWERTY = TMUX_SAFE_RANGE,
    COLEMAK,

    LATIN_E,
    LATIN_A,
    LATIN_I,
    LATIN_O,
    LATIN_U,
    LATIN_N,
    LATIN_IEXC,
    LATIN_IQS,

    ASCII_SHRUG,

    QMK_MAKE,

    NEW_SAFE_RANGE,
};

#define LAYOUT_wrapper(...)  LAYOUT(__VA_ARGS__)

#define __BASE_LCR1__ KC_GESC
#define __BASE_LCR2__ KC_TAB
#define __BASE_LCR3__ LCTL_T(KC_TAB)
#define __BASE_LCR4__ KC_LSFT

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
#define ______NUMBERS______  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,    KC_9,    KC_0

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

void mousekey_tap(uint8_t);
void key_tap(uint8_t);

typedef enum {
    OTHER = 0,
    SINGLE = 1,
    DOUBLE = 2,
    TRIPLE = 3,
    SINGLE_HOLD = 4,
    DOUBLE_HOLD = 5,
    TRIPLE_HOLD = 6
} td_state;
td_state process_td_state(qk_tap_dance_state_t *state, void *user_data);

void userspace_matrix_init_user(void);
void userspace_matrix_scan_user(void);
bool userspace_process_record_user(uint16_t keycode, keyrecord_t *record);

#endif // USERSPACE
