all: clean build start

build: program.c 
	gcc -c program.c -lm
	gcc -o program program.o -lm

clean: 
	rm -rf *.o program

start :
	./program
