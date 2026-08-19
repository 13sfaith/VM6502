#ifndef __rom_h__
#define __rom_h__

#include "bus.h"

typedef struct {
    uint8_t *data;
} rom_dev_t;

void rom_init(bus_t *bus, uint16_t start, char *data_path);
uint8_t rom_read(void* device, uint16_t addr);
void rom_write(void *device, uint16_t addr, uint8_t val);

#endif