#include <stdlib.h>
#include <stdio.h>

#include "bus.h"
#include "cpu.h"
#include "mem.h"

int main() {
    bus_t *bus = malloc(sizeof(bus_t));
    bus_init(bus);

    mem_init(bus, 0x1000, 0x1024);

    bus_device_t memory_d = bus->devices[0];
    memory_d.write(memory_d.device, 0x1000, 0xaa);
    memory_d.write(memory_d.device, 0x1001, 0xbb);
    uint8_t value = memory_d.read(memory_d.device, 0);
    uint8_t value2 = memory_d.read(memory_d.device, 1);
    printf("memory value: %x %x\n", value, value2);

    cpu6502_t *cpu = malloc(sizeof(cpu6502_t));
    cpu_tick(cpu, bus);

    return 0;
}