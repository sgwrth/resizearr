#include <stdio.h>
#include <stdlib.h>

typedef int *Intarray;

Intarray createintarray();
void initarrayvalues(Intarray array);
Intarray push(int valuetoadd, Intarray array);
Intarray pop(int index, Intarray array);
void printintarray(Intarray array);

int main(int argc, int **argv)
{
	Intarray intarray = createintarray();
	printintarray(intarray);

	printf("enter value to push to array: ");
	int valuetopush = 0;
	scanf("%d", &valuetopush);
	intarray = push(valuetopush, intarray);
	printf("pushed %d to array:\n", valuetopush);
	printintarray(intarray);
  
	printf("enter index of value to pop from array: ");
	int indextopop = 0;
	scanf("%d", &indextopop);
	intarray = pop(indextopop, intarray);
	printf("popped value at [%d]:\n", indextopop);
	printintarray(intarray);

	free(intarray);
	return 0;
}

Intarray createintarray()
{
	int size = 0;
	printf("enter size of int array: ");
	scanf("%d", &size);

	Intarray array = (int*)malloc(sizeof(int) * (size + 1));
	array[0] = size; /* storing size info */
	initarrayvalues(array);
	return array;
}

void initarrayvalues(Intarray array)
{
	for (int i = 1; i <= array[0]; i++) {
		int inputvalue = 0;
		printf("enter value for index %d of int array: ", i - 1);
		scanf("%d", &inputvalue);
		array[i] = inputvalue;
	}
}

Intarray push(int valuetoadd, Intarray array)
{
	int oldsize = array[0];
	int newsize = oldsize + 1;
	Intarray newarray = (int*)malloc(sizeof(int) * newsize);
	newarray[0] = newsize;
	int i = 1;
	while (i < newsize) {
		newarray[i] = array[i];
		i++;
	}
	newarray[i] = valuetoadd;
	free(array);
	return newarray;
}

Intarray pop(int indextopop, Intarray array)
{
	int oldsize = array[0];
	int newsize = oldsize - 1;
	Intarray newarray = (int*)malloc(sizeof(int) * newsize);
	newarray[0] = newsize;
	int i = 1;
	while (i <= indextopop) {
		newarray[i] = array[i];
		i++;
	}
	while (i <= newarray[0]) {
		newarray[i] = array[i + 1];
		i++;
	}
	free(array);
	return newarray;
}

void printintarray(Intarray array)
{
	for (int i = 1; i <= array[0]; i++) {
		printf("value at [%d]: %d\n", i - 1, array[i]);
	}
}
