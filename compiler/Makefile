CFLAGS = 
CC = gcc
VPATH = src build include

build/nsc: main.o
	$(CC) $(CFLAGS) $? -o $@

build/main.o: main.c
	rm -rvf build
	mkdir build
	$(CC) $(CFLAGS) -c $? -o $@

clean:
	rm -rvf build

run: nsc
	./build/nsc
