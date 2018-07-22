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

#define SEND_TMUX(c) SEND_STRING(SS_LCTRL("a")c);

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

    NEW_SAFE_RANGE,
};

bool userspace_process_record_user(uint16_t keycode, keyrecord_t *record);

#endif
