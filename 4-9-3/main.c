#include <stdio.h>
#include<time.h>
#define M 3
#define N 3
int main()
{
    int a[N][M];
    int sar, min;
   srand(time(0));
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            a[i][j] = 1+rand()%10; //випадкові числа
            //a[i][j] = 1.0 +1.0(rand()%91)/10; до 90 результат дробове 0-9 за рахунок +1 буде 1-10
        } // формат дробових %5.1f якщо %-5.1f вирівнювання по лівій стороні
     }//setw(4) c++!!!
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            printf("%4i", a[i][j]);
        }
        printf("\n");
    for(int i =0; i< M; i++){
        sar =0;
        for(int j=0; j<M; j++){
            sar+=a[i][j];
        }
    }


        sar/=N;
        min = abs(sar-a[i][0]);
        for(int j=1; j<N; j++)
            if(abs(sar-a[i][j])< min) min = abs(sar- a[i][j]);
        for(int j = 0; j<N; j++)
            if(abs(sar-a[i][j])==min) a[i][j]= sar;
        }
    printf("\n");
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            printf("%4i", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
