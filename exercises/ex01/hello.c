#include <stdio.h>



int main(){
	int x = 5;  /*When this is declared on its own
	without optimization it is declared in assembly
	code. With optimization, if it is unused, it
	is not compiled. When it is simply used to define
	another variable (ie. y) then it is ignored,
	and y is declared as the value that would result
	from x's evaluation. */

	int y = x+1; /*This, during optimization, becomes
	the only thing considered, and is simply evaluated
	as 6. */
	printf("%d\n", y);/*If the printf statement is not
	called on the variable, optimization will get rid of
	it since it is unused.*/
}