#include "hokiegeek.h"
#include <print.h>

#ifndef ENCODER_RESOLUTION
  #define ENCODER_RESOLUTION 4
#endif

// Encoder
static uint8_t  encoder_state  = 0;
static int8_t  encoder_value  = 0;
static int8_t  encoder_LUT[]  = { 0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0 };

__attribute__ ((weak))
void encoder_update(bool clockwise) { }

void check_encoder(void) {
    uint8_t rotaryA = !!(PINB & _BV(PB2));
    uint8_t rotaryB = !!(PINF & _BV(PF4));

    encoder_state <<= 2;
    encoder_state |= rotaryA | rotaryB;
    // TODO encoder_state |= (palReadPad(GPIOB, 12) << 0) | (palReadPad(GPIOB, 13) << 1);
    encoder_value += encoder_LUT[encoder_state & 0xF];

    dprintf("%d\n", encoder_value);

    if (encoder_value <= -ENCODER_RESOLUTION) { // direction is arbitrary here, but this clockwise
        encoder_update(0);
    } else
    if (encoder_value >= ENCODER_RESOLUTION) {
        encoder_update(1);
    // } else {
    //     SEND_STRING("?");
        // register_code(KC_LSFT);
        // register_code(KC_SLASH);
        // unregister_code(KC_SLASH);
        // unregister_code(KC_LSFT);
    }
    encoder_value %= ENCODER_RESOLUTION;
}

void matrix_init_user(void) {
    // JTAG disable for PORT F. write JTD bit twice within four cycles.
    MCUCR |= (1<<JTD);
    MCUCR |= (1<<JTD);

    DDRB &= ~(1 << 2); // Rotary input A -> Pin B2
    DDRF &= ~(1 << 4); // Rotary input B -> Pin F4
}

void matrix_scan_user(void) {
    check_encoder();
}

bool userspace_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // LAYOUTS
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;

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

        // ASCII
        case ASCII_SHRUG:
            if (record->event.pressed) {
                SEND_STRING("¯\\_(ツ)_/¯");
            }
            return false;
            break;

        // RANDOM
        case QMK_MAKE:
            if (record->event.pressed) {
                // Thanks, @drashna!
                SEND_DELAYED(10, "make " QMK_KEYBOARD ":" QMK_KEYMAP
#if  (defined(BOOTLOADER_DFU) || defined(BOOTLOADER_LUFA_DFU) || defined(BOOTLOADER_QMK_DFU))
                   ":dfu"
#elif defined(BOOTLOADER_HALFKAY)
                   ":teensy"
#elif defined(BOOTLOADER_CATERINA)
                   ":avrdude"
#endif // bootloader options
                   SS_TAP(X_ENTER));
            }
            return false;
            break;
    }
    return true;
}
