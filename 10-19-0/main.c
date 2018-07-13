#include <string.h>
#include <stdio.h>
#include <malloc.h>
struct Node {
       char word[40];
       int count;
       struct Node *next, *prev;
};

typedef struct Node* PNode;

// структура "точок входу" двозв'§зного списку
struct List{
  PNode Head;
  PNode Tail;
};

PNode CreateNode(char NewWord[])
{
 PNode NewNode = (PNode)calloc(1,sizeof(struct Node));
 strcpy(NewNode->word, NewWord); // записати у вузол слово
 NewNode->count = 1; // л≥чильник сл≥в = 1
 NewNode->next = NULL; // наступного вузла поки що немаѓ
 NewNode->prev = NULL; // попереднього - теж
 return NewNode; // результат функц≥Ь ÷ адреса вузла
}

// додаванн§ вузла в "голову"
void AddHead(PNode* Head, PNode* Tail, PNode NewNode)
// оск≥льки функц≥§ зм≥нюѓ ≥ повинна повернути 2 значенн§ - Head i Tail,
// передаѓмо в неЬ Љ?Ц?Чї цих покажчик≥в - тобто, покажчик на покажчик
{
 NewNode->next = *Head; // з ц≥ѓЬ причини - в потр≥бних м≥сц§х ЦЭЂ?Ю?НЭђФЩЮЭ покажчики на Head i Tail
 NewNode->prev = NULL; // у "головного" вузла попередн≥й вузол - в≥дсутн≥й
 if (*Head) (*Head)->prev = NewNode;  // §кщо в списку вже ѓ вузли (Head не нульовий) -
 // покажчик prev ран≥ше створеного "головного" вузла замикаѓмо на новий вузол
 *Head = NewNode; // а новий вузол стаѓ "головним"
 if (!(*Tail)) *Tail = *Head; // §кщо список був пустий (одна ≥з ознак цього - нульовий Tail) -
}// новий вузол стаѓ одночасно "головою" ≥ "хвостом"

// додаванн§ вузла в "хв≥ст"
void AddTail(PNode* Head, PNode* Tail, PNode NewNode)
// так само - функц≥§ приймаѓ 2 параметри типу "покажчик на покажчик",
{
 NewNode->prev = *Tail; // §к≥ в потр≥бних м≥сц§х роз≥меновуѓмо
 NewNode->next = NULL;
 // дал≥ - все по аналог≥Ь процедури AddFirst (т≥льки Head i Tail м≥н§ютьс§ м≥сц§ми)
 if (*Tail) (*Tail)->next = NewNode;
 *Tail = NewNode;
 if (!(*Head)) *Head = *Tail;
}

// додаванн§ вузла п≥сл§ заданого, з адресою в покажчику p
void AddAfter(PNode* Head, PNode* Tail, PNode p, PNode NewNode)
{// функц≥§ приймаѓ 2 параметри "покажчик на покажчик"
 if (!p->next)
    AddTail(Head, Tail, NewNode); // ≥ передаѓ Ьх в AddTail, §кщо покажчик p вказуѓ на Tail
 else {
      NewNode->next = p->next;
      NewNode->prev = p;
      p->next->prev = NewNode;
      p->next = NewNode;
 }
}

// вставка вузла перед заданим, з адресою в покажчику p
void AddBefore (PNode* Head, PNode* Tail, PNode p, PNode NewNode)
{
// дана процедура сама по соб≥ не буде зм≥нювати Head i Tail,
 if (!p->prev)
 // а "доручить" це зробити наступн≥й процедур≥:
    AddHead(Head,Tail,NewNode); // - передаѓмо в неЬ Љ?Ц?Чї Head i Tail,
 // попередн§ умова означаѓ: §кщо покажчик prev НФОєЭђїЕ (p вказуѓ на "головний" вузол) -
 // вставити новий вузол на м≥сце "головного"
 else {
      NewNode->prev = p->prev;
      NewNode->next = p;
      p->prev->next = NewNode;
      p->prev = NewNode;
 }
}

// пошук прочитаного слова у списку з "хвоста"
PNode FndReturn(PNode* Tail, char NewWord[])
{
 PNode q = *Tail;
 while (q && strcmp(q->word, NewWord))
    q = q->prev;
 return q;
}

// пошук прочитаного слова у списку з "голови"
PNode FndForvard(PNode* Head, char NewWord[])
{
 PNode q = *Head;
 while (q && strcmp(q->word, NewWord))
    q = q->next;
 return q;
}

// пошук м≥сц§ вставки нового слова у список з "хвоста"
PNode FndPlaceRet(PNode* Tail, char NewWord[])
{
 PNode q = *Tail;
 while (q && (strcmp(q->word, NewWord) > 0)){
    q=q->prev;
 }
 return q;
}

// пошук м≥сц§ вставки нового слова у список з "голови"
PNode FndPlaceFwd(PNode* Head, char NewWord[])
{
 PNode q = *Head;
 while (q && (strcmp(q->word, NewWord) < 0)){
    q=q->next;
 }
 return q;
}

// створюѓмо новий список без бар'ѓр≥в
void CreateList(FILE* in, PNode* Head, PNode* Tail)
{
 char word[40];
 int n,nHead,nTail;
 PNode p=NULL,where=NULL;

 while (1) {
    n = fscanf(in,"%s",word);
    if (n<=0) break;
    if(*Head){ // §кщо в списку вже ѓ хоч один вузол - виконуѓмо стандартне додаванн§ нових вузл≥в
      nHead=strcmp((*Head)->word, word);
      nTail=strcmp((*Tail)->word, word);
      if (nHead>nTail)
        p = FndReturn(Tail,word);
      else p = FndForvard(Head,word);
      if (p)
       p->count++;
      else {
         p = CreateNode(word);
         if (nHead>nTail){
            where = FndPlaceRet(Tail,word);
            if(!where) AddHead(Head,Tail,p);
            else AddAfter(Head,Tail,where,p);
         }
         else{
            where = FndPlaceFwd(Head,word);
            if(!where) AddTail(Head,Tail,p);
            else AddBefore(Head,Tail,where,p);
         }
      }
    }
    else // ≥накше - вставл§ѓмо в список перший вузол
         AddHead(Head,Tail,CreateNode(word));
 }
 fclose(in);
 printf("Double-linked list create successfull! Press ENTER\n");
 getchar();
}
int main(void)
{
// оголошуѓмо список ≥ обнул§ѓмо його "точки входу"
   struct List dll={NULL,NULL};
   PNode q,p;
   int k1,k2,i;
   FILE *in, *out;

   in = fopen("inp_eng1.txt","r");
   if (in) printf("First file open successfull! Press ENTER\n");
   getchar();
// заповнюЇмо список словами з файлу
   CreateList(in,&dll.Head,&dll.Tail);

   out = fopen("output1.dat","w");
   q = dll.Head;
   while (q) {
    fprintf(out, "%-20s\t%d\n",q->word,q->count);
   printf("%-20s\t%d\n",q->word,q->count);//вивести список на екран (у формат≥ "слово - к≥льк≥сть повторень")
    q = q->next;
  }
  fclose(out);
  //------------------
  printf("\n\n");
  // вузли, що м≥ст€ть слова, €к≥ зустр≥чаютьс€ в текст≥ непарну к≥льк≥сть раз≥в, продублювати (зробити њх коп≥њ) ≥
  q = dll.Head;
  while (q) {
      if((q->count)%2 != 0){// зустр≥чаютьс€ в текст≥ непарну к≥льк≥сть раз≥в
           //printf("%-20s\t%d\n",q->word,q->count);//вивести список на екран (у формат≥ "слово - к≥льк≥сть повторень")
           p=CreateNode(q->word); // створюЇмо новий вузол з шуканим словом
           p->count=q->count;
           AddBefore(&dll.Head,&dll.Tail,q,p);
      }
           q = q->next;
 }
  //--------------------------
  out = fopen("output2.dat","w");
  q = dll.Head;
  while (q) {
   fprintf(out, "%-20s\t%d\n",q->word,q->count);
   q = q->next;
 }
 fclose(out);



// робимо список цикл≥чним -
  (dll.Head)->prev=dll.Tail; // замикаѓмо голову на хв≥ст
  (dll.Tail)->next=dll.Head; // ≥ навпаки

  do{
   printf("Input the number >0: k1=");
   scanf("%d",&k1); // к≥льк≥сть крок≥в дл§ цикл≥чного зсуву "вправо"
   getchar();
  }while (k1<=0);
  do{
   printf("Input the number <0: k2=");
   scanf("%d",&k2); // к≥льк≥сть крок≥в дл§ цикл≥чного зсуву "вл≥во"
   getchar();
  }while (k2>=0);

  for(i=0;i<k1;i++)
    dll.Head=(dll.Head)->next; // пересуваѓмо покажчик голови на k1 вузл≥в "вправо"
  dll.Tail=(dll.Head)->prev; // а покажчик хвоста - прилаштовуѓмо поруч

  out = fopen("output3_1.dat","w");
  q = dll.Head;
  do { // виводимо одержаний список у файл
    fprintf(out, "%-20s\t%d\n",q->word,q->count);
    q = q->next;
  }while (q!=dll.Head);
  fclose(out);

  for(i=0;i<-k2;i++)
    dll.Tail=(dll.Tail)->prev; // пересуваѓмо покажчик хвоста на k2 вузл≥в "вл≥во"
  dll.Head=(dll.Tail)->next; // а покажчик голови - прилаштовуѓмо поруч

  out = fopen("output3.dat","w");
  q = dll.Tail;
  do { // виводимо одержаний список у файл
    fprintf(out, "%-20s\t%d\n",q->word,q->count);
    q = q->prev;
}while (q!=dll.Tail);
fclose(out);

getchar();
}
