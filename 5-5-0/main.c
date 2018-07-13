#include <stdio.h>
#define N 80
void copy2(char* str1, char* str2);
int find(char *str);
int main()
{
    char name[N];
    char text[N];
    puts("Input first name and last name:");
    gets(name);
    puts(name);
    copy2(text, name);
    puts("Tekst2 ");
    puts(text);
    char t = (char)find(text);
    printf("%i",t);


    return 0;
}

void copy2(char* str1, char* str2)
{
    while((*str1++ = *str2++));
    }
int find(char *str){
        char *ps;
        int i=0,k=-1;
        ps = str;
        while(*ps !=0){
            i++;
            if(*ps++ =='y')
                k = i;
        }
    return k;
}
