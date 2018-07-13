#include <stdio.h>

enum paytype {CARD, CHECK}; // ��������� ������������� � ����������� ���� ������:
                            //CARD == 0, CHECK == 1
union payment{     // ��� ��� ����� ������� ��������� �� �ᒺ������ -
        char card[25];	// ���� ����� ����������� ��� �������,
        long check;		// ��� �����
    };

struct info{	// ��������� ��������� ����� ��� �����
    enum paytype ptype;	// ��� ������� - ������� CARD ��� CHECK
    union payment data; // ��� ��� ������� ����� �������
};
int main()
{
    struct info pay;

        scanf("%d",&pay.ptype);
        switch (pay.ptype){	// � ��������� �� ���� ������� - ������ ���:
            case CARD: printf("Input data of card: "); // ��� ������
                        scanf("%s",pay.data.card);
                        break;
            case CHECK:  printf("Input data of check: "); // ��� ���
                        scanf("%d",&pay.data.check);
                        break;
        }

        switch (pay.ptype){	// � ��������� �� ���� ������� - ������� ���:
            case CARD: printf("Pay of card: %s",pay.data.card); break; // ��� ������
            case CHECK: printf("Pay of check: %ld", pay.data.check); break; // ��� ���
        }
        fflush(stdin);
        getchar();
    return 0;
}
