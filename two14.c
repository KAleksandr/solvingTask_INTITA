/*������� ��������� ����� �������� ������
// ���� ������: ����� ������� ��������� (��������������) �� ������ ������ (� �������, ������ �� 1), � �������� - �� ���� �������
// ���� ����: ����� ������� ��������� (��������������) �� ������ ������ (� �������, ������ �� 1), � ������ - �� ���� ����������
*/
#include <stdio.h>


#define N 10
main()
{
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


int i,j, a[N];
int temp; // ��������� �����
	for(i=0; i<N; i++){
		printf("Input a[%d]: ",i);
		scanf("%d", &a[i]);
	} // ������� ����� a[N]
// �������� ���� ������
for (j=0; j<2; j++){

temp = a[0]; // ���a�'����� �������� �������
// ���'������! ������ ������� ����������� a[0], ���� �������� ���� a[N-1]
for ( i = 0; i < N-1; i ++ ) // ���������� ��������, ��������� � ���� ������
a[i] = a[i+1]; // ��������� �������� ���������� ����������, � ��� - �� ������ ������� ������
a[N-1] = temp; // ������� �������� ���������� �������� ����������
}
printf("\n ���������: \n");
for ( i = 0; i < N; i ++ )
printf("%d ", a[i]); // �������� ��������� ������������
}



