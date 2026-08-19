#ifndef __bus_h__
#define __bus_h__

#include <stdint.h>

#define BUS_MAX_DEVICES 16

typedef struct {
    uint16_t start, end; // start and end range (inclusive) of the device address
    uint8_t (*read)(void *device, uint16_t addr);
    void (*write)(void *device, uint16_t addr, uint8_t val);
    void *device;
} bus_device_t;

typedef struct {
    bus_device_t devices[BUS_MAX_DEVICES];
    int device_count;
} bus_t;

uint8_t bus_read(bus_t *bus, uint16_t addr);
void bus_write(bus_t *bus, uint16_t addr, uint8_t val);

#endif