#include <stdio.h>

struct Node {
    char data; // ������, �� ���������� � �����
    struct Node *next, *prev;
};
typedef struct Node* PNode;
typedef struct  {
   PNode Head; // ��������� ����������� �������
   PNode Tail;    // � �������� �����
}Stack;
int main()
{
    printf("Hello World!\n");
    return 0;
}
char Pop (Stack *S ) // ������� ��������� � ��������� ���������� ����� �����

{
    PNode TopNode = *S.Head; // �������� �� ������� �����
    char x;
    if (!TopNode ) // ���� ���� ������ (TopNode==NULL) -
    return char(255); // �� ��������� ������ � ����� 255
    x = TopNode->data; // �������� ������ � ������� �����
    *S.Head = TopNode->next; // ���������� �������� ������� �� ��������� �����
    // ���� ����� � ����� ����� ���� - S.Head ������ �������� NULL
    if (*S.Head) // ���� ���� �� ��������� ������
    *S.Head->prev = NULL; // ���������� �������� prev �����, ���� ���� ��������
    else *S.Tail = NULL; // ������ - ���������� ����� �������� �� �����
    free(TopNode); // ��������� ������ �� �������� TopNode
    return x; // ��������� � ������� �������� ������ � ������� �����

}
