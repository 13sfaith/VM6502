#include <stdlib.h>
#include <stdio.h>

#include "bus.h"

void bus_init(bus_t *bus) {
    bus->device_count = 0;
}

int bus_attach(bus_t *bus, uint16_t start, uint16_t end, bus_read_fn read, bus_write_fn write, void *device) {
    if (bus->device_count >= BUS_MAX_DEVICES) {
        perror("Bus has too many devices connected");
        return 1;
    }

    bus_device_t *device_entry = &bus->devices[bus->device_count];
    device_entry->start = start;
    device_entry->end = end;
    device_entry->read = read;
    device_entry->write = write;
    device_entry->device = device;

    bus->device_count++;

    return 0;
}

bus_device_t *get_bus_device(bus_t *bus, uint16_t addr) {
    for (int i = 0; i < bus->device_count; i++) {
        if (bus->devices[i].start > addr) {
            continue;
        }
        if (bus->devices[i].end < addr) {
            continue;
        }
        return &bus->devices[i];
    }
    fprintf(stderr, "Invalid get_bus_device address: %hx\n", addr);
    exit(1);
}

uint8_t bus_read(bus_t *bus, uint16_t addr) {
    bus_device_t *device = get_bus_device(bus, addr);
    uint16_t normalized_addr = addr - device->start;
    return device->read(device->device, normalized_addr);
}

void bus_write(bus_t *bus, uint16_t addr, uint8_t val) {
    bus_device_t *device = get_bus_device(bus, addr);
    uint16_t normalized_addr = addr - device->start;
    device->write(device->device, normalized_addr, val);
    return;
}