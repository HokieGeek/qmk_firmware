#include QMK_KEYBOARD_H
#include <print.h>
// #include "hal.h"
// #include "hokiegeek.h"

extern keymap_config_t keymap_config;

enum custom_keycodes {
    foo = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[0] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    foo,    DEBUG,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL, \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  KC_LSFT,  KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT,   KC_SPC,  KC_SPC,  KC_LSFT,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

};

void encoder_update(bool clockwise) {
    /*
    if (clockwise) {
        register_code(KC_F);
        unregister_code(KC_F);
    } else {
        register_code(KC_B);
        unregister_code(KC_B);
    }
    */
}

#ifndef ENCODER_RESOLUTION
  #define ENCODER_RESOLUTION 4
#endif

#define ENC_A PF4
#define ENC_B PB2

/*
 
void setup()
{
  DDRC &= ~(1 << ENC_A);
  DDRB &= ~(1 << ENC_B);
  PORTC |= (1 << ENC_A);
  PORTB |= (1 << ENC_B);
}
 
void loop()
{
 static uint8_t counter = 0;      //this variable will be changed by encoder input
 int8_t tmpdata;
    
  tmpdata = read_encoder();
  if( tmpdata ) {
    counter += tmpdata;
    Serial.print(counter, DEC);
    Serial.print(", ");
    Serial.println(tmpdata == 1 ? "CW" : "CCW");
  }
}
 
int8_t read_encoder()
{ 
  static int8_t enc_states[] = {0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0};
  static uint8_t old_AB2 = 0;

  uint8_t pinB = (PINB & (1 << ENC_B)) >> 1;
  uint8_t pinA = (PINC & (1 << ENC_A)) >> 4;

  old_AB2 <<= 2;                   //remember previous state
  old_AB2 |= ( (pinB) | (pinA) );  //add current state

  int8_t val2 = enc_states[( old_AB2 & 0x0f )];
 */

// Encoder
static uint8_t  encoder_state  = 0;
static int8_t  encoder_value  = 0;
static int8_t  encoder_LUT[]  = { 0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0 };
//                                0  1   2  3  4  5  6  7   8   9  10 11 12 13 14  15

// __attribute__ ((weak))
// void encoder_update(bool clockwise) { }

void check_encoder(void) {
    // static int8_t enc_states[] = {0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0};
    // static uint8_t old_AB2 = 0;

    uint8_t pinB = (PINB & (1 << ENC_B)) >> 1;
    uint8_t pinA = (PINF & (1 << ENC_A)) >> 4;

    encoder_state <<= 2;                   //remember previous state
    encoder_state |= ( (pinB) | (pinA) );  //add current state

    encoder_value += encoder_LUT[( encoder_state & 0x0f )];
    dprintf("value: %u\n", encoder_value);

    /*
    uint8_t rotaryA = (PINB & (1 << PB2));
    uint8_t rotaryB = (PINF & (1 << PF4));

    // dprintf("A: %u B: %u\n", rotaryA, rotaryB);

    encoder_state <<= 2;
    encoder_state |= (rotaryA << 0) | (rotaryB << 1);
    dprintf("state: %u\n", encoder_state & 0xf);
    encoder_value += encoder_LUT[encoder_state & 0xF];
    ////  dprintf("state: %u\n", encoder_state);
    // dprintf("value: %u\n", encoder_value);
    */


    /*
    if (encoder_value <= -ENCODER_RESOLUTION) { // direction is arbitrary here, but this clockwise
        // dprintf("%d\n", encoder_value);
        encoder_update(0);
    } else
    if (encoder_value >= ENCODER_RESOLUTION) {
        // dprintf("%d\n", encoder_value);
        encoder_update(1);
    }
    encoder_value %= ENCODER_RESOLUTION;
    */
}

void matrix_init_user(void) {
    debug_enable = true;

    // JTAG disable for PORT F. write JTD bit twice within four cycles.
    MCUCR |= (1<<JTD);
    MCUCR |= (1<<JTD);

    // DDRB &= ~(1 << 2); // Rotary input A -> Pin B2
    // PORTB |= (1 << 2); // Pull-up pin A
    // DDRF &= ~(1 << 4); // Rotary input B -> Pin F4
    // PORTF |= (1 << 4); // Pull-up pin B
    // DDRB &= ~(1 << PB2); // Rotary input A -> Pin B2
    // DDRF &= ~(1 << PF4); // Rotary input B -> Pin F4
    // PORTB |= (1 << PB2); // Pull-up
    // PORTF |= (1 << PF4); // Pull-u pin
    DDRB &= ~(1 << ENC_B);
    DDRF &= ~(1 << ENC_A);
    PORTB |= (1 << ENC_B);
    PORTF |= (1 << ENC_A);
}

void matrix_scan_user(void) {
    check_encoder();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case foo:
      if (record->event.pressed) {
          dprintf("foo:%s\n", "bar");
        // register_code(KC_A);
        // unregister_code(KC_A);
      }
      return false;
      break;
  }
  return true;
}
