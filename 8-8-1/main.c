#include <stdio.h>
#include <conio.h>
#define N 30
typedef struct
{
   char name [N];
   char city[N];
   int place;
}Club;

int main()
{
    int count=0;
    int k=1;
    Club myClub[7];
    Club *pmyClub = &myClub[0];
    FILE * file, *temp;

    file = fopen("teams.dat", "ab");
    /*
     * �������� ����, � ����� �� ���� (�� ����� 7-�� ����!):
     *- ������ � ��������� �������� ���� ����� ���� Club;
     *- �������� ������� ��������� (��� ��� ����) � ���� teams.dat ;
     */
    /*
     *�������� ��������� ����� � ����� ���� Club � ������� ���� ���� �������� ����� � ���������,
     * ��������� ����� � ����.
     * ���� ��������� �� ����� ���� Club, � ������ ����� � ����, ���� ����� ���� ���������� ������(�� ����� 7-��).
     * ����� ����� ���������� �������� ����� ���� ����� ���� CLUB - � ���� ������� ������!
     * ������� ������ � ����: ��� ���������� ������� �������� �����,
     *                         ��� �� ���������� ���������� ������ ��������
     */
    while(k++){

        printf("Enter the name of the team: ");
        gets(pmyClub[count].name);
        printf("Enter the city of the team: ");
        gets(pmyClub[count].city);
        printf("Enter the place in the team championship: ");
        scanf("%d", &pmyClub[count].place);
        fflush(stdin);
        count++;
        if(count==7 || k>7){//(�� ����� 7-�� ����!)
            if(count==7){
                fwrite(pmyClub, sizeof(Club), count, file);
                count=0;
            }
            printf("You want to continue? (y/n):");//����� ���������� ��������
            char c;
            c =getch();
            if(c == 'n'|| c =='N'){
                if(count >0)
                    fwrite(pmyClub, sizeof(Club), count, file);
                k=0;
            }
            getch();
        }

    }
    fclose(file);
    file=fopen("teams.dat", "rb");


//���� �������� ����� � ������� ���� � ����� �������  � ��������� � ����� ����� 3 ��������� ;
    fread(myClub, sizeof(Club), 3, file);
//�������� ��� �������� � ����� �������� ���� (���������, teams1.dat);
    temp = fopen("teams1.dat", "wb");
    fwrite(myClub, sizeof(Club), 3,temp);
    fclose(file);
    fclose(temp);
//������������� ���� ������� � ����� �������,
//���� ���� ������� �� �����, ������������ � ���������� ����������� ����� � ������ �����.
    temp = fopen("teams1.dat","rb");
    fread(myClub, sizeof(Club), 3, temp);
    for(int i=0; i<3; i++)
        printf("\nRezult: %s %s - %d", myClub[i].name,myClub[i].city,myClub[i].place);
    fclose(temp);
    return 0;
}
