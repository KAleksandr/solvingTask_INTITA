//Реалізуй програму, що виконує наступні дії:
//1) приймає з клавіатури деяке N-цифрове додатне ціле число (з перевіркою на додатність
//і на кількість цифр за допомогою циклу do-while);
//2) за допомогою процедури Div() розбиває його на окремі цифри (справа наліво), які записує в масив;
//3) приймає з клавіатури число K- номер деякої цифри, починаючи з 1;
//4) за допомогою функції NSymbol() знаходить і повертає K-ту цифру в числі,
//рахуючи зліва направо (функцію викликати, якщо K<=N, інакше вивести повідомлення про помилку).
#include <stdio.h>
int k=0;
int n=0;
int a[10];
void Div();
void NSymbol();

int main()
{
    do{
        printf("Input numbers (1 - 10000000): ");
        scanf("%i",&n);
    }
    while(!(n>0 && n<=10000000));
    Div();
    if(k<=n){
        NSymbol();
    }
    else {
        printf("\nError!!!\n");//ця умова не буде виконуватись, так на К накладена умова
    }
    return 0;
}
void Div(){
    int num=n;
    int i=0;
    while(num>0){
        a[i] = num%10;
        num/=10;
        i++;
    }
    do{
        printf("Input number K: ");
        scanf("%i",&k);
        if(!(k>0&&k<=i)) {
            printf("\nError!!!\n");
            printf("Imput k>0 and k<= %i\n",i);
        }
    }
    while(!(k>0&&k<=i));
}
void NSymbol(){
    printf("Number (%i with %i) - %i\n", k,n,a[k-1]);
}