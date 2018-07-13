#include <stdio.h>
#include <string.h>

int main(void)

{
    char str1[] = "Australia"; // ініціалізуємо
    char str2[] = "Austria"; // два рядки
    int n;

    while(1){
        do{//цикл do-while використав для перевірки введення числа від 0 до 9
        printf("Input number: ");
        scanf("%i",&n);

        fflush(stdin);
        }
        while(!(n>0 && n <= 9));

        if ( 0 == strncmp(str1,str2,n) ){ // якщо рядки однакові -
            printf("String %s is identical to %s\n", str1, str2); // констатуємо це
            break;
        }
        else printf("String %s is not identical to %s\n", str1, str2); // інакше - заперечуємо
    }

}
