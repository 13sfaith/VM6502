#ifndef __bus_h__
#define __bus_h__

#include <stdint.h>

#define BUS_MAX_DEVICES 16

typedef uint8_t (*bus_read_fn)(void *device, uint16_t addr);
typedef void (*bus_write_fn)(void *device, uint16_t addr, uint8_t val);

typedef struct {
    uint16_t start, end; // start and end range (inclusive) of the device address
    bus_read_fn read;
    bus_write_fn write;
    void *device;
} bus_device_t;

typedef struct {
    bus_device_t devices[BUS_MAX_DEVICES];
    int device_count;
} bus_t;

void bus_init(bus_t *bus);
int bus_attach(bus_t *bus, uint16_t start, uint16_t end, bus_read_fn read, bus_write_fn write, void *device);
uint8_t bus_read(bus_t *bus, uint16_t addr);
void bus_write(bus_t *bus, uint16_t addr, uint8_t val);

#endif