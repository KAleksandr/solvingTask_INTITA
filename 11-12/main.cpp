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
    int score; // корисні дані (ключ)

    struct Node *left, *right; // покажчики на "вузли-сини"
};
typedef struct Node* PNode; // покажчик на деяку вершину



// обхід дерева за схемою ЛКП
void PrintLKP(PNode Tree)
{
    if (!Tree ) return; // кінець рекурсії - досягнення "листка" (повертається значення покажчика left==NULL або right==NULL)
    PrintLKP(Tree->left); // обхід лівого піддерева

    printf("%s - %s ",Tree->name, Tree->city);
    printf("%d - %d - %d\n", Tree->score, Tree->goalsScored, Tree->missedBalls); // виводимо  на екран

    PrintLKP(Tree->right); // обхід правого піддерева
}
void AddToTree (PNode *Tree, int score,char name[],char city[], int goalsScored, int missedBalls)// покажчик на корінь, цілочисельний ключ
{
    if ( ! (*Tree) ) {
        (*Tree) = (PNode)calloc(1,sizeof(struct Node)); // створити новий вузол
        (*Tree)->score = score;
        strcpy((*Tree)->name, name);
        strcpy((*Tree)->city, city);
        (*Tree)->goalsScored = goalsScored;
        (*Tree)->missedBalls = missedBalls;
        (*Tree)->left = NULL;
        (*Tree)->right = NULL;
        return;
    }

    if ( score < (*Tree)->score ) // додавання вузла у потрібне (ліве чи праве) піддерево
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
    PNode Tree; // покажчик на корінь дерева
    Tree = NULL;

    cout << "Hello World!" << endl;
    return 0;
}
