#include <stdio.h>
#include <malloc.h>
#include<string.h>
struct Club
{
    char name[25];
    char city[25];
    int place;
    int score;
};
typedef struct Club *pclub, club;
void printClub(pclub pmyclub, int n);
void sortClub(pclub pmyClub, int size);
void copyClub(pclub pclub2,pclub pclub, int size);
int main()
{
    int n;
    pclub pmyclub, pmyclub2;

    do{
       printf("Input N(0<n<=10): ");
       scanf("%i",&n);
    }
    while(!(n>0 && n<=10));

    pmyclub = (pclub)malloc(n*sizeof(pmyclub));
    pmyclub2 = (pclub)malloc(n*sizeof(pmyclub2));
    for(int i=0; i<n; i++){
        printf("[%i] Input name (club) ",i+1);
        //scanf("%s", &pmyclub[i].name);
        fflush(stdin);
        gets(pmyclub[i].name);
        printf("Input city (club) ");
        //scanf("%s", &pmyclub[i].city);
        fflush(stdin);
        gets(pmyclub[i].city);
        printf("Input place (club) ");
        scanf("%d", &pmyclub[i].place);
        printf("Input score (club) ");
        scanf("%d", &pmyclub[i].score);
    }
    printClub(pmyclub, n);

    pmyclub2 = pmyclub;//copy

    sortClub(pmyclub2, n);//sort
    printClub(pmyclub2, n);//print
    pmyclub = realloc(pmyclub, (n-2)*sizeof(pmyclub) );
    copyClub(pmyclub, pmyclub2, n-2);
    printClub(pmyclub, n-2);


    //зв≥льненн€ пам'€т≥
    free(pmyclub);
    pmyclub = NULL;
    free(pmyclub2);
    pmyclub2 = NULL;
    getchar();
    return 0;
}
void sortClub(pclub pmyClub, int size)
{
    club tmp;//з метою обм≥ну структур м≥сц€ми оголошую додаткову структуру
    int min;
    for(int i=0; i<size-1;i++){
        min=i;
        for(int j=i+1; j<size;j++){
            if(pmyClub[i].place > pmyClub[j].place)
                if(pmyClub[min].place > pmyClub[j].place)
                   min = j;
         }
        tmp=pmyClub[i];
        pmyClub[i]=pmyClub[min];
        pmyClub[min] = tmp;
    }
}
void printClub(pclub pmyclub, int n){
    printf("\n   CLUB: \t\tCITY: \t\tPLACE: \t\tSCORE: \n");
    printf("|-----------------------------------------------------------------|\n");
    for(int i=0; i<n; i++){
        printf("[%i] %s",i+1,pmyclub->name);
        printf("\t\t%s ",pmyclub->city);
        printf("\t\t%d",pmyclub->place);
        printf("\t\t%d\n", pmyclub->score);
        pmyclub++;
        printf("|-----------------------------------------------------------------|\n\n\n");
    }
    pmyclub-=n;
}
void copyClub(pclub pclub2,pclub pclub, int size){
    for(int i=0; i<size;i++){
        strcpy(pclub2->name, pclub->name);
        strcpy(pclub2->city, pclub->city);
        pclub2->place=pclub->place;
        pclub2->score = pclub->score;
        pclub++; pclub2++;
    }

}
