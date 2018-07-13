#include "ranking.h"

void makeTree (Node **Tree, char name[],char city[], int wins, int draws,int defeats, int score)// покажчик на корінь, цілочисельний ключ
{
    if ( ! (*Tree) ) {
        (*Tree) = (Node*)calloc(1,sizeof(struct Node)); // створити новий вузол
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

    if (((*Tree)->score) > score) // додавання вузла у потрібне (ліве чи праве) піддерево
        makeTree(&(*Tree)->left, name, city, wins, draws, defeats, score);
    else makeTree(&(*Tree)->right, name, city, wins, draws, defeats, score);
}
void PrintPKL(Node *Tree)
{
    if (!Tree ) return; // кінець рекурсії - досягнення "листка" (повертається значення покажчика left==NULL або right==NULL)

    PrintPKL(Tree->right); // обхід правого піддерева
    printf("%s - %s - ",Tree->name, Tree->city);
    printf("%d - %d - %d - %d\n", Tree->wins, Tree->draws, Tree->defeats, Tree->score); // виводимо  на екран
    PrintPKL(Tree->left); // обхід лівого піддерева

}
int countScore(char w[], char d[]){
    int countS=0;
    countS =3* (atoi(w)) + atoi(d);
    return countS;
}
