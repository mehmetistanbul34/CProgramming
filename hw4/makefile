all : clean build

build : program.c
	gcc -c program.c
	gcc -o program program.o
	
clean : 
	rm -rf *.o program
