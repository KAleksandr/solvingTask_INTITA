#include <stdio.h>
#define N 3

int main()
{

    int mas[N]={0};
    FILE *fin, *fout;
    //Для зручності створюю файл(який потім буду зчитувати) і наповнюю послідовними числами
    fin = fopen("input.data", "w");
    for(int i=1; i< 3000; i++)
        fprintf(fin, "%d ", i);
    fclose(fin);
    //// відкриваємо файл в режимі читання і запису
    fin = fopen("input.data", "r");
    if(fin == NULL){
        printf("Not found file!\n");
        return 0;
    }
    fout = fopen("out.data", "w");
    while(1){
        if(N > fscanf(fin, "%d%d%d", &mas[1],&mas[0],&mas[2]))// зчитуємо з файлу input.dat трійку чисел,
           break;
        fprintf(fout, "%4d %4d %4d\n", mas[0], mas[1], mas[2]);// записуємо в файл output.dat змінену трійку чисел,
    }
    printf("The file record has been successfully completed\n");
    fclose(fin);// закриваємо файли
    fclose(fout);

    return 0;
}
