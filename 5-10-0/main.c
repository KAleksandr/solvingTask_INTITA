#include <stdio.h>

#include <string.h>

main()

{

char s1[] = "Go Home!";

char s2[10];



strncpy(s2,s1,2); // скопіювати 2 перші символи з s1 в s2

//puts(s2); //- помилка! (оскільки відсутній символ кінця рядка '\0' - функція виведе рядок s2 і всі символи, що містяться в пам’яті за ним, поки не зустріне '\0')

s2[2] = '\0'; // додаємо символ кінця рядка

puts (s2); // результат - рядок “Go”

}
/*
 * 	char *s1 = &str1[0];
    char *s2 = &str2[0];
    if(n <= (int)strlen(s1) && n <= (int)strlen(s2)){

                strncpy(s1,s2,2);
                 s1[n] = '\0';
                  return s1;
             }

     else return "Error";

 * /
