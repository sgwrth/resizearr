#include <stdio.h>
#include <stdlib.h>
#include "resizearr.h"

int main(int argc, char **argv)
{
	Intarray intarray = new_intarray();
	print_intarray(intarray);

	intarray = push(get_val_to_push(), intarray);
	print_intarray(intarray);

	intarray = pop(get_idx_to_pop(), intarray);
	print_intarray(intarray);

	printf("push multiple values: ");
	Intarray values = new_intarray();
	intarray = push_multiple(values, intarray);
	print_intarray(intarray);

	destroy(values);
	destroy(intarray);

	return 0;
}
