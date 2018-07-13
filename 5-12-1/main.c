#include <stdio.h>
#include <string.h>
int main (void)
{
   // Массив со строкой для поиска
   char str [80];
   // Код искомого символа
   char ch;
   // Указатель на искомую переменную в строке,
   // по которой осуществляется поиск.
   char *ach;
   printf("Input string: ");
   gets(str);
   printf("Input symbol:");
   scanf("%c",&ch);

   // Ищем символ ‘6’
   ach=strchr (str,ch);

   // Выводим результат на консоль
   if (ach==NULL)
      printf ("Symbol '%c' in string not found.\n",ch);
   else
      printf ("Wanted symbol in string on a position  # %d\n",ach - str+1);

   return 0;
}
