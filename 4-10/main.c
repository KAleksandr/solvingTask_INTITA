#include <stdio.h>

int Factorial ( int n )     // розрахнок значення n!

{

    if ( n <= 0 ) return 1; // умова завершення рекурсії

    else return n*Factorial(n-1); // рекурсивний виклик функції самої себе

}                                               // підсумковий результат буде дорівнювати n*(n-1)*...*1
int main()
{
    int n, f;
    printf("Input number (> 0): ");
    scanf("%i", &n);
    f = Factorial(n);
    printf("Factorial number %i! = %i\n", n ,f);
    return 0;
}
