#include <stdio.h>
#include <stdlib.h>

int size = 0;

int *createintarray(int size)
{
	int *array = (int*)malloc(sizeof(int) * size);
	return array;
}

int *push(int x, int *array)
{
	int *newarray = (int*)malloc(sizeof(int) * size + 1);
	int i = 0;
	while (i < size) {
		newarray[i] = array[i];
		i++;
	}
	newarray[i] = x;
	free(array);
	size++;
	return newarray;
	
}

void printarray(int *array)
{
	for (int i = 0; i < size; i++) {
		printf("%d. value: %d\n", i + 1, array[i]);
	}
}

int main(int argc, int **argv)
{
	int array[5] = {1, 2, 3, 4, 5};
	printf("size of array: %ld\n", sizeof(array) / sizeof(array[0]));
	printf("enter size of int array: \n");
	scanf("%d", &size);
	printf("size: %d\n", size);
	int *intarray = createintarray(size);

	for (int i = 0; i < size; i++) {
		int value = 0;
		printf("enter value for index %d of int array: ", i);
		scanf("%d", &value);
		intarray[i] = value;
	}

	printf("size of intarray: %ld\n", sizeof(intarray) / sizeof(intarray[0]));

	printarray(intarray);

	intarray = push(1, intarray);

	printarray(intarray);

	return 0;
}
