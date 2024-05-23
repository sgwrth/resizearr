#include <stdio.h>
#include <stdlib.h>
#include "resizearr.h"

Intarray createintarray()
{
	int arraysize = promptforsize();
	Intarray array = (int*)malloc(sizeof(int) * (arraysize + 1));
	array[0] = arraysize;		/* storing size info */
	initarrayvalues(++array);	/* shifting pointer to index 1 */
	return array;
}

int promptforsize()
{
	int size = 0;
	printf("enter size of int array: ");
	scanf("%d", &size);
	return size;
}

void initarrayvalues(Intarray array)
{
	for (int i = 0; i < getintarraysize(array); i++) {
		int inputvalue = 0;
		printf("enter value for index %d of int array: ", i);
		scanf("%d", &inputvalue);
		array[i] = inputvalue;
	}
}

Intarray push(int valuetoadd, Intarray array)
{
	int newsize = getintarraysize(array) + 1;
	Intarray newarray = (int*)malloc(sizeof(int) * newsize);
	newarray[0] = newsize;
	int i = 1;
	while (i < newsize) {
		newarray[i] = array[i - 1];
		i++;
	}
	newarray[i] = valuetoadd;
	destroy(array);
	return ++newarray;
}

Intarray pop(int indextopop, Intarray array)
{
	int newsize = getintarraysize(array) - 1;
	Intarray newarray = (int*)malloc(sizeof(int) * newsize);
	newarray[0] = newsize;
	int i = 1;
	while (i <= indextopop) {
		newarray[i] = array[i - 1];
		i++;
	}
	while (i <= newsize) {
		newarray[i] = array[i];
		i++;
	}
	destroy(array);
	return ++newarray;
}

void printintarray(Intarray array)
{
	for (int i = 0; i < getintarraysize(array); i++) {
		printf("value at [%d]: %d\n", i, array[i]);
	}
}

int getintarraysize(Intarray array)
{
	return *(array - 1);
}

Intarray pushmultiple(Intarray valuestoadd, Intarray array)
{
	int numberofvalues = getintarraysize(valuestoadd);
	printf("number of values to add: %d\n", numberofvalues);
	for (int i = 0; i < numberofvalues ; i++) {
		array = push(valuestoadd[i], array);
	}
	return array;
}

void destroy(Intarray array)
{
	free(--array);
}
