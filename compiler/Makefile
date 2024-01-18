CFLAGS = -g -Wall -Wextra
CC = gcc
VPATH = src build include

build/nsc: main.o parser.o lexer.o token.o
	$(CC) $(CFLAGS) $? -o $@

build/main.o: main.c
	mkdir build 
	$(CC) $(CFLAGS) -c $? -o $@

build/parser.o: parser.c
	$(CC) $(CFLAGS) -c $? -o $@

build/lexer.o: lexer.c
	$(CC) $(CFLAGS) -c $? -o $@

build/token.o: token.c
	$(CC) $(CFLAGS) -c $? -o $@

.PHONY: clean
clean:
	rm -rf build

.PHONY: run
run: nsc
	./build/nsc -r
