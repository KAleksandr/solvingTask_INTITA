#include <stdio.h>
#include <string.h>
#include<malloc.h>
#define N 80
void newStr1(char *s1, char *s2, int a, int b);
void newStr2(char* s1, char* s2, int a,int b);
void inputNumbers(int* n1,int*n2,int size1, int size2);

int main()
{
    char str1[N], str2[N];
    char* s1,*s2;

    printf("Input string one: ");
    gets(str1);
    printf("Input string two: ");
    gets(str2);
    s1 = &str1[0];
    s2 = &str2[0];
    int sizeS1 = strlen(str1 );
    int sizeS2 = strlen(str2);
    int n1, n2;
    inputNumbers(&n1,&n2,sizeS1,sizeS2);
    newStr1(s1,s2,n1,n2);
    newStr2(s1,s2,n1,n2);
    return 0;
}
//введення цілих чисел які використовуються для обмеження копіювання
void inputNumbers(int* n1,int*n2,int size1, int size2){
    do{
        printf("\nInput number 0 < N <= %i: ",size1);
        scanf("%i",n1);
        printf("\nInput number 0 < M <= %i: ",size2);
        scanf("%i",n2);
        fflush(stdin);
    }
    while(!(*n1>0 && *n1<= size1 && *n2>0 && *n2<= size2));
}
/*
 * шляхом копіювання одночасно цілої групи символів з рядків str1 і str2;
 */
void newStr1(char *s1, char *s2, int a, int b){
    char* newText  = (char*)calloc(strlen(s1)+strlen(s2),sizeof(char));
    char* newTextTmp  = (char*)calloc(strlen(s2),sizeof(char));
    strncpy(newText, s1,a);
    strncpy(newTextTmp,(s2+(strlen(s2)-b)),b);//n2 останніх символів рядка str2 (в кінці).
    strcat(newText, newTextTmp);
    printf("Version 1: ");
    puts(newText);
    free(newTextTmp);
    free(newText);
}

/*
 * шляхом посимвольного копіювання необхідних літер з відповідних рядків;
 */
void newStr2(char* s1, char* s2, int a,int b){
    char* newText  = (char*)calloc(strlen(s1)+strlen(s2),sizeof(char));
    newText = s1;
    newText +=a;
    int i = 0;
    s2 = (s2+(strlen(s2)-b));//ось тут виправив помилку(n2 останніх символів рядка)
    while(i < b){
        *newText++ = *s2++;
        i++;
    }
    *newText = '\0';
    newText = s1;
    printf("Version 2: ");
    puts(newText);
    free(newText);
}
