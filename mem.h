#ifndef __mem_h__
#define __mem_h__

#include "bus.h"

typedef struct {
    uint16_t start, end;
    uint8_t *data;
} mem_dev_t;

void mem_init(bus_t *bus, uint16_t start, uint16_t size);
uint8_t mem_read(void* device, uint16_t addr);
void mem_write(void *device, uint16_t addr, uint8_t val);

#endif