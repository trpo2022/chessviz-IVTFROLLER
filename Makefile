CC = gcc
WALL_FLAGS = -Wall -Werror


all: build run clean

build: main.o 
	$(CC) $(WALL_FLAGS) src/chess/main.o

main.o:
	$(CC) -c src/chess/main.c -o src/chess/main.o

run:
	./a.out
clean:
	rm -f a.out 
	rm -f src/chess/main
	rm -f src/chess/main.o
