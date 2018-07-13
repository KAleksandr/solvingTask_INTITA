#include <iostream>
int Mul(int &n, int &v);

int main()
{

    int a,b;
    int dob=0;
    printf("Inpun two numbers:  \n");
    scanf("%i%i",&a,&b);

    dob = Mul(a,b);
    printf("\n%i * %i = %i\n",a,b, dob);
    return 0;
}
int Mul(int &c, int &d){
    ++c;
    ++d;
    return c *d;
}
