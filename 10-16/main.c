#include <stdio.h>
#include <string.h>
struct Node
{
    char nameTeam[50];
    char  city[50];
    char country[50];
    float rbd;
    int place;
    int count;
    struct Node * next, * prev;
};
typedef struct Node* PNode;


PNode CreateNode(char nameTeam[],char city[], char country[], float rbd, int place)
{
 PNode NewNode = (PNode)calloc(1,sizeof(struct Node));

 strcpy(NewNode->nameTeam,nameTeam);
 strcpy(NewNode->city, city);
 strcpy(NewNode->country, country);
 NewNode->rbd = rbd;
 NewNode->place = place;
 NewNode->count = 1;
 NewNode->next = NULL;
 NewNode->prev = NULL;
 return NewNode;
}

// додавання вузла в "голову"
void AddHead(PNode* Head, PNode* Tail, PNode NewNode)
// оскільки функція змінює і повинна повернути 2 значення - Head i Tail,
// передаємо в неї АДРЕСИ цих покажчиків - тобто, покажчик на покажчик
{
 NewNode->next = *Head; // з цієї причини - в потрібних місцях РОЗІМЕНОВУЄМО покажчики на Head i Tail
 NewNode->prev = NULL; // у "головного" вузла попередній вузол - відсутній
 if (*Head) (*Head)->prev = NewNode;  // якщо в списку вже є вузли (Head не нульовий) -
 // покажчик prev раніше створеного "головного" вузла замикаємо на новий вузол
 *Head = NewNode; // а новий вузол стає "головним"
 if (!(*Tail)) *Tail = *Head; // якщо список був пустий (одна із ознак цього - нульовий Tail) -
}// новий вузол стає одночасно "головою" і "хвостом"

// додавання вузла в "хвіст"
void AddTail(PNode* Head, PNode* Tail, PNode NewNode)
// так само - функція приймає 2 параметри типу "покажчик на покажчик",
{
 NewNode->prev = *Tail; // які в потрібних місцях розіменовуємо
 NewNode->next = NULL;
 // далі - все по аналогії процедури AddFirst (тільки Head i Tail міняються місцями)
 if (*Tail) (*Tail)->next = NewNode;
 *Tail = NewNode;
 if (!(*Head)) *Head = *Tail;
}

// додавання вузла після заданого, з адресою в покажчику p
void AddAfter(PNode p, PNode NewNode)
{
      NewNode->next = p->next;
      NewNode->prev = p;
      p->next->prev = NewNode;
      p->next = NewNode;
}

// пошук прочитаного слова у списку
PNode Find(PNode Tail, char country[])
{
 PNode q = Tail->prev;
 while (q && strcmp(q->country, country))
    q = q->prev;
 return q;
}

//PNode FndForvard(PNode Head, char NewWord[])
//{
// PNode q = Head->next;
// while (q && strcmp(q->word, NewWord))
//    q = q->next;
// return q;
//}

//PNode FndPlaceRet(PNode Tail, char NewWord[])
//{
// PNode q = Tail->prev;
// while (q->prev && (strcmp(q->word, NewWord) > 0))
//    q=q->prev;
// return q;
//}

PNode FndPlaceFwd(PNode Head, char NewWord[])
{
 PNode q = Head->next;
 PNode p = Head;
 while (q->next && (strcmp(q->word, NewWord) < 0)){
    p=q;
    q=q->next;
 }
 return p;
}
// пошук першого вузла на потрібну початкову літеру
PNode fndStart(PNode Head, char c)
{
 PNode p = Head->next;
 while (p->next) {
    if(p->word[0]==c)
        return p;
    p = p->next;
 }
}
// підрахунок кількості вузлів від деякого стартового і до "голови"
int fndNodeAddrToHead(PNode p, PNode Head, char kind[])
{
 int count=0;
 while (p->prev) {
    if(p->prev==Head)
        printf("%s node address is %p\n",kind,p);
    count++;
    p = p->prev;
 }
 return count;
}

// підрахунок кількості вузлів від деякого стартового і до "хвоста"
int fndNodeAddrToTail(PNode p, PNode Tail, char kind[])
{
 int count=0;
 while (p->next) {
    if(p->next==Tail)
        printf("%s node address is %p\n",kind,p);
    count++;
    p = p->next;
 }
 return count;
}
void Delete(PNode *Head, PNode *Tail, PNode OldNode)

{ // OldNode - адреса вузла, що видаляється
    if (*Head == OldNode) {       // якщо видаляємий вузол є першим у списку -
        *Head = OldNode->next; // пересуваємо покажчик Head на адресу наступного вузла
                                             // якщо видалений вузол - єдиний в списку, то Head встановиться в NULL
        if (*Head)                      // якщо вузли в списку залишилися -
            *Head = NULL; // “обнуляємо” покажчик prev у вузла, який став першим
        else *Tail = NULL;         // інакше - “обнуляємо” також і “хвіст”
    }
    else { // якщо видаляємий вузол - не перший в списку,
        OldNode->prev->next = OldNode->next;
        // пересуваємо покажчик next у попереднього вузла на вузол, що був наступним за видаленим
        if ( OldNode->next ) // якщо видалений вузол - не останній,
            OldNode->next->prev = OldNode->prev; // пересуваємо покажчик prev у наступного вузла на вузол, що стояв перед видаленим
        else *Tail = OldNode->prev; // пересуваємо покажчик Tail на адресу вузла, що стояв перед видаленим
    }
   free(OldNode);                 // видаляємо вузол з пам’яті
}

void Circled (PNode *Head, PNode *Tail)

{

(*Head)->prev=*Tail;

(*Tail)->next=*Head;

*Tail=NULL;

}

main()
{
// Алфавітно-частотний словник
 PNode p, where;
 FILE *in, *out;
 char word[40];
 int n,nHead,nTail;
 int cNodes=0; // лічильник вузлів
 PNode Head = NULL, Tail = NULL;

// creating borders
// left border
 p = CreateNode("00000");
 p->count=0;
 AddHead(&Head,&Tail,p);
//right border
 p = CreateNode("00000");
 p->count=0;
 AddTail(&Head,&Tail,p);

 SetConsoleCP(1251);
 SetConsoleOutputCP(1251);
 in = fopen("input1.txt","r");
 if (in) printf("Файл відкрито успішно! Press ENTER\n");
 getchar();

 while (1) {
    n = fscanf(in,"%s",word); // читаємо слово з файлу
    if (n<=0) break;
    nHead=strcmp(Head->next->word, word); // визначаємо, до якого кінця списку
    nTail=strcmp(Tail->prev->word, word); // прочитане слово знаходиться ближче
    if (nHead>nTail)
       p = FndReturn(Tail,word); // шукаємо слово в списку, починаючи з хвоста
    else p = FndForvard(Head,word); // або з голови
    if (p) // якщо знайшли слово,
       p->count++; // збільшити лічильник
    else { // якщо ж слово нове -
         p = CreateNode(word); // створюємо новий вузол
         if (nHead>nTail)
            where = FndPlaceRet(Tail,word); // шукаємо місце вставки від хвоста
         else where = FndPlaceFwd(Head,word); // або від голови
         AddAfter(where,p); // вставляємо новий вузол в список
    }
 }
 fclose(in);
 printf("Double-linked list create successfull! Press ENTER\n");
 getchar();

 PNode start=fndStart(Head,'л'); // визначаємо вузол, що починається на літеру "л"
 cNodes=fndNodeAddrToHead(start->prev,Head,"First"); // підраховуємо вузли до голови
 cNodes+=fndNodeAddrToTail(start->next,Tail,"Last"); // і до хвоста (сплюсовуємо разом)
 printf("List contains of %d nodes\n",cNodes+1); // на екран - знайдена кількість + "стартовий" вузол

// аналогічно - знаходимо і рахуємо від вузла на літеру "ю"
 start=fndStart(Head,'ю');
 cNodes=fndNodeAddrToHead(start->prev,Head,"First");
 cNodes+=fndNodeAddrToTail(start->next,Tail,"Last");
 printf("List contains of %d nodes\n",cNodes+1);

 out = fopen("output-t1.txt","w");
 p = Head->next;
 while (p->next) { // виводимо список у файл
    fprintf(out, "%-20s\t%d\n", p->word, p->count);
    p = p->next;
 }
 fclose(out);

 getchar();
}
