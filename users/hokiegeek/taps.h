#ifndef USERSPACE_TAPS
#define USERSPACE_TAPS

void mousekey_tap(uint8_t);
void key_tap(uint8_t);
void tap_mod_key(uint8_t, uint8_t);
void tap_ctrl_key(uint8_t);
void tap_ctltab(void);
void tap_gui_shift_enter(void);

#endif // USERSPACE_TAPS
