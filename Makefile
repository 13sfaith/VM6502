
build:
	cc $(wildcard *.c) -o vm6502

debug:
	cc -ggdb $(wildcard *.c) -o vm6502

clean:
	rm vm6502
	rm -rf vm6502.dSYM