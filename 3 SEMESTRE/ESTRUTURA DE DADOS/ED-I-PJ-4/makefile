main: main.o my_io.o retangulo.o ponto.o
	gcc -o main main.o my_io.o retangulo.o ponto.o -lm

main.o: main.c my_io.h retangulo.h ponto.h
	gcc -c main.c

my_io.o: my_io.c my_io.h
	gcc -c my_io.c

retangulo.o: retangulo.c retangulo.h my_io.h
	gcc -c retangulo.c

ponto.o: ponto.c ponto.h
	gcc -c ponto.c
