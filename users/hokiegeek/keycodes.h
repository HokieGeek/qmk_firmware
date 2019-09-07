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

    TMUX_NEXT,
    TMUX_PREV,
    TMUX_LAST,
    TMUX_PEEK,

    KC_OS_NIX,
    KC_OS_MAC,
    KC_OS_WIN,

    VSC_PROBS,
    VSC_SCM,
    VSC_FIND,
    VSC_TERM,
    VSC_PKDEFS,
    VSC_PKSYMS,
    VSC_G2SYM,
    VSC_RENAME,
    VSC_PALETT,
    VSC_XPLORE,
    VSC_ED_1,

    DYNAMIC_MACRO_RANGE,
    NEW_SAFE_RANGE = DYNAMIC_MACRO_RANGE + 5,
};

#endif // USERSPACE_KEYCODES
