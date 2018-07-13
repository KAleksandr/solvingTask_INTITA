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

// ��������� ����� � "������"
void AddHead(PNode* Head, PNode* Tail, PNode NewNode)
// ������� ������� ����� � ������� ��������� 2 �������� - Head i Tail,
// �������� � �� ������ ��� ��������� - �����, �������� �� ��������
{
 NewNode->next = *Head; // � ���� ������� - � �������� ����� ��ǲ�����Ӫ�� ��������� �� Head i Tail
 NewNode->prev = NULL; // � "���������" ����� ��������� ����� - �������
 if (*Head) (*Head)->prev = NewNode;  // ���� � ������ ��� � ����� (Head �� ��������) -
 // �������� prev ����� ���������� "���������" ����� �������� �� ����� �����
 *Head = NewNode; // � ����� ����� ��� "��������"
 if (!(*Tail)) *Tail = *Head; // ���� ������ ��� ������ (���� �� ����� ����� - �������� Tail) -
}// ����� ����� ��� ��������� "�������" � "�������"

// ��������� ����� � "����"
void AddTail(PNode* Head, PNode* Tail, PNode NewNode)
// ��� ���� - ������� ������ 2 ��������� ���� "�������� �� ��������",
{
 NewNode->prev = *Tail; // �� � �������� ����� �����������
 NewNode->next = NULL;
 // ��� - ��� �� �����㳿 ��������� AddFirst (����� Head i Tail �������� ������)
 if (*Tail) (*Tail)->next = NewNode;
 *Tail = NewNode;
 if (!(*Head)) *Head = *Tail;
}

// ��������� ����� ���� ��������, � ������� � ��������� p
void AddAfter(PNode p, PNode NewNode)
{
      NewNode->next = p->next;
      NewNode->prev = p;
      p->next->prev = NewNode;
      p->next = NewNode;
}

// ��������� ����� ����� �������, � ������� � ��������� p
void AddBefore(PNode p, PNode NewNode)
{
      NewNode->prev = p->prev;
      NewNode->next = p;
      p->prev->next = NewNode;
      p->prev = NewNode;
}

// ����� ����������� ����� � ������ � "������"
PNode FndReturn(PNode Tail, char NewWord[])
{
 PNode q = Tail->prev;
 while (q && strcmp(q->word, NewWord))
    q = q->prev;
 return q;
}

// ����� ����������� ����� � ������ � "������"
PNode FndForvard(PNode Head, char NewWord[])
{
 PNode q = Head->next;
 while (q && strcmp(q->word, NewWord))
    q = q->next;
 return q;
}

// ����� ���� ������� ������ ����� � ������ � "������"
PNode FndPlaceRet(PNode Tail, char NewWord[])
{
 PNode q = Tail->prev;
 while (q->prev && (strcmp(q->word, NewWord) > 0))
    q=q->prev;
 return q;
}

// ����� ���� ������� ������ ����� � ������ � "������"
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

// ��������� �����
void Delete(PNode OldNode)
{
    OldNode->prev->next = OldNode->next;
    OldNode->next->prev = OldNode->prev;
    free(OldNode);
}

// ��������� ����� ������ �� ���� � �� � ����������
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
// ��������� 2 ������ � ��������� �� "����� �����"
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
// ���������� ������ ������� � ������� �����
   CreateList(in, dll1.Head,dll1.Tail);

   in = fopen("inp_eng2.txt","r");
   if (in) printf("Second file open successfull! Press ENTER\n");
   getchar();

// ���������� ��� ����� ������ ������� � ������� �����
   CreateList(in, dll1.Head,dll1.Tail);
// �������� ��������� ������� ������ � ����
   out = fopen("outt5_1.txt","w");
   q = dll1.Head->next;
   while (q->next) {
    fprintf(out, "%-20s\t%d\n",q->word,q->count);
    q = q->next;
   }
   fclose(out);
// �������� ����� �������� ������
   q = dll1.Head->next;
   while (q->next && q->word[0]!='Q') // ���� �� "��������" � "����" ��� �� �������� ����� �����
    q = q->next;                   // �� ������� �����
   if (q==dll1.Tail) left=dll1.Head->next; // ���� ����� �� "������" � �� ������� - ������ ����� ���������� � �������
   else left=q; // ������ - ������� ������ ����� � ������ �� ������� �����
// � ��� ����������, ����� ������� - �� "������" � �� ����������� (�� �� �����������) ���� �����
   q = dll1.Tail->prev;
   while (q->prev && q->word[0]!='q')
    q = q->prev;
   if (q==dll1.Head) right=dll1.Tail->prev;
   else right=q;

   while(1){
     c_letter=left->word[0]; // ������� ����� (����) ������ �����
     q=left;
     while (q->next->word[0]==c_letter) // �������� �� �����, �� ����������� �� �� �����
       q = q->next;
     p=CreateNode(q->word); // ��������� ����� ����� � ������� ������ �� ������� �����
     p->count=q->count;
     AddBefore(dll2.Tail, p); //���������� ���� � ������ ������
     p=CreateNode(left->word); // ��������� ����� ����� � ������ ������ �� ������� �����
     p->count=left->count;
     AddBefore(dll2.Tail, p);//���������� ���� � ������ ������
     if(left!=q) Delete(left); // ��������� � �������� ������ ������ ����� �������� ����
     if(q==right){ // ���� ����� �� ������� ���������� ����� (� ������ ������� ������)
       Delete(right);  // ��������� ����
       break;          // � �������� � "������������" �����
     }
     else {
       left=q->next; // ������ - ���������� �� ����� � ����� ������� ������
       Delete(q); // � ������� � ����������� ������ - ��������� � �������� ������
     }
   }

   printf("Initial and new lists were modified successfull!!!");
// �������� ������� ������� ������ � ����
   out = fopen("outt5_2.txt","w");
   q = dll1.Head->next;
   while (q->next) {
    fprintf(out, "%-20s\t%d\n",q->word,q->count);
    q = q->next;
   }
   fclose(out);
// �������� ������������� ������ � ����
   out = fopen("outt5_3.txt","w");
   q = dll2.Head->next;
   while (q->next) {
    fprintf(out, "%-20s\t%d\n", q->word, q->count);
    q = q->next;
   }
   fclose(out);
   getchar();
}
