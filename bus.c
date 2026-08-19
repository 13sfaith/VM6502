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

    bus_device_t device_entry = bus->devices[bus->device_count];
    device_entry.start = start;
    device_entry.end = end;
    device_entry.read = read;
    device_entry.write = write;
    device_entry.device = device;

    bus->device_count++;

    return 0;
}