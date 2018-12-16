all : clean build start

build : proje.c
	gcc -c proje.c
	gcc -o projem proje.o
	
clean :
	rm -rf *.o projem
	
start :
	./projem
