#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#include "bus.h"
#include "rom.h"

void rom_init(bus_t *bus, uint16_t start, char *data_path) {
    struct stat file_stats;
    int fd = open(data_path, O_RDONLY);        
    int success = fstat(fd, &file_stats);
    size_t file_size = file_stats.st_size;
    uint8_t *buff = malloc(file_size);
    read(fd, buff, file_size);
    rom_dev_t *device_ref = malloc(sizeof(rom_dev_t));
    device_ref->data = buff;
    bus_attach(bus, start, start+file_size, rom_read, rom_write, device_ref);
    close(fd);
}

uint8_t rom_read(void *device, uint16_t addr) {
    rom_dev_t *rom_instance = device;
    return rom_instance->data[addr];
}

void rom_write(void *device, uint16_t addr, uint8_t val) {
    fprintf(stderr, "Tried to write to read only memory!\n");
    exit(1);
}