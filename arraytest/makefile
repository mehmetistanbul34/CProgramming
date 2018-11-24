all: clean build

build: test.c 
	gcc -c test.c -lm
	gcc -o test test.o -lm

clean: 
	rm -rf *.o test

