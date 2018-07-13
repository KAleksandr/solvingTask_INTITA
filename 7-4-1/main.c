#include <stdio.h>

#define N 10 // фіксуємо потрібну кількість елементів масиву
int main(void)

{

    int i, n, A[N];

    FILE* fp; // дескриптор файлу

    fp = fopen( "file_bin", "rb" ); // відкрити двійковий файл на читання
    n = fread ( A, sizeof(int), N, fp ); // читаємо в масив потрібну кількість чисел
    if ( n < N ) { // якщо чисел у файлі менше - помилка!
        printf("Reading error");
    return;
    }
    fclose ( fp ); // закрити файл
    for ( i = 0; i < N; i ++ )
        A[i] = A[i];// * 2; // модифікуємо прочитаний масив
    fp = fopen( "output.dat", "wb" ); // відкрити двійковий файл на запис
    fwrite ( A, sizeof(int), N, fp ); // записати масив у файл
    fclose ( fp ); // закрити файл
}
