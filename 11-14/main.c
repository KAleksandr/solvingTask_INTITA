//��� ���� ���������
//�������������� ������������ ����� � ����� ������ � ������
#include <malloc.h>
#include <string.h>
#include <stdio.h>

struct Node {
    char name[20];
    char city[20];
    int goalsScored;
    int missedBalls;
    int score; // ������ ��� (����)
    int count;  // �������� ���������
    struct Node *left, *right; // ��������� �� "�����-����"
};
typedef struct Node* PNode; // �������� �� ����� �������
int flag = 0;


// ����� ������ �� ������ ���
void PrintLKP(PNode Tree)
{
    if (!Tree ) return; // ����� ������ - ���������� "������" (����������� �������� ��������� left==NULL ��� right==NULL)
    PrintLKP(Tree->left); // ����� ����� ��������

    printf("%s - %s ",Tree->name, Tree->city);
    printf("%d - %d - %d -  %d\n", Tree->score, Tree->goalsScored, Tree->missedBalls, Tree->count); // ��������  �� �����

    PrintLKP(Tree->right); // ����� ������� ��������
}
void PrintKLP(PNode Tree)
{
    if ( ! Tree ) return; // ����� ������ - ���������� "������" (����������� �������� ��������� left==NULL ��� right==NULL)
    printf("%s - %s ",Tree->name, Tree->city);
    printf("%d - %d - %d\n", Tree->score, Tree->goalsScored, Tree->missedBalls); // ��������  �� �����
    PrintKLP(Tree->left); // ����� ����� ��������
    PrintKLP(Tree->right); // ����� ������� ��������
}
void PrintPKL(PNode Tree)
{
    if (!Tree ) return; // ����� ������ - ���������� "������" (����������� �������� ��������� left==NULL ��� right==NULL)

    PrintPKL(Tree->right); // ����� ������� ��������
    printf("%s - %s ",Tree->name, Tree->city);
    printf("%d - %d - %d\n", Tree->score, Tree->goalsScored, Tree->missedBalls); // ��������  �� �����
    PrintPKL(Tree->left); // ����� ����� ��������

}
void AddToTree (PNode *Tree, int score,char name[],char city[], int goalsScored, int missedBalls)// �������� �� �����, ������������� ����
{
    if ( ! (*Tree) ) {
        (*Tree) = (PNode)calloc(1,sizeof(struct Node)); // �������� ����� �����
        strcpy((*Tree)->name, name);
        (*Tree)->score = score;
        strcpy((*Tree)->city, city);
        (*Tree)->goalsScored = goalsScored;
        (*Tree)->missedBalls = missedBalls;
        (*Tree)->count=1;
        (*Tree)->left = NULL;
        (*Tree)->right = NULL;
        return;
    }

    if (strcmp((*Tree)->name, name) >0) // ��������� ����� � ������� (��� �� �����) ��������
        AddToTree (&(*Tree)->left, score,name, city, goalsScored, missedBalls);
    else AddToTree (&(*Tree)->right, score,name, city, goalsScored, missedBalls);
}
PNode Search (PNode Tree, char *word) // word - �������� �� ������� �����
{
    if ( !Tree ) return NULL; // ����� �� ������ - � �������� ���� �� �������...
    if (strcmp(word,Tree->name)==0){
        Tree->count++;        // ���� ��������! (� ����� ������ ������ ��� ����-����� ��������)
        return Search ( Tree->right, word);
    }
    if (strcmp(Tree->name,word) > 0) // ���� ������� ���� �� �������� ��� ����� ������ - ������ ��� � ����� �������
        return Search ( Tree->left, word);
    else return Search ( Tree->right, word); // ������ - � ������� �������
}
void Load(PNode *Tree)//download from the word file
{
    char name[20];
    char city[20];
    int goalsScored;
    int missedBalls;
    int score;

    FILE *fp;
    fp =NULL;
    fp = fopen("club.txt", "r");
    if(!fp){
        printf("File is absent in the currant directory");
        return;
    }
    while(fscanf(fp, "%s%s%d%d%d",name,city,&score, &goalsScored, &missedBalls)!=EOF){
        Search(*Tree,name);

            AddToTree(Tree,score, name,city,goalsScored,missedBalls);
    }
    fclose(fp);
}

int main()
{
    PNode Tree; // �������� �� ����� ������
    Tree = NULL;
    Load(&Tree);
    if(Tree){
        printf("The tournament table: \n");//�� �������� �� �������� ������� ����)
        PrintLKP(Tree); //�������� ����� ������ �� ������ ���
    }
    else
        printf("File is absent in the currant directory");

    free(Tree);
    Tree = NULL;
    return 0;
}
