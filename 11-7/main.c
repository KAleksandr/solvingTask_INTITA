#include <stdio.h>

int main()
{
    printf("Hello World!\n");
    return 0;
}
int PopHead ( Quere *Q ) // ������� �����e��� ����� � ������� �����

{
    PNode TopNode = *Q.Head; // �������� �� ������� �����
    int x;
    if ( ! TopNode ) // ���� ����� ����� (TopNode==NULL) -
    return 0; // �� ��������� ����� 0
    x = TopNode->data; // �������� ����� � ������� �����
    *Q.Head = TopNode->next; // ���������� �������� ������� ����� �� ��������� �����
    // ���� ����� � ���� ����� ���� - Q.Head ������ �������� NULL
    if (*Q.Head ) // ���� ����� �� ���������� ����� -
    *Q.Head->prev = NULL; // ���������� �������� prev �����, ���� ���� �������� �����
    else *Q.Tail = NULL; // ������ - ���������� ����� �������� �� ����� �����
    free(TopNode); // ��������� ������ �� ��������� �������� TopNode
    return x; // ��������� � ������� �������� ����� � ������� �����

}
