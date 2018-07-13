#include <iostream>
#include <string.h>
using namespace std;
struct Node {
    char word[40]; // знайдене слово
        int count; // кількість повторень в тексті
        Node* next; // покажчик на наступний вузол (інше слово)
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
    PNode NewNode = (PNode)malloc(sizeof(Node)); // покажчик на нову структуру (дані про слово)
    strcpy(NewNode->word, NewWord); // записати в структуру знайдене слово
    NewNode->count = 1;                       // ініціалізація лічильника повторень слова в тексті
    NewNode->next = NULL;                  // для самої першої структури - наступного вузла ще немає
    return NewNode;
}
void AddFirst (PNode* Head, PNode NewNode) // процедура додавання на початок списку
{ // покажчик Head передається за посиланням (PNode*), оскільки він зміниться в процедурі
    NewNode->next = *Head; // для всталеного вузла наступний буде той, що перед цим був Head
    // адреса Head отримується шляхом розіменування покажчика на покажчик (*Head)
    *Head = NewNode; // покажчик Head тепер вказує на новий вузол
}
void AddAfter (PNode p, PNode NewNode)
{// в процедуру передаємо адресу заданого вузла p і адресу нового вузла NewNode

    NewNode->next = p->next; // встановлюємо посилання в новому вузлі на вузол, що слідує за ним
    p->next = NewNode;           // встановлюємо посилання в заданому вузлі на новий вузол

}
void AddBefore(PNode* Head, PNode p, PNode NewNode)

{ // пам'ятаємо, що Head - покажчик на покажчик, тому там, де треба - розіменовуємо

if (*Head == p) { // якщо заданий вузол - перший у списку,

AddFirst(Head, NewNode); // реалізуємо відповідну процедуру

return;

} // в протилежному випадку -

PNode q = *Head; // вводимо допоміжну адресу із значенням Head

while (q && q->next!=p) // поки не пройшли весь список (q!=NULL) - шукаємо вузол, який стоїть перед заданим (щоб q->next==p)

q = q->next; // рухаємося по списку - переприсвоюємо q адресу наступного вузла

if ( q ) // умова виконується, якщо вузол із заданою адресою p існує, інакше після проходження всього списку q==NULL

AddAfter(q, NewNode); // виконуємо процедуру вставки нового вузла після вузла, що стоїть перед заданим

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
