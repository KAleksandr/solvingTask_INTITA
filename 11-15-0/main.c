#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct Node {
    char key[40]; // ������ ��� (�����-����)
    int count;  // �������� ���������
    struct Node *left, *right; // ��������� �� "�����-����"
};
typedef struct Node* PNode; // �������� �� ������ �����

// ����� ������ �� ������ ���
void PrintLKP(PNode Tree)
{
    if ( ! Tree ) return; // ����� ������ - ���������� "������" (����������� �������� ��������� left==NULL ��� right==NULL)
    PrintLKP(Tree->left); // ����� ����� ��������
    printf("%s - %d\n", Tree->key,Tree->count); // �������� "����" ������ �� �����
    PrintLKP(Tree->right); // ����� ������� ��������
}
//� �� ������ �������
void PrintLPK(PNode Tree)
{
    if ( ! Tree ) return; // ����� ������ - ���������� "������" (����������� �������� ��������� left==NULL ��� right==NULL)
    PrintLPK(Tree->left); // ����� ����� ��������
    PrintLPK(Tree->right); // ����� ������� ��������
    printf("%s - %d\n", Tree->key,Tree->count); // �������� "����" ������ �� �����
}

void PrintKLP(PNode Tree)
{
    if ( ! Tree ) return; // ����� ������ - ���������� "������" (����������� �������� ��������� left==NULL ��� right==NULL)
    printf("%s - %d\n", Tree->key,Tree->count); // �������� "����" ������ �� �����
    PrintKLP(Tree->left); // ����� ����� ��������
    PrintKLP(Tree->right); // ����� ������� ��������
}

void PrintPKL(PNode Tree)
{
    if ( ! Tree ) return; // ����� ������ - ���������� "������" (����������� �������� ��������� left==NULL ��� right==NULL)
    PrintPKL(Tree->right); // ����� ������� ��������
    printf("%s - %d\n", Tree->key,Tree->count); // �������� "����" ������ �� �����
    PrintPKL(Tree->left); // ����� ����� ��������
}

// ������� ������ ����� � ������ ������
void AddToTree(PNode *Tree, char *word)// ��������� - ������ ��������� �� �����, �������� �� ������� �����
{// ��� ����������� �� ����� ������ - ������ ���� ��������� ��� ����� �����������
    if ( ! *Tree ) { // ���� ������ ����� ��� ����� �� "������" -
        (*Tree) = (PNode)calloc(1,sizeof(struct Node)); // �������� ����� �����
        strcpy((*Tree)->key,word);
        (*Tree)->count=1;
        (*Tree)->left = NULL;
        (*Tree)->right = NULL;
        return;
    }
    if (strcmp((*Tree)->key,word) > 0) // ��������� ����� � ������� (��� �� �����) ��������
        AddToTree ( &(*Tree)->left, word);
    else AddToTree ( &(*Tree)->right, word);
}
// ����� ��������� ����� � �����
PNode Search (PNode Tree, char *word) // word - �������� �� ������� �����
{
    if ( ! Tree ) return NULL; // ����� �� ������ - � �������� ���� �� �������...
    if (strcmp(word,Tree->key)==0) return Tree; // ���� ��������! (� ����� ������ ������ ��� ����-����� ��������)
    if (strcmp(Tree->key,word) > 0) // ���� ������� ���� �� �������� ��� ����� ������ - ������ ��� � ����� �������
        return Search ( Tree->left, word);
    else return Search ( Tree->right, word); // ������ - � ������� �������
}

int main()
{
    FILE *in;
    int n;
    char word[40];
    PNode p,Tree; // �������� �� ����� ������

    Tree = NULL;
    in = fopen("inp_eng.txt","r");
    if (in) {
      printf("File open successful! Press ENTER\n");
      getchar();

      while(1) {
        n = fscanf(in,"%s",word); // ������ ����� � �����
        if (n<=0) break; // ���� ����� ���������� - ����� � �����
        p=Search(Tree,word); // ����� ������ �����, �� ������� ����� ��� ����
        if (p) p->count++; // ���� ������� - ��������� ���������
        else AddToTree(&Tree,word); // ������ - �����. ����� ����� � ������� � ����� �����, ����������� � �����
      }
      fclose(in);
      if (Tree) {

        PrintLKP(Tree);
        getchar();
        PrintPKL(Tree);
        getchar();

      }
      else printf("File is absent in the currant directory");
    }
    else printf("File is empty");
    getchar();
    return 0;
}
