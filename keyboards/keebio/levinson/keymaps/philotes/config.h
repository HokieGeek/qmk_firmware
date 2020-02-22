#pragma once

// #define SPLIT_USB_DETECT

#undef SPLIT_HAND_PIN
#undef MASTER_LEFT
#define EE_HANDS

#define ENCODERS_PAD_A { F5 }
#define ENCODERS_PAD_B { F4 }

// Fixing bad row pin in left-hand Elite C
#undef MATRIX_ROW_PINS // { D4, D7, E6, B4 }
#define MATRIX_ROW_PINS { D4, D7, B7, B4 }
#define MATRIX_ROW_PINS_RIGHT { D4, D7, E6, B4 }

// Fixing bad column pin in left-hand Elite C
#undef MATRIX_COL_PINS // { F6, F7, B1, B3, B2, B6 }
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2, F0 }
#define MATRIX_COL_PINS_RIGHT { F6, F7, B1, B3, B2, B6 }

#define COMBO_COUNT 8

#undef RGBLED_NUM
#undef RGBLED_SPLIT
#define RGBLED_NUM 12
#define RGBLED_SPLIT { RGBLED_NUM / 2, RGBLED_NUM / 2 }
#define RGBLIGHT_HUE_STEP 14
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17
#undef RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_CHRISTMAS
// #define RGBLIGHT_EFFECT_STATIC_GRADIENT
// #define RGBLIGHT_EFFECT_RAINBOW_MOOD
// #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// #define RGBLIGHT_EFFECT_SNAKE
