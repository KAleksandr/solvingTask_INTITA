#include <stdio.h>
#include <string.h>
int main()
{
    char str[80]; // допоміжний рядок
    char str1[80]= "56 32";
    int x, y;
    x=5;
    y =7;// змінні x, y набувають певних значень
    sprintf (str, "X=%d, Y=%d", x, y); // аналогічно printf(), тільки результат буде не на екрані, а в змінній str

    printf("%s\n", str);
    sscanf (str1, "%d%d", &x, &y);
    printf ( "x = %d, y = %d", x, y );
    return 0;
}
