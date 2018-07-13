#include <stdio.h>
#include <windows.h>
main()

{
int lim;
printf("Imput Limit (number): ");
scanf("%d", &lim);
fflush(stdin);
int d[lim];


float sum=0;
int n=0;

while(1){
	sum+=n/(n+5.0);
    n++;
    if(n>lim){
    	goto m1;
	}
}
//m1:return sum;
m1: printf("Suma = %g", sum);
}
