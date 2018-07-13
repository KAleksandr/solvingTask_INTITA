#include <stdio.h>
#include <malloc.h>

struct Club
{
    char name[25];
    char city[25];
    int place;
    int score;
};
typedef struct Club *pclub;
int main()
{
    int n;
    pclub pmyclub;

    do{
       printf("Input N(0<n<=10): ");
       scanf("%i",&n);
    }
    while(!(n>0 && n<=10));

    pmyclub = (pclub)calloc(n,sizeof(pclub));
    for(int i=0; i<n; i++){
        printf("[%i] Input name (club) ",i+1);
        scanf("%s", pmyclub[i].name);
        printf("Input city (club) ");
        scanf("%s", pmyclub[i].city);
        printf("Input place (club) ");
        scanf("%d", &pmyclub[i].place);
//        printf("Input score (club) ");
//        scanf("%d", &pmyclub[i].score);//заповнює нулями під час виділення пам'яті
    }
    printf("\n   CLUB: \t\tCITY: \t\tPLACE: \t\tSCORE: \n");
    printf("|-----------------------------------------------------------------|\n");
    for(int i=0; i<n; i++){
        printf("[%i] %s",i+1,pmyclub->name);
        printf("\t\t\t%s ",pmyclub->city);
        printf("\t\t%d",pmyclub->place);
        printf("\t\t%d\n", pmyclub->score);
        pmyclub++;
        printf("|-----------------------------------------------------------------|\n");
    }
    free(pmyclub);//звільнення пам'яті
    pmyclub = NULL;
    return 0;
}
