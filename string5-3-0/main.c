
//На базі наведеного зразка, складіть програму з наступними особливостями:
//1) введіть в явному вигляді покажчик на рядок (типу char);
//2) присвойте йому значення str ;
//3) за допомогою циклу - виведіть послідовно символи рядка,
//пересуваючи введений покажчик на кожен наступний символ.

#include <stdio.h>
#define MAX 80 // визначення константи MAX із присвоєнням їй значення 80

int main()

{
    char str[MAX] = {0};
    char *s = str;
    printf("Input string: ");

    gets(s);

       while(*s != '\0'){
       printf("\n%c", *s);
        s++;
    }

        printf("\nYou've input: %s\n ",str);
    return 0;
}

