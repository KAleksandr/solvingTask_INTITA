#include <stdio.h>
#define N 3

struct Club
{
    char name[25];
    char city[25];
    int place;
    int score;
};
typedef struct Club club, *pclub;
int main()
{
    club myclub[N];
    pclub pmyclub;
    pmyclub = myclub;


    for(int i=0; i<N; i++){
        printf("[%i] Input name (club) ",i+1);
        scanf("%s", &myclub[i].name);
        printf("Input city (club) ");
        scanf("%s", &myclub[i].city);
        printf("Input place (club) ");
        scanf("%d", &myclub[i].place);
        printf("Input score (club) ");
        scanf("%d", &myclub[i].score);
    }
    printf("\n   CLUB: \t\tCITY: \t\tPLACE: \t\tSCORE: \n");
    printf("|-----------------------------------------------------------------|\n");
    for(int i=0; i<N; i++){
        printf("[%i] %s",i+1,pmyclub->name);
        printf("\t\t%s ",pmyclub->city);
        printf("\t\t%d",pmyclub->place);
        printf("\t\t%d\n", pmyclub->score);
        pmyclub++;
        printf("|-----------------------------------------------------------------|\n");
    }
    return 0;
}
