all: clean build

build: programtest.c 
	gcc -c programtest.c -lm
	gcc -o programtest programtest.o -lm

clean: 
	rm -rf *.o programtest

