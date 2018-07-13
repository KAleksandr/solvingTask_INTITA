#include <string.h>
#include <stdio.h>
#include <malloc.h>
struct Node {
       char word[40];
       int count;
       struct Node *next, *prev;
};

typedef struct Node* PNode;

// ��������� "����� �����" �����'������ ������
struct List{
  PNode Head;
  PNode Tail;
};

PNode CreateNode(char NewWord[])
{
 PNode NewNode = (PNode)calloc(1,sizeof(struct Node));
 strcpy(NewNode->word, NewWord); // �������� � ����� �����
 NewNode->count = 1; // �������� ��� = 1
 NewNode->next = NULL; // ���������� ����� ���� �� ����
 NewNode->prev = NULL; // ������������ - ���
 return NewNode; // ��������� ������� � ������ �����
}

// �������� ����� � "������"
void AddHead(PNode* Head, PNode* Tail, PNode NewNode)
// ������� ������� ����� � ������� ��������� 2 ������� - Head i Tail,
// �������� � �� �?�?�� ��� ��������� - �����, �������� �� ��������
{
 NewNode->next = *Head; // � ���� ������� - � �������� ����� ���?�?������� ��������� �� Head i Tail
 NewNode->prev = NULL; // � "���������" ����� ��������� ����� - �������
 if (*Head) (*Head)->prev = NewNode;  // ���� � ������ ��� � ����� (Head �� ��������) -
 // �������� prev ����� ���������� "���������" ����� �������� �� ����� �����
 *Head = NewNode; // � ����� ����� ��� "��������"
 if (!(*Tail)) *Tail = *Head; // ���� ������ ��� ������ (���� �� ����� ����� - �������� Tail) -
}// ����� ����� ��� ��������� "�������" � "�������"

// �������� ����� � "����"
void AddTail(PNode* Head, PNode* Tail, PNode NewNode)
// ��� ���� - ������� ������ 2 ��������� ���� "�������� �� ��������",
{
 NewNode->prev = *Tail; // �� � �������� ����� �����������
 NewNode->next = NULL;
 // ��� - ��� �� �����㳜 ��������� AddFirst (����� Head i Tail ������ ������)
 if (*Tail) (*Tail)->next = NewNode;
 *Tail = NewNode;
 if (!(*Head)) *Head = *Tail;
}

// �������� ����� ��� ��������, � ������� � ��������� p
void AddAfter(PNode* Head, PNode* Tail, PNode p, PNode NewNode)
{// ������� ������ 2 ��������� "�������� �� ��������"
 if (!p->next)
    AddTail(Head, Tail, NewNode); // � ������ �� � AddTail, ���� �������� p ����� �� Tail
 else {
      NewNode->next = p->next;
      NewNode->prev = p;
      p->next->prev = NewNode;
      p->next = NewNode;
 }
}

// ������� ����� ����� �������, � ������� � ��������� p
void AddBefore (PNode* Head, PNode* Tail, PNode p, PNode NewNode)
{
// ���� ��������� ���� �� ��� �� ���� �������� Head i Tail,
 if (!p->prev)
 // � "��������" �� ������� �������� ��������:
    AddHead(Head,Tail,NewNode); // - �������� � �� �?�?�� Head i Tail,
 // �������� ����� ������: ���� �������� prev �������� (p ����� �� "��������" �����) -
 // �������� ����� ����� �� ���� "���������"
 else {
      NewNode->prev = p->prev;
      NewNode->next = p;
      p->prev->next = NewNode;
      p->prev = NewNode;
 }
}

// ����� ����������� ����� � ������ � "������"
PNode FndReturn(PNode* Tail, char NewWord[])
{
 PNode q = *Tail;
 while (q && strcmp(q->word, NewWord))
    q = q->prev;
 return q;
}

// ����� ����������� ����� � ������ � "������"
PNode FndForvard(PNode* Head, char NewWord[])
{
 PNode q = *Head;
 while (q && strcmp(q->word, NewWord))
    q = q->next;
 return q;
}

// ����� ���� ������� ������ ����� � ������ � "������"
PNode FndPlaceRet(PNode* Tail, char NewWord[])
{
 PNode q = *Tail;
 while (q && (strcmp(q->word, NewWord) > 0)){
    q=q->prev;
 }
 return q;
}

// ����� ���� ������� ������ ����� � ������ � "������"
PNode FndPlaceFwd(PNode* Head, char NewWord[])
{
 PNode q = *Head;
 while (q && (strcmp(q->word, NewWord) < 0)){
    q=q->next;
 }
 return q;
}

// ��������� ����� ������ ��� ���'���
void CreateList(FILE* in, PNode* Head, PNode* Tail)
{
 char word[40];
 int n,nHead,nTail;
 PNode p=NULL,where=NULL;

 while (1) {
    n = fscanf(in,"%s",word);
    if (n<=0) break;
    if(*Head){ // ���� � ������ ��� � ��� ���� ����� - �������� ���������� �������� ����� �����
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
    else // ������ - �����뤯�� � ������ ������ �����
         AddHead(Head,Tail,CreateNode(word));
 }
 fclose(in);
 printf("Double-linked list create successfull! Press ENTER\n");
 getchar();
}
int main(void)
{
// ��������� ������ � ����뤯�� ���� "����� �����"
   struct List dll={NULL,NULL};
   PNode q,p;
   int k1,k2,i;
   FILE *in, *out;

   in = fopen("inp_eng1.txt","r");
   if (in) printf("First file open successfull! Press ENTER\n");
   getchar();
// ���������� ������ ������� � �����
   CreateList(in,&dll.Head,&dll.Tail);

   out = fopen("output1.dat","w");
   q = dll.Head;
   while (q) {
    fprintf(out, "%-20s\t%d\n",q->word,q->count);
   printf("%-20s\t%d\n",q->word,q->count);//������� ������ �� ����� (� ������ "����� - ������� ���������")
    q = q->next;
  }
  fclose(out);
  //------------------
  printf("\n\n");
  // �����, �� ������ �����, �� ������������ � ����� ������� ������� ����, ������������ (������� �� ��ﳿ) �
  q = dll.Head;
  while (q) {
      if((q->count)%2 != 0){// ������������ � ����� ������� ������� ����
           //printf("%-20s\t%d\n",q->word,q->count);//������� ������ �� ����� (� ������ "����� - ������� ���������")
           p=CreateNode(q->word); // ��������� ����� ����� � ������� ������
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



// ������ ������ �������� -
  (dll.Head)->prev=dll.Tail; // �������� ������ �� ����
  (dll.Tail)->next=dll.Head; // � �������

  do{
   printf("Input the number >0: k1=");
   scanf("%d",&k1); // ������� ����� �� ��������� ����� "������"
   getchar();
  }while (k1<=0);
  do{
   printf("Input the number <0: k2=");
   scanf("%d",&k2); // ������� ����� �� ��������� ����� "����"
   getchar();
  }while (k2>=0);

  for(i=0;i<k1;i++)
    dll.Head=(dll.Head)->next; // ���������� �������� ������ �� k1 ����� "������"
  dll.Tail=(dll.Head)->prev; // � �������� ������ - ������������ �����

  out = fopen("output3_1.dat","w");
  q = dll.Head;
  do { // �������� ��������� ������ � ����
    fprintf(out, "%-20s\t%d\n",q->word,q->count);
    q = q->next;
  }while (q!=dll.Head);
  fclose(out);

  for(i=0;i<-k2;i++)
    dll.Tail=(dll.Tail)->prev; // ���������� �������� ������ �� k2 ����� "����"
  dll.Head=(dll.Tail)->next; // � �������� ������ - ������������ �����

  out = fopen("output3.dat","w");
  q = dll.Tail;
  do { // �������� ��������� ������ � ����
    fprintf(out, "%-20s\t%d\n",q->word,q->count);
    q = q->prev;
}while (q!=dll.Tail);
fclose(out);

getchar();
}
