#include <math.h> //бібліотека математичних функцій

#include <stdio.h>


int main(void) {

    FILE* f; //файловий дескриптор
    int i,n=10;
    char s[]="String";
    float r;

    f=fopen("file_bin","wb"); //створюємо двійковий файл з назвою file_bin для запису даних (параметр “wb”)
    for(i=1;i<=n;i++){
        r=pow(i,1.0/3); //розрахунок кубічного кореня з числа і
        //fwrite(s,sizeof(s),1,f); //запис рядка String у файл
        fwrite(&i,sizeof(int),1,f); //запис цілого числа (номер рядка) у файл
        //fwrite(&r,sizeof(float),1,f); //запис дійсного числа (корінь кубічний) у файл
        //printf("\n%s %d %f",s,i,r); //контрольний вивід на екран
         printf("\n%d",i); //контрольний вивід на екран
    }

    fclose(f); //закриття файлу
    printf("\n");
//    //f=fopen("file_bin","rb"); //відкриття двійковго файлу для читання
//        for(i=n; i>0; i--) { //переміщення покажчика файлу
//            fseek(f,(i-1)*(sizeof(s)+sizeof(int)+sizeof(float)),SEEK_SET);
//            fread(&s,sizeof(s),1,f); //читати з файлу рядок
//            fread(&n,sizeof(int),1,f); //читати ціле число
//            fread(&r,sizeof(float),1,f); //читати дійсне число
//            printf("\n%s %d %f",s,n,r); //вивести вміст файлу на екран
//        }
    getchar(); //затримка - очікування натиснення клавіші Enter
    fclose(f);
}
