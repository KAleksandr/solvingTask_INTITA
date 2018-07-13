#include <stdio.h>
struct Node {
        char word[40];
        int count;
        struct Node *next, *prev;
};

typedef struct Node* PNode;
PNode Head = NULL, Tail = NULL;
void AddFirst(PNode *Head, PNode *Tail, PNode NewNode);
int main()
{
    printf("Hello World!\n");
    return 0;
}
void AddFirst(PNode *Head, PNode *Tail, PNode NewNode)
{
    NewNode->next = *Head;
        NewNode->prev = NULL;
        if ( Head ) *Head = NewNode; // ���� ������ ��� �� ������ - ������� �������� prev ���������� ���������� �����
         *Head = NewNode;
        if (!Tail )
            Tail = Head; // ���� ������ ��� ������ - ������� �������� �� �����

}
void AddLast (PNode *Head, PNode *Tail, PNode NewNode)

{
    NewNode->prev = *Tail;
        NewNode->next = NULL;
        if ( Tail ) *Tail = NewNode; // ���� ������ ��� �� ������ - ������� �������� next ���������� ����������� �����
        *Tail = NewNode;
        if ( ! Head ) Head = Tail; // ���� ������ ��� ������ - ������� �������� �� �������
}
void AddAfter (PNode *Head, PNode *Tail, PNode p, PNode NewNode)
{
        if ( !p->next ) // ���� ������� ����� � � ������� � ������ (p->next==NULL) -
            AddLast (Head, Tail, NewNode); // ���������� � ����� ������
            // ��������� AddLast () - ������������ �� ��������� AddFirst ()
        else { // ������ - ������� ��������� � �������� ������:
            NewNode->next = p->next; // �������� �� �����, ��������� �� NewNode
            NewNode->prev = p; // �������� �� �����, ��������� �� NewNode
            p->next->prev = NewNode; // NewNode ���� ��������� �� �����, ���� ������� �� ������� ������ p
            p->next = NewNode; // NewNode ���� ��������� �� �������� ����� p
        }

}

void AddBefore (PNode *Head, PNode *Tail, PNode p, PNode NewNode)
{
    if ( !p->prev ) // ���� ������� ����� � � ������ � ������ (p->prev==NULL) -
        AddFirst (Head, Tail, NewNode); // ���������� �� ������� ������
    else { // ������ - ������� ��������� � �������� ������:
        NewNode->next = p; // �������� �� �����, ��������� �� NewNode
        NewNode->prev = p->prev; // �������� �� �����, ��������� �� NewNode
        p->prev->next = NewNode; // NewNode ���� ��������� �� �����, ���� ������� ����� ������� ������ p
        p->prev = NewNode; // NewNode ���� ��������� �� �������� ����� p
    }

}
