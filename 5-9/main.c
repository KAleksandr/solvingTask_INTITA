#include <stdio.h>
#include <string.h>

int main(void)

{

    char s1[50], s2[10];
    printf("Input string: ");
    gets(s1); // вводимо рядок, слідкуємо - щоб не більше 49 символів!
    strcpy(s2,s1); // в рядок s2 (приймач) копіюється рядок s1 (джерело)
    printf("Result of copiing: ");
    puts(s2); // виводимо рядок s2, курсор автоматично - на новий рядок

}
