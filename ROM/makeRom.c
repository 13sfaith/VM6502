#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
	int fd = open("rom_data", O_WRONLY);

	uint8_t *data = malloc(5);
	data[0] = 0xa;
	data[1] = 0xb;

	write(fd, data, 2);
	close(fd);
		
	return 0;
}
