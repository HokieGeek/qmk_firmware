#ifndef USERSPACE_CONFIG_H
#define USERSPACE_CONFIG_H

// Disabling deprecated features
#ifndef NO_ACTION_MACRO
#define NO_ACTION_MACRO
#endif
#ifndef NO_ACTION_FUNCTION
#define NO_ACTION_FUNCTION
#endif

#ifndef NO_ACTION_ONESHOT
#define NO_ACTION_ONESHOT
#endif

#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

// Use serial, by default
#if !defined(USE_SERIAL) && !defined(USE_I2C)
#define USE_SERIAL
#endif // !USE_SERIAL && !USE_I2C

#define PERMISSIVE_HOLD
#define PREVENT_STUCK_MODIFIERS

#ifdef TAPPING_TERM
#undef TAPPING_TERM
#endif // TAPPING_TERM
#define TAPPING_TERM 180

#ifdef COMBO_ENABLE
#define COMBO_TERM 10
#endif // COMBO_ENABLE

#ifdef TAPPING_TOGGLE
#undef TAPPING_TOGGLE
#endif //TAPPING_TOGGLE
#define TAPPING_TOGGLE 3

#if !defined(MASTER_LEFT) && !defined(MASTER_RIGHT) && !defined(EE_HANDS)
#undef MASTER_LEFT
#undef SPLIT_HAND_PIN
#define EE_HANDS
#endif

#endif
