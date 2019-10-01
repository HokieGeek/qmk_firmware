#pragma once

#include "quantum.h"

enum {
    OS_NIX = 0,
    OS_MAC,
    OS_WIN
};

void setTargetOS(uint16_t os);
uint16_t getTargetOS(void);

bool os_process_record_user(uint16_t keycode, keyrecord_t *record);
