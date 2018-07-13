#include <stdio.h>

/*Підраховує кількість елементів в ряді
 В цій функції я рекурсії не використовував,
 натомість рекурсію використав у функції fullArray
 для знаходження величин sum[i]=(i+1)+sum[i-1];
*/
int arrayN(int number){
    int i=1;
    int sum =0;
    while (sum <= number){
        sum +=  i;
        if(sum >= number) break;
        i++;
    }
    return i;
}

//Запит на введення числа
void inputNumber(int *number){
    printf("Input number: ");
    scanf("%i", number);
}

/* масив заповнюється величинами: sum[i]=(i+1)+sum[i-1];
 * де (i+1) - чергове натуральне число, sum[i-1] - сума попередніх чисел натурального ряду.
 */
void sumArray(int N){
    int* sum;
    sum = (int*)calloc(N,sizeof(int));// ініціалізація ідентифікатора і виділення пам’яті
    if (sum == NULL) {           // перевірка на успішність виділення пам’яті
        printf("Memory allocation error!");
        return;                  // вихід з програми в разі збою виділення пам’яті
    }
    for(int i = 0; i <N; i++){
        sum[i] = fullArray(i);
        printf("%i ", sum[i]);
    }
    free(sum);             // звільняємо виділену пам’ять по завершенні використання масиву
}

// Рекурсивна функція знаходження велечини sum[i]=(i+1)+sum[i-1];
int fullArray(int N){
    if(N==0) return 1;
    return (N + 1) + fullArray(N-1);
}

int main()
{
    int number;
    int N;
    inputNumber(&number);
    N = arrayN(number);
    sumArray(N);
    return 0;
}
