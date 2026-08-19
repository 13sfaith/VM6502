#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "mem.h"

void mem_init(bus_t *bus, uint16_t start, uint16_t size) {
    void *data = malloc(size);
    memset(data, 0, size);
    mem_dev_t *mem_dev = malloc(sizeof(mem_dev_t));
    mem_dev->data = data;
    mem_dev->start = start;
    mem_dev->end = start+size;

    if (bus_attach(bus, mem_dev->start, mem_dev->end, read, write, mem_dev) != 0) {
        perror("Failed to initalize memory");
        exit(1);
    }

    return;
}

uint16_t convert_address_to_index(mem_dev_t *device, uint16_t addr) {
    return addr - device->start;
}

uint8_t read(void *device, uint16_t addr) {
    mem_dev_t *memory_instance = device;
    uint16_t memory_index = convert_address_to_index(memory_instance, addr);
    return memory_instance->data[addr];
}

void write(void *device, uint16_t addr, uint8_t val) {
    mem_dev_t *memory_instance = device;
    uint16_t memory_index = convert_address_to_index(memory_instance, addr);
    memory_instance->data[memory_index] = val;
    return;
}