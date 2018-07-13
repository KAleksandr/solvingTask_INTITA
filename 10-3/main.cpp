#include <iostream>
#include <string.h>
using namespace std;
struct Node {
    char word[40]; // �������� �����
        int count; // ������� ��������� � �����
        Node* next; // �������� �� ��������� ����� (���� �����)
};
typedef Node* PNode;
PNode CreateNode (char* NewWord);
void AddAfter (PNode p, PNode NewNode);
int main()
{
    PNode Head = NULL;
    return 0;

}
PNode CreateNode (char* NewWord){
    PNode NewNode = (PNode)malloc(sizeof(Node)); // �������� �� ���� ��������� (��� ��� �����)
    strcpy(NewNode->word, NewWord); // �������� � ��������� �������� �����
    NewNode->count = 1;                       // ����������� ��������� ��������� ����� � �����
    NewNode->next = NULL;                  // ��� ���� ����� ��������� - ���������� ����� �� ����
    return NewNode;
}
void AddFirst (PNode* Head, PNode NewNode) // ��������� ��������� �� ������� ������
{ // �������� Head ���������� �� ���������� (PNode*), ������� �� �������� � ��������
    NewNode->next = *Head; // ��� ���������� ����� ��������� ���� ���, �� ����� ��� ��� Head
    // ������ Head ���������� ������ ������������ ��������� �� �������� (*Head)
    *Head = NewNode; // �������� Head ����� ����� �� ����� �����
}
void AddAfter (PNode p, PNode NewNode)
{// � ��������� �������� ������ �������� ����� p � ������ ������ ����� NewNode

    NewNode->next = p->next; // ������������ ��������� � ������ ���� �� �����, �� ���� �� ���
    p->next = NewNode;           // ������������ ��������� � �������� ���� �� ����� �����

}
void AddBefore(PNode* Head, PNode p, PNode NewNode)

{ // ���'�����, �� Head - �������� �� ��������, ���� ���, �� ����� - �����������

if (*Head == p) { // ���� ������� ����� - ������ � ������,

AddFirst(Head, NewNode); // �������� �������� ���������

return;

} // � ������������ ������� -

PNode q = *Head; // ������� �������� ������ �� ��������� Head

while (q && q->next!=p) // ���� �� ������� ���� ������ (q!=NULL) - ������ �����, ���� ����� ����� ������� (��� q->next==p)

q = q->next; // �������� �� ������ - �������������� q ������ ���������� �����

if ( q ) // ����� ����������, ���� ����� �� ������� ������� p ����, ������ ���� ����������� ������ ������ q==NULL

AddAfter(q, NewNode); // �������� ��������� ������� ������ ����� ���� �����, �� ����� ����� �������

}
PNode AddBefore(PNode Head, PNode p, PNode NewNode)
{
    PNode q = Head;
    if (Head == p) {
        Head=AddFirst(Head, NewNode);
        return Head;
    }
    while (q && q->next!=p)
        q = q->next;
    if ( q )
            AddAfter(q, NewNode);
    return Head;
}
PNode AddLast(PNode Head, PNode NewNode)
{
    PNode q = Head;
    if (Head == NULL) {
        Head=AddFirst(Head, NewNode);
        return Head;
    }
    while (q->next) q = q->next;
        AddAfter(q, NewNode);
    return Head;
}
PNode DeleteNode(PNode Head, PNode OldNode)
{
    PNode q = Head;
    if (Head == OldNode){
        Head = OldNode->next;
    //	return Head;
    }
    else {
        while (q && q->next != OldNode)
            q = q->next;
        if (q == NULL) return Head;
        q->next = OldNode->next;
    }
    free(OldNode);
    return Head;
}
