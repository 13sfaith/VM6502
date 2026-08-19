#include <stdlib.h>

#include "bus.h"
#include "cpu.h"

int main() {
    bus_t *bus = malloc(sizeof(bus_t));
    bus_init(bus);

    cpu6502_t *cpu = malloc(sizeof(cpu6502_t));

    cpu_tick(cpu, bus);

    return 0;
}