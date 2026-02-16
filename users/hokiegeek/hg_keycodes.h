#ifndef USERSPACE_KEYCODES
#define USERSPACE_KEYCODES

#include "quantum.h"

enum userspace_custom_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,

    QMK_MAKE,

    KC_LATIN,

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
    VSC_TGL_GTST,

    NEW_SAFE_RANGE,
};

#endif // USERSPACE_KEYCODES
