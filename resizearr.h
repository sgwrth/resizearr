#ifndef RESIZEARR
#define RESIZEARR

typedef int *Intarray;

Intarray createintarray();
int promptforsize();
void initarrayvalues(Intarray array);
Intarray push(int valuetoadd, Intarray array);
Intarray pop(int index, Intarray array);
void printintarray(Intarray array);
int getintarraysize(Intarray array);
Intarray pushmultiple(int valuestoadd[], Intarray array);
void destroy(Intarray array);

#endif
