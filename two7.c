#include <stdio.h>
#include <windows.h>
main()

{

	int n = 0;
	
	int lim = 50;
	
	float s = 0;
	
	m1: ++n; 
	printf("\n%d", n);
	if(n < lim) // ???? ????? ??????????? -
	{
	
		s += n/(n + 5.0);
		//printf("\n%d", n);
		goto m1; 
	
	}
	printf("\nFinish %d", n);
}
