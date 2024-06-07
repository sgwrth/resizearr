#ifndef RESIZEARR
#define RESIZEARR

typedef int *Intarray;

Intarray new_intarray();
int prompt_for_size();
void init_intarray(Intarray array);
int get_val_to_push();
int get_idx_to_pop();
int is_valid_int(char *string);
int is_valid_uint(char *string);
int is_digit(char character);
int is_decimal(char *string);
int is_positive_decimal(char *string);
Intarray push(int vals_to_add, Intarray array);
Intarray pop(int idx_to_pop, Intarray array);
void print_intarray(Intarray array);
int get_size(Intarray array);
Intarray push_multiple(Intarray vals_to_add, Intarray array);
void destroy(Intarray array);

#endif
