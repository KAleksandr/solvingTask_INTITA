// �������� ��������� ������ �� ��������� ������
#include <stdio.h>
#include <conio.h>

struct Node {
    int key; // ������ ��� (����)

    struct Node *left, *right; // ��������� �� "�����-����"
};
typedef struct Node* PNode; // �������� �� ����� �������

PNode MakeTree(int* data, int from, int n)
{
    PNode Tree;
    int n1, n2;
printf("%i\n", data[from]);
    if ( n == 0 ) return NULL; // ����� ���������� ������
    Tree = (PNode)calloc(1,sizeof(struct Node)); // ������� ���'��� �� ����� ����� (�������)
    Tree->key = data[from]; // �������� � ����� ������ ��� (����)
    n1 = n / 2; // ��������� ����� ��������
    n2 = n - n1 - 1;
    Tree->left = MakeTree(data, from+1, n1);
    Tree->right = MakeTree(data, from+1+n1, n2);
    return Tree;
}

// ����� ������ �� ������ ���
void PrintLKP(PNode Tree)
{
    if ( ! Tree ) return; // ����� ������ - ���������� "������" (����������� �������� ��������� left==NULL ��� right==NULL)
    PrintLKP(Tree->left); // ����� ����� ��������
    printf("%d ", Tree->key); // �������� "����" �� �����
    PrintLKP(Tree->right); // ����� ������� ��������
}

void PrintKLP(PNode Tree)
{
    if ( ! Tree ) return; // ����� ������ - ���������� "������" (����������� �������� ��������� left==NULL ��� right==NULL)
    printf("%d ", Tree->key); // �������� "����" �� �����
    PrintKLP(Tree->left); // ����� ����� ��������
    PrintKLP(Tree->right); // ����� ������� ��������
}

void PrintLPK(PNode Tree)
{
    if ( ! Tree ) return; // ����� ������ - ���������� "������" (����������� �������� ��������� left==NULL ��� right==NULL)
    PrintLPK(Tree->left); // ����� ����� ��������
    PrintLPK(Tree->right); // ����� ������� ��������
    printf("%d ", Tree->key); // �������� "����" �� �����
}

// ������� ������ ����� � ������ ������
void AddToTree (PNode *Tree, int data)// �������� �� �����, ������������� ����
{
    if ( ! (*Tree) ) {
        (*Tree) = (PNode)calloc(1,sizeof(struct Node)); // �������� ����� �����
        (*Tree)->key = data;
        (*Tree)->left = NULL;
        (*Tree)->right = NULL;
        return;
    }
//	else printf("%d ",inTree->key);
//	getchar();
    if ( data < (*Tree)->key ) // ��������� ����� � ������� (��� �� �����) ��������
        AddToTree (&(*Tree)->left, data);
    else AddToTree (&(*Tree)->right, data);
}

PNode Search (PNode Tree, int what)
{
    if ( ! Tree ) return NULL; // ��� ������ - � �������� ���� �� �������...
    if ( what == Tree->key ) return Tree; // ���� ��������! (� �����)
    if ( what < Tree->key ) // ���� ������� ���� ����� ������ - ������ ��� � ����� �������
        return Search ( Tree->left, what );
    else return Search ( Tree->right, what ); // ������ - � ������� �������
}

main()
{
    int data[] = {17, 21, 8, 9, 11, 15, 19, 20, 7};
    PNode Tree; // �������� �� ����� ������
    int i,n = sizeof(data) / sizeof(int); // ����� ������
    char c;

    Tree = MakeTree(data, 0, n); // ���������� ������ � n �����, ��������� � �������� ������ �� ������� 0
    printf("Obxid dereva za LKP0: ");
    PrintLKP(Tree); //�������� ����� ������ �� ������ ���
    printf("\nObxid dereva za KLP: ");
    PrintKLP(Tree); //�������� ����� ������ �� ������ ���
    printf("\nObxid dereva za LPK: ");
    PrintLPK(Tree); //�������� ����� ������ �� ������ ���
    Tree = NULL;
    for (i=0; i<n; i++) // ���������� ������ ������
        AddToTree(&Tree, data[i]);
    printf("\nObxid dereva za LKP: ");
    PrintLKP(Tree); //�������� ����� ������ �� ������ ���
    printf("\n");
    do{
        printf("Input number to search: ");
        scanf("%d",&n);
        if(!Search(Tree,n)) printf("There is NO such num...\n");
        else printf("There is such num !!!\n");
        printf("Next? y/n");
        do{
            c=getch();
        }while(c!='y' && c!='n');
        printf("\n");
    }while(c=='y');
}
