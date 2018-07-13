#include <stdio.h>
#include <string.h>
#define N 80
int main()
{
    char s[N];
    FILE *fin, *fout;

    fin = fopen("input.txt", "r");
    if(fin==NULL){
        printf("File not found!\n");
        return 0;
    }
    fout = fopen("output.txt", "w");
    while(EOF !=  fscanf(fin, "%s",s)){
        for(int i =0; i<(int)strlen(s); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                  fprintf(fout,"%s ", s);
                break;
            }
        }
    }
    fclose(fin);
    fclose(fout);
    printf("Conversion is complete!\n");
    return 0;
}
