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
typedef struct Club *pclub;
void printClub(pclub pmyclub, int n);

int main()
{
    int n;
    pclub pmyclub;

    do{
       printf("Input N(0<n<=10): ");
       scanf("%i",&n);
    }
    while(!(n>0 && n<=10));

    pmyclub = (pclub)malloc(n*sizeof(pmyclub));
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
 //��������� ���'��
    free(pmyclub);
    pmyclub = NULL;
    printClub(pmyclub, n);

    getchar();
    return 0;
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

/*
 * ϳ��� ��������� ���'�� ������ ������� ���� �������� ��������� � NULL,
 * ����� �������� pmyclub = NULL. ���� ��������� �������� NULL, �������� ��� ��������, ������ �������,
 * �� ��� ����� �� �����. ������ ���� ���������� ���'��, ��� ����������� ��������� NULL,
 * � ������ �������, ����� ���� ���������� ���'��, �������� ��� ���� �� �� �����,
 * � ������� ��������� ����� ������� ����� ����� ���������,
 * ��, ������� ������ ��������������� �� ���'���, ��� �� ����� ����� ��� �� �� �������� � ������ ������,
 * �� �������� ������ ��������.
 */
