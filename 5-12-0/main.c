#include <stdio.h>

#include <string.h>

int main(void)

{

    char str1[80], str2[5]; // основний рядок і підрядок
    char symb; // символ для пошуку в основному рядку
    char* p; // покажчик на знайдений символ чи підрядок

    printf("Input main string: ");
    gets(str1);
    printf("Input sub-string: ");
    gets(str2);
    printf("Input target symbol: ");
    scanf("%c",&symb);
    p = strchr(str1,symb); // пошук символу від початку основного рядка
    if (p!=NULL) { // якщо символ знайдено
        printf("First symbol %c: number %d \n", symb, p - str1);
        // номер символу в рядку - різниця покажчиків на символ і початок рядка
        p = strrchr(str1, symb); // пошук символу з кінця основного рядка
        // якщо він в рядку один-єдиний - результат співпаде з попереднім пошуком

        printf("Last symbol %c: number %d \n", symb, p - str1);

    }

    else printf("There is not symbol %c in our main string", symb);

    p = strstr(str1,str2); // пошук підрядка str2 в основному рядку str1

    if (p!=NULL) // якщо підрядок знайдено

        printf("There is substring %s in our main string", str2);

    else printf("There is not substring %s in our main string", str2);

}
