#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "config_common.h"

// Have to define my own pins because my right board doesn't like the other pin I guess...
// #undef MATRIX_ROW_PINS
// #define MATRIX_ROW_PINS { D4, B2, E6, B4, B5 }
// #define MATRIX_ROW_PINS_RIGHT { D4, D7, E6, B4, B5 }

// #undef MASTER_LEFT
// #define MASTER_RIGHT

#define ACCENTS_LINUX

#undef RGBLED_NUM
#define RGBLED_NUM 20

#define NUMBER_OF_ENCODERS 1
#define ENCODERS_PAD_A { B2 }
#define ENCODERS_PAD_B { F4 }

#endif
