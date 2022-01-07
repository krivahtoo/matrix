CC=cc
CFLAGS=-Wall -Wextra -pedantic -ggdb
CFLAGS += `pkg-config --cflags ncursesw`
LIBS=-lm
LIBS += `pkg-config --libs ncursesw`

matrix: main.o matrix.o ui.o
	$(CC) -o matrix main.o matrix.o ui.o $(CFLAGS) $(LIBS)

main.o: main.c
	$(CC) -o main.o -c main.c $(CFLAGS)

ui.o: ui.c ui.h
	$(CC) -o ui.o -c ui.c $(CFLAGS)

matrix.o: matrix.c matrix.h
	$(CC) -o matrix.o -c matrix.c $(CFLAGS)

clean:
	rm -r *.o matrix

