#include <stdio.h>
#include <stdlib.h>

int *createintarray(int size);
void initarrayvalues(int *array);
int *push(int valuetoadd, int *array);
void printarray(int *array);

int main(int argc, int **argv)
{
  int size = 0;
	printf("enter size of int array: \n");
	scanf("%d", &size);
	printf("size: %d\n", size);

	int *intarray = createintarray(size);

	printarray(intarray);

	intarray = push(1, intarray);

	printarray(intarray);

	return 0;
}

int *createintarray(int size)
{
	int *array = (int*)malloc(sizeof(int) * (size + 1));
  array[0] = size; /* storing size info */
  initarrayvalues(array);
	return array;
}

void initarrayvalues(int *array)
{
	for (int i = 1; i <= array[0]; i++) {
		int inputvalue = 0;
		printf("enter value for index %d of int array: ", i - 1);
		scanf("%d", &inputvalue);
		array[i] = inputvalue;
	}
}

int *push(int valuetoadd, int *array)
{
  int oldsize = array[0];
  int newsize = oldsize + 1;
	int *newarray = (int*)malloc(sizeof(int) * (oldsize + 1));
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

void printarray(int *array)
{
	for (int i = 1; i <= array[0]; i++) {
		printf("value at [%d]: %d\n", i - 1, array[i]);
	}
}
