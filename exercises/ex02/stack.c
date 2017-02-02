/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 /*This is defined in constant memory*/

int *foo() {  /*Returns an array/pointer */
    int i;
    int array[5];

    printf("%p\n", array);

    for (i=0; i<5; i++) {
	array[i] = 42; /*Sets every value of the array to 42*/
    }
    return array;
}

void bar() { /*This returns nothing, but modifies existing 
    variables*/
    int i;
    int array[SIZE];
    printf("%p\n", array); //This points to the same
                           //space as the other array
                           //because it has its own 
                           //variable, and the other
                           //ones were destroyed.

    for (i=0; i<SIZE; i++) {
	array[i] = i;
    }
}

int main()
/*This is trying to print out "42" 5 times*/
{
    int i;
    int *array = foo(); /*Since foo returns a pointer, then 
    array is assigned to a pointer, so it references array inside
    the function.
    Array is destroyed after the function is finished because
    it is stack memory, and we get the error.*/
    bar();

    for (i=0; i<SIZE; i++) {
	printf("%d\n", array[i]);
    }

    return 0;
}
