#include <stdio.h>

#define M 5 // кількість рядків

#define N 4 // кількість стовпців



main()

{

    int i, j, a[M][N];

    FILE *fp;



    fp = fopen("input.dat", "r");

    // перевіка на відсутність помилки при відкритті файлу

        for ( i = 0; i < M; i ++ ) // цикл по рядкам
            for ( j = 0; j < N; j ++ ) // цикл по стовпцям
                if ( 0 == fscanf(fp,"%d",&a[i][j]) ) {  // читаємо дані в масив а[i][j], одночасно перевіряємо, чи не натрапили на кінець файлу або на некоректні дані
                        puts("Даних у файлі не вистачає");
                        fclose ( fp ); // закриваємо файл через помилку
                        return; // вихід з програми через помилку
                }

    fclose ( fp ); // закрити файл після успішного зчитування даних

     // обробка зчитаної матриці

}
