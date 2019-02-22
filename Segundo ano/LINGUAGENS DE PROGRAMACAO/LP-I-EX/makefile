CC = gcc

CFLAGS = -Wall -g

FONTES = $(wildcard *.c)

OBJETOS = $(FONTES:.c=.o)

EXECUTAVEL = program_exec

all: $(EXECUTAVEL)

$(EXECUTAVEL): $(OBJETOS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) $^

clean:
	rm -rf *.o

rmproper: clean
	rm -rf $(EXECUTAVEL)

run: $(EXECUTAVEL)
	./$(EXECUTAVEL)

