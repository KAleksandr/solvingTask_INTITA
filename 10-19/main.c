#include <string.h>
#include <stdio.h>
#include <malloc.h>

struct Node {
       char word[40];
       int count;
       struct Node *next, *prev;
};

typedef struct Node* PNode;

// структура "точок входу" двозв'язного списку
struct List{
  PNode Head;
  PNode Tail;
};


PNode CreateNode(char NewWord[])
{
 PNode NewNode = (PNode)calloc(1,sizeof(struct Node));
 strcpy(NewNode->word, NewWord); // записати у вузол слово
 NewNode->count = 1; // лічильник слів = 1
 NewNode->next = NULL; // наступного вузла поки що немає
 NewNode->prev = NULL; // попереднього - теж
 return NewNode; // результат функції – адреса вузла
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

// додавання вузла перед заданим, з адресою в покажчику p
void AddBefore(PNode p, PNode NewNode)
{
      NewNode->prev = p->prev;
      NewNode->next = p;
      p->prev->next = NewNode;
      p->prev = NewNode;
}

// пошук прочитаного слова у списку з "хвоста"
PNode FndReturn(PNode Tail, char NewWord[])
{
 PNode q = Tail->prev;
 while (q && strcmp(q->word, NewWord))
    q = q->prev;
 return q;
}

// пошук прочитаного слова у списку з "голови"
PNode FndForvard(PNode Head, char NewWord[])
{
 PNode q = Head->next;
 while (q && strcmp(q->word, NewWord))
    q = q->next;
 return q;
}

// пошук місця вставки нового слова у список з "хвоста"
PNode FndPlaceRet(PNode Tail, char NewWord[])
{
 PNode q = Tail->prev;
 while (q->prev && (strcmp(q->word, NewWord) > 0))
    q=q->prev;
 return q;
}

// пошук місця вставки нового слова у список з "голови"
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

// видалення вузла
void Delete(PNode OldNode)
{
    OldNode->prev->next = OldNode->next;
    OldNode->next->prev = OldNode->prev;
    free(OldNode);
}

// створюємо новий список за однією і тією ж процедурою
void CreateList(FILE* in, PNode Head, PNode Tail)
{
 char word[40];
 int n,nHead,nTail;
 PNode p,where;

 while (1) {
    n = fscanf(in,"%s",word);
    if (n<=0) break;
    nHead=strcmp(Head->next->word, word);
    nTail=strcmp(Tail->prev->word, word);
    if (nHead>nTail)
       p = FndReturn(Tail,word);
    else p = FndForvard(Head,word);
    if (p)
       p->count++;
    else {
         p = CreateNode(word);
         if (nHead>nTail)
            where = FndPlaceRet(Tail,word);
         else where = FndPlaceFwd(Head,word);
         AddAfter(where,p);
    }
 }
 fclose(in);
 printf("Double-linked list create successfull! Press ENTER\n");
 getchar();
}

int main(void)
{
// оголошуємо 2 списки і обнуляємо їх "точки входу"
   struct List dll1={NULL,NULL},dll2={NULL,NULL};
   PNode q,p,left,right;
   char c_letter;
   FILE *in, *out;

// creating borders
// left border of list1
   q = CreateNode("00000");
   q->count=0;
   AddHead(&dll1.Head,&dll1.Tail,q);
//right border of list1
   q = CreateNode("00000");
   q->count=0;
   AddTail(&dll1.Head,&dll1.Tail,q);
// left border of list2
   q = CreateNode("00000");
   q->count=0;
   AddHead(&dll2.Head,&dll2.Tail,q);
//right border of list2
   q = CreateNode("00000");
   q->count=0;
   AddTail(&dll2.Head,&dll2.Tail,q);

   in = fopen("inp_eng1.txt","r");
   if (in) printf("First file open successfull! Press ENTER\n");
   getchar();
// заповнюємо список словами з першого файлу
   CreateList(in, dll1.Head,dll1.Tail);

   in = fopen("inp_eng2.txt","r");
   if (in) printf("Second file open successfull! Press ENTER\n");
   getchar();

// доповнюємо той самий список словами з другого файлу
   CreateList(in, dll1.Head,dll1.Tail);
// виводимо одержаний великий список у файл
   out = fopen("outt5_1.txt","w");
   q = dll1.Head->next;
   while (q->next) {
    fprintf(out, "%-20s\t%d\n",q->word,q->count);
    q = q->next;
   }
   fclose(out);
// починаємо обхід великого списку
   q = dll1.Head->next;
   while (q->next && q->word[0]!='Q') // поки не "впремося" в "хвіст" або не знайдемо перше слово
    q = q->next;                   // на потрібну літеру
   if (q==dll1.Tail) left=dll1.Head->next; // якщо дійшли до "хвоста" і не знайшли - будемо знову стартувати з початку
   else left=q; // інакше - фіксуємо адресу вузла зі словом на потрібну літеру
// ті самі маніпуляції, тільки навпаки - від "хвоста" і до знаходження (чи не знаходження) іншої літери
   q = dll1.Tail->prev;
   while (q->prev && q->word[0]!='q')
    q = q->prev;
   if (q==dll1.Head) right=dll1.Tail->prev;
   else right=q;

   while(1){
     c_letter=left->word[0]; // фіксуємо першу (зліва) опорну літеру
     q=left;
     while (q->next->word[0]==c_letter) // обходимо всі слова, що починаються на цю літеру
       q = q->next;
     p=CreateNode(q->word); // створюємо новий вузол з останнім словом на потрібну літеру
     p->count=q->count;
     AddBefore(dll2.Tail, p); //вставляємо його в другий список
     p=CreateNode(left->word); // створюємо новий вузол з першим словом на потрібну літеру
     p->count=left->count;
     AddBefore(dll2.Tail, p);//вставляємо його в другий список
     if(left!=q) Delete(left); // видаляємо з великого списку перший вузол знайденої пари
     if(q==right){ // якщо дійшли до правого граничного вузла (з другою опорною літерою)
       Delete(right);  // видаляємо його
       break;          // і виходимо з "нескінченного" циклу
     }
     else {
       left=q->next; // інакше - переходимо на вузол з іншою опорною літерою
       Delete(q); // а останній з попередньою літерою - видаляємо з великого списку
     }
   }

   printf("Initial and new lists were modified successfull!!!");
// виводимо змінений великий список у файл
   out = fopen("outt5_2.txt","w");
   q = dll1.Head->next;
   while (q->next) {
    fprintf(out, "%-20s\t%d\n",q->word,q->count);
    q = q->next;
   }
   fclose(out);
// виводимо новоутворений список у файл
   out = fopen("outt5_3.txt","w");
   q = dll2.Head->next;
   while (q->next) {
    fprintf(out, "%-20s\t%d\n", q->word, q->count);
    q = q->next;
   }
   fclose(out);
   getchar();
}
