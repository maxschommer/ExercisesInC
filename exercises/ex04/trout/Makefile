trout.o: trout.c trout.h
	gcc -c trout.c
util.o: util.c util.h
	gcc -c util.c
main: trout.o util.o main.c
	gcc trout.o util.o main.c -o main
