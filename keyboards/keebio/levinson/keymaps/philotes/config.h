#pragma once

#undef SPLIT_HAND_PIN
#undef MASTER_LEFT
#define EE_HANDS

#define ENCODERS_PAD_A { F4 }
#define ENCODERS_PAD_B { F5 }

// Fixing bad row pin in left-hand Elite C
#undef MATRIX_ROW_PINS // { D4, D7, E6, B4 }
#define MATRIX_ROW_PINS { D4, D7, B7, B4 }
#define MATRIX_ROW_PINS_RIGHT { D4, D7, E6, B4 }

// Fixing bad column pin in left-hand Elite C
#undef MATRIX_COL_PINS // { F6, F7, B1, B3, B2, B6 }
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2, F0 }
#define MATRIX_COL_PINS_RIGHT { F6, F7, B1, B3, B2, B6 }

#define COMBO_COUNT 3
