#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdio.h>
struct Club {
        char name[20];
        char city[20];
        int goalsScored;
        int missedBalls;
        int score;
    };
typedef struct Club* pClub;
struct Node {
    char name[20];
    char city[20];
    int goalsScored;
    int missedBalls;
    int score; // ������ ��� (����)

    struct Node *left, *right; // ��������� �� "�����-����"
};
typedef struct Node* PNode; // �������� �� ����� �������

PNode MakeTree(pClub data, int from, int n)
{
    PNode Tree;
    int n1, n2;
printf("%i", data[from].score);
    if ( n == 0 ) return NULL; // ����� ���������� ������
    Tree = (PNode)calloc(1,sizeof(struct Node)); // ������� ���'��� �� ����� ����� (�������)
    int score = data[from].score;
    Tree->score = score; // �������� � ����� ������ ��� (����)
     Tree->goalsScored = data[from].goalsScored;
    Tree->missedBalls = data[from].missedBalls;

    strcpy(Tree->city, data[from].city);
    strcpy(Tree->name, data[from].name);
    n1 = n / 2; // ��������� ����� ��������
    n2 = n - n1 - 1;
    Tree->left = MakeTree(data, from+1, n1);
    Tree->right = MakeTree(data, from+1+n1, n2);
    return Tree;
}

// ����� ������ �� ������ ���
void PrintLKP(PNode Tree)
{
    if (!Tree ) return; // ����� ������ - ���������� "������" (����������� �������� ��������� left==NULL ��� right==NULL)
    PrintLKP(Tree->left); // ����� ����� ��������

    printf("%s - %s ",Tree->name, Tree->city);
    printf("%d - %d - %d\n", Tree->score, Tree->goalsScored, Tree->missedBalls); // ��������  �� �����

    PrintLKP(Tree->right); // ����� ������� ��������
}
void AddToTree (PNode *Tree, int score,char name[],char city[], int goalsScored, int missedBalls)// �������� �� �����, ������������� ����
{
    if ( ! (*Tree) ) {
        (*Tree) = (PNode)calloc(1,sizeof(struct Node)); // �������� ����� �����
        (*Tree)->score = score;
        strcpy((*Tree)->name, name);
        strcpy((*Tree)->city, city);
        (*Tree)->goalsScored = goalsScored;
        (*Tree)->missedBalls = missedBalls;
        (*Tree)->left = NULL;
        (*Tree)->right = NULL;
        return;
    }

    if ( score < (*Tree)->score ) // ��������� ����� � ������� (��� �� �����) ��������
        AddToTree (&(*Tree)->left, score, name, city, goalsScored, missedBalls);
    else AddToTree (&(*Tree)->right, score, name, city, goalsScored, missedBalls);
}

int main()
{
   int n;
        pClub pmyclub;

        do{
           printf("Input N(0<n<=10): ");
           scanf("%i",&n);
        }
        while(!(n>0 && n<=10));

        pmyclub = (pClub)malloc(n*sizeof(pClub));
        for(int i=0; i<n; i++){
            printf("[%i] Input name (club) ",i+1);
            scanf("%s", pmyclub[i].name);
            printf("Input city (club) ");
            scanf("%s", pmyclub[i].city);
            printf("Input goals Scored (club) ");
            scanf("%d", &pmyclub[i].goalsScored);
            printf("Input missed Balls (club) ");
            scanf("%d", &pmyclub[i].missedBalls);
            printf("Input score (club) ");
            scanf("%d", &pmyclub[i].score);
        }
        PNode Tree; // �������� �� ����� ������
        Tree = NULL;

        Tree = MakeTree(pmyclub, 0, n); // ���������� ������ � n �����, ��������� � �������� ������ �� ������� 0
        printf("Obxid dereva za LKP: ");
        PrintLKP(Tree); //�������� ����� ������ �� ������ ���

    free(pmyclub);
    free(Tree);
    Tree = NULL;

    return 0;
}
