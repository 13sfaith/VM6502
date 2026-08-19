
build:
	gcc $(wildcard *.c) -o vm6502

clean:
	rm vm6502