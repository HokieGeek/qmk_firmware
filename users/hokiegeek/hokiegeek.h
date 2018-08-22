#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

// Layer names
#define _BASE 0
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

#define TMUX_PREFIX "a"
#define SEND_TMUX(c) SEND_STRING(SS_LCTRL(TMUX_PREFIX)c);

#define SEND_DELAYED(delay, str) send_string_with_delay_P(PSTR(str), delay)

enum userspace_custom_keycodes {
    LATIN_E = SAFE_RANGE,
    LATIN_A,
    LATIN_I,
    LATIN_O,
    LATIN_U,
    LATIN_N,
    LATIN_IEXC,
    LATIN_IQS,

    TMUX_NEXT,
    TMUX_PREV,
    TMUX_LAST,
    TMUX_PEEK,

    ASCII_SHRUG,

    QMK_MAKE,

    NEW_SAFE_RANGE,
};

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
#define _____QWERTY_R1_____  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,    KC_O,    KC_P
#define _____QWERTY_R2_____  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,    KC_L,    KC_SCLN,  KC_QUOT
#define _____QWERTY_R3_____  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH

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


bool userspace_process_record_user(uint16_t keycode, keyrecord_t *record);

#endif
