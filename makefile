all: picmaker.o
	gcc -o program picmaker.o
	./program
	display img.ppm

picmaker.o: picmaker.c
	gcc -c picmaker.c

run: 
	./program