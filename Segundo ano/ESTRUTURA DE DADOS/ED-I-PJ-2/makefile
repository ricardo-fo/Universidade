main: main.o my_io.o my_math.o
	gcc -o main main.o my_io.o my_math.o -lm

main.o: main.c my_io.h my_math.h
	gcc -c main.c

my_io.o: my_io.c my_io.h
	gcc -c my_io.c

my_math.o: my_math.c
	gcc -c my_math.c
