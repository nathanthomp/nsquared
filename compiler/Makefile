CFLAGS = -g
CC = gcc
VPATH = src build include

build/nsc: main.o
	$(CC) $(CFLAGS) $? -o $@

build/main.o: main.c
	rm -rf build
	mkdir build
	$(CC) $(CFLAGS) -c $? -o $@

clean:
	rm -rf build

run: nsc
	./build/nsc
