#include <stdio.h>
struct Node {
    char data; // ������, �� ���������� � �����
    struct Node *next, *prev;
};
typedef struct Node* PNode;


int main()
{
    printf("Hello World!\n");
    return 0;
}
void Push ( Stack *S, char x) // ��������� ��������� ����� � ����

{// &S - ��������� �� ��������� � ����������� �����; � - ������, �� ��������� � ����

    PNode NewNode; // �������� �� ����� �����
    NewNode = (PNode)calloc(1,sizeof(struct Node));; // �������� ������ �� ����� �����
    NewNode->data = x; // �������� ������ � ����� �����
    NewNode->next = *S.Head; // ������������ � ������ ���� �������� next �� ������� �����-������� (Head),
    NewNode->prev = NULL; // � �������� prev - ����������
    if (*S.Head ) // ���� ���� ��� �� ������ -
    *S.Head->prev = NewNode; // � ���������� ����-������ �������� prev ������������ �� ����� ������� ����� NewNode
    *S.Head = NewNode; // ��� ���� - �������� ������� �����
    if (!*S.Tail ) *S.Tail = *S.Head; // ������� �������� �� ����� (���� ���� ��� ��������� ������)
}
