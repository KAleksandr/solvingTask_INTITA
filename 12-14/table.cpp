#include "ranking.h"

void makeTree (Node **Tree, char name[],char city[], int wins, int draws,int defeats, int score)// �������� �� �����, ������������� ����
{
    if ( ! (*Tree) ) {
        (*Tree) = (Node*)calloc(1,sizeof(struct Node)); // �������� ����� �����
        strcpy((*Tree)->name, name);
        strcpy((*Tree)->city, city);
        (*Tree)->wins = wins;
        (*Tree)->draws = draws;
        (*Tree)->defeats = defeats;
        (*Tree)->score = score;
        (*Tree)->left = NULL;
        (*Tree)->right = NULL;
        return;
    }

    if (((*Tree)->score) > score) // ��������� ����� � ������� (��� �� �����) ��������
        makeTree(&(*Tree)->left, name, city, wins, draws, defeats, score);
    else makeTree(&(*Tree)->right, name, city, wins, draws, defeats, score);
}
void PrintPKL(Node *Tree)
{
    if (!Tree ) return; // ����� ������ - ���������� "������" (����������� �������� ��������� left==NULL ��� right==NULL)

    PrintPKL(Tree->right); // ����� ������� ��������
    printf("%s - %s - ",Tree->name, Tree->city);
    printf("%d - %d - %d - %d\n", Tree->wins, Tree->draws, Tree->defeats, Tree->score); // ��������  �� �����
    PrintPKL(Tree->left); // ����� ����� ��������

}
int countScore(char w[], char d[]){
    int countS=0;
    countS =3* (atoi(w)) + atoi(d);
    return countS;
}
