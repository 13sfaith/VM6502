#ifndef __CPU_H__
#define __CPU_H__

#include <stdint.h>

#include "bus.h"

typedef struct {
    uint8_t a, x, y, sp, status;  // registers
    uint16_t pc;
} cpu6502_t;

void cpu_tick(cpu6502_t *cpu, bus_t *bus);

#endif