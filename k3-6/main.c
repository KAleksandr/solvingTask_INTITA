//Реалізуйте функцію, яка має два цілочисельні вхідні параметри a і b, і виконує наступні дії:
//1) двічі виконує множення вказаних аргументів, при цьому в другому виразі обидва піддаються інкременту;
//2) повертає (через return) різницю обох результатів множення.
//Увага! Проведіть експеримент - спочатку запрограмуйте постінкремент, а потім преінкремент аргументів у виразі множення.
//Програма видасть вірне рішення, якщо результат, який повертається функцією, буде відмінний від 0.
//Зверніть увагу, при якому варіанті інкременту результат виявиться вірним.
#include <stdio.h>

int main()
{
    int RizComp(int a, int b);
    int RizComp1(int a, int b);
    int a,b,rez, rez1;
    printf("Input a and b: ");
    scanf("%i%i",&a,&b);
    rez=RizComp(a,b);
    rez1= RizComp1(a,b);
    printf("\n%i * %i - %i * %i = %i\n",a,b,a,b,rez);
    printf("\n%i * %i - %i * %i = %i\n",a,b,a,b,rez1);
    return 0;
}

int RizComp(int a, int b){
    int comp1, comp2, riz;
    comp1 = a*b;
    a++; b++;
    comp2 = a*b;
    riz = comp2 - comp1;

    return riz;
}
int RizComp1(int a, int b){
    int comp1, comp2, riz;
    comp1 = a*b;
    ++a; ++b;
    comp2 = a*b;
    riz = comp2 - comp1;

    return riz;
}
