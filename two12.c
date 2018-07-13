#include <stdio.h>

#define N 10

main()

{

	int i, j, arr[N];
	int mas[N];
	 
	for(i=0; i<N; i++){
		printf("Input arr[%d]: ",i);
		scanf("%d", &arr[i]);
	}
	
	
	for ( i = 0; i < N; i ++ )
	{
		mas[i]=0;
	}
	j=0;
	for(i=0; i<N; i++){
		if(arr[i]<0){
			mas[j]=arr[i];
			j++;
		}
	}
	for ( i = 0; i < N; i ++ )
	{
		arr[i]=mas[i];
	}
	for(i=0; i<N; i++){
		printf("%d ",arr[i]);
	}

}
