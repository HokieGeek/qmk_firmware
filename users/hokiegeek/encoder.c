#ifndef ENCODER_RESOLUTION
  #define ENCODER_RESOLUTION 4
#endif

// Encoder
static uint8_t  encoder_state  = 0;
static int8_t  encoder_value  = 0;
static int8_t  encoder_LUT[]  = { 0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0 };

__attribute__ ((weak))
void encoder_update(bool clockwise) { }

void check_encoder() {
    encoder_state <<= 2;
    encoder_state |= (palReadPad(GPIOB, 12) << 0) | (palReadPad(GPIOB, 13) << 1);
    encoder_value += encoder_LUT[encoder_state & 0xF];

    // int val = encoder_value;
    if (encoder_value <= -ENCODER_RESOLUTION) { // direction is arbitrary here, but this clockwise
        encoder_update(0);
        // return 1;
    }
    if (encoder_value >= ENCODER_RESOLUTION) {
        encoder_update(1);
        // return -1;
    }
    encoder_value %= ENCODER_RESOLUTION;

    // return 0
}
