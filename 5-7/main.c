#include <stdio.h>
#include <string.h>

int main(void)

{
    int N;
    printf("Input string length: \n");
    scanf("%i",&N);
    int strln; // оголошуємо змінну - довжину рядка (кількість символів)
    char str[N]; // оголошуємо масив фіксованого розміру
    do{
    printf("\nInput string: \n");
    fflush(stdin);
    gets(str);
    strln = strlen(str); // визначаємо довжину рядка
    printf("Length of string %s is %d",str,strln); // виводимо результат
    }
    while(strln < N);

}
