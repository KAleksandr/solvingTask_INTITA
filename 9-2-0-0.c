#include <stdio.h>

enum restype {PLACE, SCORE}; // оголошуємо перерахування з константами типу оплати:
                            //CARD == 0, CHECK == 1
union results{     // дані про спосіб платежу оголошуємо як об’єднання -
        char name[25];	// один платіж здійснюється або карткою,
        int score;		// або чеком
    };

struct Club{	// оголошуємо структуру даних про платіж
    enum restype info;	// тип платежу - відповідає CARD або CHECK
    union results res; // дані про обраний спосіб платежу
    char name[25];
    char  sity[25];
};
int main()
{
    struct Club myClub;

        scanf("%d",&myClub.info);
        switch (myClub.info){	// в залежності від типу платежу - ввести дані:
            case PLACE: printf("Input data of place: "); // про картку
                        scanf("%s",myClub.res.name);
                        break;
            case SCORE:  printf("Input data of score: "); // про чек
                        scanf("%d",&myClub.res.score);
                        break;
        }

        switch (myClub.info){	// в залежності від типу платежу - вивести дані:
            case PLACE: printf("Pay of card: %s",myClub.res.name); break; // про картку
            case SCORE: printf("Pay of check: %ld", myClub.res.score); break; // про чек
        }
        fflush(stdin);
        getchar();
    return 0;
}

