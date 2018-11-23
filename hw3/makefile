all: clean build start

build: program.c 
	gcc -c programtest.c -lm
	gcc -o program programtest.o -lm

clean: 
	rm -rf *.o program

start :
	./program
