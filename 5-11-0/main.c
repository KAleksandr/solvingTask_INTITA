#include <stdio.h>
#include <string.h>
#define N 20
#define M 12
int main()

{
    char s1[N];
    char s2[M];
    int sizeS1,sizeS2;

    do{
        printf("Input string one: ");
        gets(s1);
        printf("Input string two: ");
        gets(s2);
        sizeS1 =sizeof(s1) - strlen(s1);//вільний розмір отримувача
        sizeS2 = strlen(s2);//розмір передавача
        if(!(sizeS1 >= sizeS2)){
            puts("---------------------------------------------------------");
            puts("\nThere is not enough space to copy\n");
            puts("---------------------------------------------------------\n");
            memset(s1, 0, sizeof(s1));//обнулення стрічки
            memset(s2, 0, sizeof(s2));//обнулення стрічки
        }
    }
    while(!(sizeS1 >= sizeS2));
    if(s1[strlen(s1)-1] != ' '&& (sizeS1 - sizeS2) >= 1)//якщо в кінці першого рядка немає пробілу - добавлю
        s1[strlen(s1)] = ' ';

    strcat(s1,s2); // дописати рядок s2 в кінець s1
    puts(s1); // результат  операції

    return 0;


}
