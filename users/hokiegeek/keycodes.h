#ifndef USERSPACE_KEYCODES
#define USERSPACE_KEYCODES

#include "quantum.h"

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

    DYNAMIC_MACRO_RANGE,
    NEW_SAFE_RANGE = DYNAMIC_MACRO_RANGE + 5,
};

#endif // USERSPACE_KEYCODES
