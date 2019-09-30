#pragma once

enum {
    OS_NIX = 0,
    OS_MAC,
    OS_WIN
};

void setTargetOS(uint16_t os);
uint16_t getTargetOS(void);
