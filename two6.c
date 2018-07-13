#include <stdio.h>
#include <windows.h>
main()
{
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
int a, b, c; 
int i=1,n;
printf ( "Enter two integers \n" ); 

for(i; i<=2;i++){
	printf("Imput %d number: ", i);
	scanf ( "%d", &n); 
	switch(i){
		case 1: a=n; break;
		case 2: b=n; break;
	}
}

c = a + b; 
printf ( "Result: %d + %d = %d \n", a, b, c ); 
getchar(); 
}

