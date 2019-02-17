#include "quantum.h"
#include "hgencoder.h"

// Encoder
static uint8_t  encoder_state  = 0;
static int8_t   encoder_value  = 0;
static int8_t   encoder_LUT[]  = { 0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0 };

__attribute__ ((weak))
void encoder_update(bool clockwise) { }

void check_encoder(void) {
    uint8_t pinB = (PINB & (1 << ENC_B)) >> 1;
    uint8_t pinA = (PINF & (1 << ENC_A)) >> 4;

    encoder_state <<= 2;                   //remember previous state
    encoder_state |= ( (pinB) | (pinA) );  //add current state
    encoder_value += encoder_LUT[( encoder_state & 0x0f )];

    if (encoder_value <= -ENCODER_RESOLUTION) {
        encoder_update(false);
    }
    if (encoder_value >= ENCODER_RESOLUTION) {
        encoder_update(true);
    }
    encoder_value %= ENCODER_RESOLUTION;
}
