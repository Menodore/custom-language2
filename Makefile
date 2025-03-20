all: globals.h virtual.h token.h parser.h
	gcc -ggdb main.c -o main
clean:
	rm main