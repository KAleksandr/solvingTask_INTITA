#include <stdio.h>
#include <math.h>
#include <iostream>



float * func (int i, float * mas)
{
 float * mas_new = new float [i];
 for (int z = 0; z <i; z ++)
mas_new [z] = sqrt (mas [z]);
 return mas_new;
}

int main ()
{
 float mas [] = {1.0, 2.0, 3.0, 4.0};
 float * mas_new;

 for (int z = 0; z <4; z ++)
printf ( "% f", mas [z]);

 mas_new = func (4, mas);

 for (int z = 0; z <4; z ++)
printf ( "% f", mas_new [z]);

 delete mas_new;
 return 0;
}
