#include <stdio.h>
#define N 10
#define M 6
int main()
{
    int sum = 0;
    long n= 0, m= 0;
    int A[N], B[M]={0};

    FILE *fb, *foutb;
    fb = fopen("file_bin", "rb");//відкриваю файл
    fseek(fb,0L,SEEK_END);//переміщення в кінець файлу
    //так як відомо, що працюємо з цілими числами, знаходжу кількість елементів в файлі
    long size = ftell(fb)/sizeof(int);
    fseek(fb,0L,SEEK_SET);// повертаю покажчик на початок файлу

    // заповнюю елементами масив(и)
    if (size <= N)
        n = fread(A, sizeof(int), size, fb);//заповнюю тільки масив А
    else if(size > N && size <=M +N){
        n = fread(A, sizeof(int), N, fb);
        m = fread(B, sizeof(int), size-N, fb);
    }
 //якщо даних у файлі більше, ніж сукупна розмірність обох масивів - видається повідомлення
 //про помилку і вихід з програми;
    else{
        printf("Error! Data is too much\n");
        fclose(fb);
        return 0;
     }
    fclose(fb);
    foutb = fopen("output.dat", "wb+");//відкриваю файл на запис/читання
    int count;
    if(m == 0)
        count = n < M ? n : M;
    else
        count = n < m ? n : m;
    /*
     * у двійковий файл output.dat записати послідовно числа - суми відповідних елементів
     * (під однаковими номерами) масивів A[N] і B[M] (надлишкові елементи одного з масивів,
     * якщо такі будуть - проігнорувати);
     */
    if(count > 0)//перевірка чи потрібно записувати дані
        for(int i = 0; i < count; i++){
            sum = A[i] + B[i];
            fwrite(&sum, sizeof(int),1,foutb);
        }
    //вивести на екран вміст обох масивів
    if(n> 0){
        printf("  \tA:");
        for(int i=0; i <n; i++)
            printf("%2d ", A[i]);
        printf("\n");
    }
    if(m >= 0){
        printf("  \tB:");
        for(int i=0; i <M; i++)
            printf("%2d ", B[i]);
        printf("\n");
     }
    fseek(foutb,0L,SEEK_SET);// повертаю покажчик на початок файлу
    if(count > 0)//перевірка чи потрібно зчитувати дані
        printf("Read file:");
        for(int i = 0; i < count; i++){
            fread(&sum, sizeof(int), 1, foutb);
            printf("%2d ", sum);
        }
        printf("\n");
     fclose(foutb);
    return 0;
}
