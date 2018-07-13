#include <stdio.h>
#include <windows.h>
main()

{
	int a[10];
	int i;
	for(i=0; i<10; i++){
		printf("Imput a[%d]: ",i);
		scanf("%d",&a[i]);
	}
	
	for(i=9; i>0; i--){
		a[i]-=a[i-1];
	}
	for(i=0; i<10; i++){
		printf("\na[%d] = %d", i, a[i]);
	}
 
}
