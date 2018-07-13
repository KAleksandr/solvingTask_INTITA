#include<stdio.h>

main(){
	int k=-4, l=3, t=3;
	int p, n;
	k-=(2*l++)/4+5%(--l);
	
	//p=2*l++;
//	n=2*(++t);
	printf("%d", k);
	printf("\n%d", l);
	//printf("\n%d", n);
}
