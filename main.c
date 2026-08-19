#include <stdlib.h>
#include <stdio.h>

#include "bus.h"
#include "cpu.h"
#include "mem.h"
#include "rom.h"

int main() {
    bus_t *bus = malloc(sizeof(bus_t));
    bus_init(bus);
    rom_init(bus, 0x1000, "./ROM/rom_data");
    mem_init(bus, 0x1100, 0x1024);

    printf("rom read[0]: %hhx\n", bus_read(bus, 0x1000));
    printf("rom read[1]: %hhx\n", bus_read(bus, 0x1001));

    cpu6502_t *cpu = malloc(sizeof(cpu6502_t));
    cpu_tick(cpu, bus);

    return 0;
}