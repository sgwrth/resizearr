#include <stdio.h>
#include <stdlib.h>
#include "resizearr.h"

int main(int argc, char **argv)
{
	Intarray intarray = createintarray();
	printintarray(intarray);

	printf("enter value to push to array: ");
	int valuetopush;
	scanf("%d", &valuetopush);
	intarray = push(valuetopush, intarray);
	printf("pushed %d to array:\n", valuetopush);
	printintarray(intarray);
  
	printf("enter index of value to pop from array: ");
	int indextopop;
	scanf("%d", &indextopop);
	intarray = pop(indextopop, intarray);
	printf("popped value at [%d]:\n", indextopop);
	printintarray(intarray);

	printf("push multiple values:\n");
	Intarray values = createintarray();
	printintarray(values);

	printf("adding multiple values\n");
	intarray = pushmultiple(values, intarray);
	printintarray(intarray);

	destroy(values);
	destroy(intarray);
	return 0;
}
