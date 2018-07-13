#include <stdio.h>

enum restype {PLACE, SCORE}; // ��������� ������������� � ����������� ���� ������:
                            //CARD == 0, CHECK == 1
union results{     // ��� ��� ����� ������� ��������� �� �ᒺ������ -
        char name[25];	// ���� ����� ����������� ��� �������,
        int score;		// ��� �����
    };

struct Club{	// ��������� ��������� ����� ��� �����
    enum restype info;	// ��� ������� - ������� CARD ��� CHECK
    union results res; // ��� ��� ������� ����� �������
    char name[25];
    char  sity[25];
};
int main()
{
    struct Club myClub;

        scanf("%d",&myClub.info);
        switch (myClub.info){	// � ��������� �� ���� ������� - ������ ���:
            case PLACE: printf("Input data of place: "); // ��� ������
                        scanf("%s",myClub.res.name);
                        break;
            case SCORE:  printf("Input data of score: "); // ��� ���
                        scanf("%d",&myClub.res.score);
                        break;
        }

        switch (myClub.info){	// � ��������� �� ���� ������� - ������� ���:
            case PLACE: printf("Pay of card: %s",myClub.res.name); break; // ��� ������
            case SCORE: printf("Pay of check: %ld", myClub.res.score); break; // ��� ���
        }
        fflush(stdin);
        getchar();
    return 0;
}

