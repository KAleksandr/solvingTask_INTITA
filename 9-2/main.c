#include <stdio.h>
#include <stdlib.h>
enum restype {PLACE, SCORE}; //
                            //
union results{     //
        int place;
        int score;
    };

struct Club{
    enum restype info;
    union results res;
    char name[25];
    char  sity[25];
};
#define N 7
int main()
{
    struct Club myClub[N];
    //Ввести дані (назва, місто, зайняте місце або кількість очок)
    //про кілька реальних чи умовних клубів, створивши з них масив структур.
    for(int i=0; i<N; i++){
        printf("Input name club: ");
        scanf("%s", &myClub[i].name);
        printf("Input sity: ");
        scanf("%s", &myClub[i].sity);
        printf("[%i] Input change info PLACE(0) or SCORE(1)  ",i+1);
        scanf("%i",&myClub[i].info);
        switch (myClub[i].info){	//
            case PLACE: printf("Input occupied place: "); //
                        scanf("%d",&myClub[i].res.place);
                        break;
            case SCORE:  printf("Input number of points scored: "); //
                        scanf("%d",&myClub[i].res.score);
                        break;
        default: printf("Error of choice!");
            break;
        }
    }
    system("cls");//очистка екрану
    //Для контролю - пройтися по масиву структур і вивести дані (поля) про кожен клуб.
    printf("\n   CLUB: \tCITY: \t\tPLACE: \tSCORE: \n");
    printf("|------------------------------------------------------|\n");
    for(int i =0; i<N; i++){
        printf("[%i] %s ",i+1,myClub[i].name);
        printf("\t%s ",myClub[i].sity);
        switch (myClub[i].info){	//
            case PLACE: printf("\t\t%-d",myClub[i].res.place); break; //
            case SCORE: printf("\t\t\t%d", myClub[i].res.score); break; //
        }
        printf("\n");
    }
    printf("|------------------------------------------------------|\n");
        fflush(stdin);
        getchar();
    return 0;
}
