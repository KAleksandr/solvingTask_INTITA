#include <iostream>
#include <malloc.h>
#include <string.h>
#include <stdio.h>
using namespace std;
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
void Load(PNode *Tree)//download from the word file
{
    char name[20];
    char city[20];
    int goalsScored;
    int missedBalls;
    int score;
    FILE *fp;
    fp = fopen("club.txt", "r");
    while(fp != EOF){
        fscanf(fp, "%s%s",name,city);
        fscanf(fp, "%d%d%d", &score, &goalsScored, &missedBalls);
        AddToTree(Tree,score, name,city,goalsScored,missedBalls);
    }
}

int main()
{
    PNode Tree; // �������� �� ����� ������
    Tree = NULL;

    cout << "Hello World!" << endl;
    return 0;
}
