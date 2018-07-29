#include "hokiegeek.h"

bool userspace_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // ACCENTS
        case LATIN_E:
        case LATIN_A:
        case LATIN_I:
        case LATIN_O:
        case LATIN_U:
        case LATIN_N:
        case LATIN_IEXC:
        case LATIN_IQS:
            if (record->event.pressed) {
                switch (keycode) {
                case LATIN_E:       SEND_LATIN(LATIN_E_STRING); break;
                case LATIN_A:       SEND_LATIN(LATIN_A_STRING); break;
                case LATIN_I:       SEND_LATIN(LATIN_I_STRING); break;
                case LATIN_O:       SEND_LATIN(LATIN_O_STRING); break;
                case LATIN_U:       SEND_LATIN(LATIN_U_STRING); break;
                case LATIN_N:       SEND_LATIN(LATIN_N_STRING); break;
                case LATIN_IEXC:    SEND_LATIN(LATIN_IEXC_STRING); break;
                case LATIN_IQS:     SEND_LATIN(LATIN_IQS_STRING); break;
                }
            }
            return false;
            break;

        // TMUX
        case TMUX_NEXT:
        case TMUX_PREV:
        case TMUX_LAST:
            if (record->event.pressed) {
                switch (keycode) {
                case TMUX_NEXT: SEND_TMUX("n"); break;
                case TMUX_PREV: SEND_TMUX("p"); break;
                case TMUX_LAST: SEND_TMUX(SS_LCTRL("a")); break;
                }
            }
            return false;
            break;
        case TMUX_PEEK:
            SEND_TMUX(SS_LCTRL("a"))
            return false;
            break;

        // EMOJI
        case EMOJI_SHRUG:
            if (record->event.pressed) {
                SEND_STRING("¯\\_(ツ)_/¯");
            }
            return false;
            break;
    }
    return true;
}
