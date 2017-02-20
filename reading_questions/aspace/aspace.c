/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int global;


void printlocal(){
	int local2 = 6;
	printf ("Address of local2 is %p\n", &local2);
}

int main ()
{
    int local = 5;
    void *p = malloc(128);
    void *d = malloc(128);

    void *chunk1 = malloc(17);
    void *chunk2 = malloc(17);

    printf ("Address of main is %p\n", main);
    printf ("Address of global is %p\n", &global);
    printf ("Address of local is %p\n", &local);
    printlocal();
    printf ("Address of p is %p\n", p);
    printf ("Address of d is %p\n\n", d);
    printf ("Address of chunk1 is %p\n", chunk1);
    printf ("Address of chunk2 is %p\n\n", chunk2);
    return 0;
}
