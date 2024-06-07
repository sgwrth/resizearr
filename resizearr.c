#include <stdio.h>
#include <stdlib.h>
#include "resizearr.h"
#define MIN_VAL_UINT 0
#define MAX_VAL_UINT 4294967295
#define MIN_VAL_INT -2147483648
#define MAX_VAL_INT 2147483647

Intarray new_intarray()
{
	int array_size = prompt_for_size();
	Intarray array = malloc((array_size + 1) * sizeof(int));
	array[0] = array_size;		/* storing array size */
	init_intarray(++array);		/* '++': shifting pointer to index 1 */
	return array;
}

int prompt_for_size()
{
	char *size = malloc(10 * sizeof(char));
	while (1) {
		printf("enter size of int array (max: %ld): ", MAX_VAL_UINT);
		scanf("%s", size);
		if (0 == is_valid_uint(size)) {
			break;
		} else {
			printf("wrong input, please try again.\n");
		}
	}
	return atoi(size);
}

int is_valid_int(char *input)
{
	long value;	
	if (0 == is_positive_decimal(input)) {
		value = atoi(input);
	} else {
		return -1;
	}
	return (MAX_VAL_INT >= value && MIN_VAL_INT <= value) ? 0 : 1; 
}

int is_valid_uint(char *string)
{
	long value;	
	char *tmp;
	if (0 == is_positive_decimal(string)) {
		value = strtol(string, &tmp, 10);
	} else {
		return -1;
	}
	return (MAX_VAL_UINT >= value && MIN_VAL_UINT <= value) ? 0 : -1; 
}

int is_positive_decimal(char *string)
{
	int i = 0;
	while (string[i] != '\0') {
		if (0 != is_digit(string[i])) {
			return -1;
		}
		i++;
	}
	return 0;
}

int is_decimal(char *string)
{
	int i = 0;
	if ('-' == string[i] || 0 == is_digit(string[i])) {
		i++;
		while (string[i] != '\0') {
			if (0 != is_digit(string[i])) {
				return -1;
			}
			i++;
		}
		return 0;
	} else {
		return -1;
	}
}

int is_digit(char character)
{
	switch (character) {
		case '0': break;
		case '1': break;
		case '2': break;
		case '3': break;
		case '4': break;
		case '5': break;
		case '6': break;
		case '7': break;
		case '8': break;
		case '9': break;
		default: return -1; 
	}
	return 0;
}

void init_intarray(Intarray array)
{
	for (int i = 0; i < get_size(array); i++) {
		int input_val;
		printf("enter value for index %d of int array: ", i);
		scanf("%d", &input_val);
		array[i] = input_val;
	}
}

int get_val_to_push()
{
	printf("enter value to push to array: ");
	int val_to_push;
	scanf("%d", &val_to_push);
	return val_to_push;
}

int get_idx_to_pop()
{
	printf("enter index of value to pop from array: ");
	int idx_to_pop;
	scanf("%d", &idx_to_pop);
	return idx_to_pop;
}

Intarray push(int val_to_add, Intarray array)
{
	int new_size = get_size(array) + 1;
	Intarray new_array = (int*)malloc(new_size * sizeof(int));
	new_array[0] = new_size;
	int i = 1;
	while (i < new_size) {
		new_array[i] = array[i - 1];
		i++;
	}
	new_array[i] = val_to_add;
	destroy(array);
	return ++new_array;
}

Intarray pop(int idx_to_pop, Intarray array)
{
	int new_size = get_size(array) - 1;
	Intarray new_array = (int*)malloc(new_size * sizeof(int));
	new_array[0] = new_size;
	int i = 1;
	while (i <= idx_to_pop) {
		new_array[i] = array[i - 1];
		i++;
	}
	while (i <= new_size) {
		new_array[i] = array[i];
		i++;
	}
	destroy(array);
	return ++new_array;
}

void print_intarray(Intarray array)
{
	for (int i = 0; i < get_size(array); i++) {
		printf("value at [%d]: %d\n", i, array[i]);
	}
}

int get_size(Intarray array)
{
	return *(array - 1);
}

Intarray push_multiple(Intarray vals_to_add, Intarray array)
{
	for (int i = 0; i < get_size(vals_to_add); i++) {
		array = push(vals_to_add[i], array);
	}
	return array;
}

void destroy(Intarray array)
{
	free(--array);
}
