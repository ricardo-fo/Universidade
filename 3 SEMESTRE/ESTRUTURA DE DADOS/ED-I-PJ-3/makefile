main: main.o ponto.o my_io.o circulo.o
	gcc -o main main.o ponto.o my_io.o circulo.o -lm

main.o: main.c ponto.h my_io.h circulo.o
	gcc -c main.c

ponto.o: ponto.c ponto.h
	gcc -c ponto.c

my_io.o: my_io.c my_io.h
	gcc -c my_io.c

circulo.o: circulo.c circulo.h
	gcc -c circulo.c
