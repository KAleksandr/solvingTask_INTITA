#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
#include <time.h>
#define N 150

void createFile();
void processingFile();
void copyFile();

int main()
{
    createFile();
    processingFile();
    return 0;
}
//-------------------------------------------------------------------||
/* 1.
* Створюю текстовий файл, в якому в довільному порядку записані цілі
* і дійсні числа (ціла і дробова частина відділяються символом “.”);
*/
//-------------------------------------------------------------------||
void createFile(){
    int number1;
    float number2;
    FILE *fp;
    srand(time(NULL));
    fp = fopen("input.txt", "w");
    for(int i =0; i< N; i++){
        if(i%10 == 0 && i!=0)
            fprintf(fp, "\n");
        number1 =rand()%100+i;
        number2 = rand()%100 * 0.1+0.2 ;
        if(number2 < 5)
            fprintf(fp, "%4i %4g ", number1, number2);
        else
            fprintf(fp, "%4g %4i ", number2, number1);
    }
    fclose(fp);

}
//-------------------------------------------------------------------||
/* 2.
 * а) читає послідовно з файлу числа і розподіляє їх для запису в два інші файли:
 * перший - лише цілі, другий - лише дійсні;
 * б) числа в нові файли повинні записуватись в стовпчик;
 * в) останнім рядком кожного файлу має бути: “Сума = S”, де S - сума всіх чисел файлу;
 */
//-------------------------------------------------------------------||
void processingFile(){
    float summa=0;
    int sumFloat=0;
    char str[10];
    FILE *fin, *fint, *ffloat, *temp;
    fin = fopen("input.txt", "r");
    if(fin == NULL){
        printf("File not found!");
        return;
    }
    fint = fopen("integerNumber.txt", "w");
    ffloat = fopen("floatNumber.txt", "w");
    temp = fopen("temp.dat", "w");
    fprintf(temp, "Whole parts: ");//б) дописую рядок: “Цілі частини: ...” - і далі в один рядок
    while(1){
        if(1 > fscanf(fin, "%s",str))
            break;
        if(strchr (str,'.') == NULL){
            fprintf(fint, "%s\n", str);
            summa += atoi(str);
        }
        else{
            fprintf(ffloat, "%s\n", str);
            summa += atof(str);
            sumFloat += atoi(str);
            fprintf(temp, "%d ", atoi(str));//а) виділіть цілі частини кожного дійсного числа і записую в один рядок;
        }
    }
    fprintf(fint, "Summa = %g\n", summa);
    fprintf(ffloat, "Summa = %g\n", summa);
    fprintf(temp, "\nThe sum of the whole parts = %d", sumFloat);//“Сума цілих частин = Sс”, де Sс - сума відповідних значень.
    fclose(fin);
    fclose(fint);
    fclose(ffloat);
    fclose(temp);
    copyFile();
    printf("Task complete :-)\n");
}

//-------------------------------------------------------------------||
//допису в кінець файлу дійсних чисел виконання умови 3.

void copyFile(){
    char buf[BUFSIZ];
    FILE
        *input = fopen("temp.dat", "r"),
        *output = fopen("floatNumber.txt", "a");
    if(input ==NULL){
        printf("File not found!\n");
        return;
    }
    while ((NULL != fgets(buf,sizeof(buf),input))) // копірую по стрічці файл
    {
        fprintf(output,"%s",buf);// допису в кінець іншого файлу
    }
    fclose(input);
    fclose(output);
}
