#include <malloc.h>
#include <string.h>
#include <stdio.h>

struct Node {
    char name[20];
    char city[20];
    int goalsScored;
    int missedBalls;
    int score; // ������ ��� (����)

    struct Node *left, *right; // ��������� �� "�����-����"
};
typedef struct Node* PNode; // �������� �� ����� �������



// ����� ������ �� ������ ���
void PrintLKP(PNode Tree)
{
    if (!Tree ) return; // ����� ������ - ���������� "������" (����������� �������� ��������� left==NULL ��� right==NULL)
    PrintLKP(Tree->left); // ����� ����� ��������

    printf("%s - %s ",Tree->name, Tree->city);
    printf("%d - %d - %d\n", Tree->score, Tree->goalsScored, Tree->missedBalls); // ��������  �� �����

    PrintLKP(Tree->right); // ����� ������� ��������
}
void PrintKLP(PNode Tree)
{
    if (!Tree ) return; // ����� ������ - ���������� "������" (����������� �������� ��������� left==NULL ��� right==NULL)
    printf("%s - %s ",Tree->name, Tree->city);
    printf("%d - %d - %d\n", Tree->score, Tree->goalsScored, Tree->missedBalls); // ��������  �� �����
    PrintKLP(Tree->left); // ����� ����� ��������
    PrintKLP(Tree->right); // ����� ������� ��������
}
/*
 * ��������� ��������� AddToTree() ��� ��������� ������ � ������ ��� �������� �����. ����� ��������� ����� � ���/����� �������� - �������� ����� ���������� ����� ����� �������
*/
void AddToTree (PNode *Tree, char name[],char city[],int score, int goalsScored, int missedBalls)// �������� �� �����, ������������� ����
{
    if ( ! (*Tree) ) {
        (*Tree) = (PNode)calloc(1,sizeof(struct Node)); // �������� ����� �����
        strcpy((*Tree)->name, name);
        (*Tree)->score = score;
        strcpy((*Tree)->city, city);
        (*Tree)->goalsScored = goalsScored;
        (*Tree)->missedBalls = missedBalls;
        (*Tree)->left = NULL;
        (*Tree)->right = NULL;
        return;
    }

    if (strcmp((*Tree)->name, name) >0) // ��������� ����� � ������� (��� �� �����) ��������
        AddToTree (&(*Tree)->left, name, city,score, goalsScored, missedBalls);
    else AddToTree (&(*Tree)->right, name, city,score, goalsScored, missedBalls);
}
void Load(PNode *Tree)//download from the word file
{
    char name[20];
    char city[20];
    int goalsScored;
    int missedBalls;
    int score;
    FILE *fp;
    fp = fopen("club.txt", "r");
    while(fscanf(fp, "%s%s%d%d%d",name,city,&score, &goalsScored, &missedBalls)!=EOF){

        AddToTree(Tree, name,city,score,goalsScored,missedBalls);
    }
    fclose(fp);
}

int main()
{
    PNode Tree; // �������� �� ����� ������
    Tree = NULL;
    Load(&Tree);
    printf("Obxid dereva za LKP: \n");
    PrintLKP(Tree); //�������� ����� ������ �� ������ ���
    printf("\nObxid dereva za KLP: \n");
    PrintKLP(Tree); //�������� ����� ������ �� ������ KLP

    free(Tree);
    Tree = NULL;
    return 0;
}
