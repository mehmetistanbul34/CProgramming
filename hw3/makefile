all: clean build

build: program.c 
	gcc -c programtest.c -lm
	gcc -o programtest programtest.o -lm
	gcc -c program.c -lm
	gcc -o program program.o -lm
	gcc -c program2.c -lm
	gcc -o program2 program2.o -lm

clean: 
	rm -rf *.o program program2 programtest

