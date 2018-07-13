#include <stdio.h>

enum paytype {CARD, CHECK}; // оголошуємо перерахування з константами типу оплати:
                            //CARD == 0, CHECK == 1
union payment{     // дані про спосіб платежу оголошуємо як об’єднання -
        char card[25];	// один платіж здійснюється або карткою,
        long check;		// або чеком
    };

struct info{	// оголошуємо структуру даних про платіж
    enum paytype ptype;	// тип платежу - відповідає CARD або CHECK
    union payment data; // дані про обраний спосіб платежу
};
int main()
{
    struct info pay;

        scanf("%d",&pay.ptype);
        switch (pay.ptype){	// в залежності від типу платежу - ввести дані:
            case CARD: printf("Input data of card: "); // про картку
                        scanf("%s",pay.data.card);
                        break;
            case CHECK:  printf("Input data of check: "); // про чек
                        scanf("%d",&pay.data.check);
                        break;
        }

        switch (pay.ptype){	// в залежності від типу платежу - вивести дані:
            case CARD: printf("Pay of card: %s",pay.data.card); break; // про картку
            case CHECK: printf("Pay of check: %ld", pay.data.check); break; // про чек
        }
        fflush(stdin);
        getchar();
    return 0;
}
