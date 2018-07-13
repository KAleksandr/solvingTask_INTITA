#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main()
{
    //char str1[80] ="Wanted symbol in string symbol on a symbol position";
        char str1[80] ="Wanted symbol in string on a position";
    char str2[10] = "symbol";

    char* ps1, *ps2;
    ps1 = &str1[0];
    ps2 = &str2[0];
    ps1 = strstr(ps1, ps2);
    int *pos = (int*)malloc(2 * sizeof(int));
    pos[0] = ps1-&str1[0];
    pos[1] = ps1-&str1[0];
    ps1++;
    while(strstr(ps1,ps2) != NULL){
        ps1 = strstr(ps1, ps2);
        pos[1] = ps1-&str1[0];
        ps1++;
    }

    printf("First posishion %i, last position %i\n", pos[0], pos[1]);

    return 0;
}
