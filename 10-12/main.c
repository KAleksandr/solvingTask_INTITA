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
        if ( Head ) *Head = NewNode; // якщо список був не пустий - змінюємо покажчик prev колишнього “головного” вузла
         *Head = NewNode;
        if (!Tail )
            Tail = Head; // якщо список був пустий - змінюємо покажчик на “хвіст”

}
void AddLast (PNode *Head, PNode *Tail, PNode NewNode)

{
    NewNode->prev = *Tail;
        NewNode->next = NULL;
        if ( Tail ) *Tail = NewNode; // якщо список був не пустий - змінюємо покажчик next колишнього “хвостового” вузла
        *Tail = NewNode;
        if ( ! Head ) Head = Tail; // якщо список був пустий - змінюємо покажчик на “голову”
}
void AddAfter (PNode *Head, PNode *Tail, PNode p, PNode NewNode)
{
        if ( !p->next ) // якщо заданий вузол р є останнім у списку (p->next==NULL) -
            AddLast (Head, Tail, NewNode); // вставляємо в кінець списку
            // процедура AddLast () - “симетрична” до процедури AddFirst ()
        else { // інакше - змінюємо покажчики у потрібних вузлах:
            NewNode->next = p->next; // покажчик на вузол, наступний за NewNode
            NewNode->prev = p; // покажчик на вузол, попередній до NewNode
            p->next->prev = NewNode; // NewNode став попереднім до вузла, який слідував за заданим вузлом p
            p->next = NewNode; // NewNode став наступним до заданого вузла p
        }

}

void AddBefore (PNode *Head, PNode *Tail, PNode p, PNode NewNode)
{
    if ( !p->prev ) // якщо заданий вузол р є першим у списку (p->prev==NULL) -
        AddFirst (Head, Tail, NewNode); // вставляємо на початок списку
    else { // інакше - змінюємо покажчики у потрібних вузлах:
        NewNode->next = p; // покажчик на вузол, наступний за NewNode
        NewNode->prev = p->prev; // покажчик на вузол, попередній до NewNode
        p->prev->next = NewNode; // NewNode став наступним до вузла, який слідував перед заданим вузлом p
        p->prev = NewNode; // NewNode став попереднім до заданого вузла p
    }

}
