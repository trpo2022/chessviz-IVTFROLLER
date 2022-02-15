CC = gcc
CFLAGS = -Wall -o

# Compiling 'Hello, world' file
demo: main.c
	${CC} ${CFLAGS} main main.c 

clean:
	rm -f main
