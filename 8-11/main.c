#include <stdio.h>
#include<stdlib.h>
typedef struct {
    char name[50];
    char city[50];
    int score;
}Club;
void sortClub(Club *pmyClub, int size);//���������� �� ��������� ������� ���� �����
int main()
{
    int n,hasRead = 3;
    printf("Input number (1...15): ");
    scanf("%i", &n);
    Club tmp;
    Club *myClub;
    //������� �������� ������ ��� ������ � n ��������;
    myClub = (Club*) malloc(sizeof(Club)*n);
    Club *pmyClub, *ptmp;//��������� �� ���������
    pmyClub = myClub;
    ptmp = &tmp;

    FILE *ft;
    ft = fopen("clubs.txt","r");
    if(ft==NULL){//�������� �������� �����
        printf("File not found.");
        return 0;
    }
    int size=0;
    //��������� � ��������� ����� ����������� ������� �������
    //����� ��� ����� (���� ������� ����� � ���� ����� n);
    while (hasRead == 3 && size != n) {
        hasRead=fscanf(ft, "%s %s %i", pmyClub[size].name,pmyClub[size].city,&pmyClub[size].score);
        size++;
    }
    if(hasRead== -1)
        size--;
    fclose(ft);
    //size - ������� �������� �������� ���� Club;

    //����������
    sortClub(pmyClub,size);
    //�������� ����������
    for(int i=0;i<size; i++){//�������� ������������ �����
        printf("%-12s %-15s - %3d\n",pmyClub[i].name,pmyClub[i].city, pmyClub[i].score);
    }

    FILE *fb = fopen("myClub.dat", "w+b");//��������� ������� ���� �� �����/�������
    fwrite(pmyClub, sizeof(Club),size,fb);
    free (myClub);//��������� ���� � ���'�� ������� ��� ������.
    long int cl_size = ftell(fb)/sizeof(Club); //������� ��������� ����� � ����
    //(����� ���� ������������ ������ size). ��� ������ �������� ������
    rewind(fb);//���������� �������� �� ������� ����� (������)


     int n_club;
    printf("\nInput club number in order of file: ");
    scanf("%i",&n_club);//������ � ��������� ����� n_club (����� ����� �� ������� � ����),

    // ���������� ���������� ����� ��� ����
    if(n_club <= cl_size && n_club>0){
        fseek(fb,(long)sizeof(Club)*(n_club-1), SEEK_SET);
        fread(ptmp, sizeof(Club), 1, fb);
    }
    else{
        printf("There is no such record!!!");
        fclose(fb);
        return -1;
    }
    //�������� ������, ���� �� ����� ������� �����
        printf("%-12s %-15s - %3d\n",ptmp->name,ptmp->city,ptmp->score);
    fclose(fb);
    return 0;
}
//���������� �� ��������� ������� ���� �����
void sortClub(Club *pmyClub, int size)
{
    Club tmp;//� ����� ����� �������� ������ �������� ��������� ���������
    int max;
    for(int i=0; i<size-1;i++){
        max=i;
        for(int j=i+1; j<size;j++){
            if(pmyClub[i].score < pmyClub[j].score)
                if(pmyClub[max].score< pmyClub[j].score)
                   max = j;
         }
        tmp=pmyClub[i];
        pmyClub[i]=pmyClub[max];
        pmyClub[max] = tmp;
    }
}
