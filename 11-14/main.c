//Вніс деякі корективи
//Використовував завантаження даних з файлу відразу в дерево
#include <malloc.h>
#include <string.h>
#include <stdio.h>

struct Node {
    char name[20];
    char city[20];
    int goalsScored;
    int missedBalls;
    int score; // корисні дані (ключ)
    int count;  // лічильник повторень
    struct Node *left, *right; // покажчики на "вузли-сини"
};
typedef struct Node* PNode; // покажчик на деяку вершину
int flag = 0;


// обхід дерева за схемою ЛКП
void PrintLKP(PNode Tree)
{
    if (!Tree ) return; // кінець рекурсії - досягнення "листка" (повертається значення покажчика left==NULL або right==NULL)
    PrintLKP(Tree->left); // обхід лівого піддерева

    printf("%s - %s ",Tree->name, Tree->city);
    printf("%d - %d - %d -  %d\n", Tree->score, Tree->goalsScored, Tree->missedBalls, Tree->count); // виводимо  на екран

    PrintLKP(Tree->right); // обхід правого піддерева
}
void PrintKLP(PNode Tree)
{
    if ( ! Tree ) return; // кінець рекурсії - досягнення "листка" (повертається значення покажчика left==NULL або right==NULL)
    printf("%s - %s ",Tree->name, Tree->city);
    printf("%d - %d - %d\n", Tree->score, Tree->goalsScored, Tree->missedBalls); // виводимо  на екран
    PrintKLP(Tree->left); // обхід лівого піддерева
    PrintKLP(Tree->right); // обхід правого піддерева
}
void PrintPKL(PNode Tree)
{
    if (!Tree ) return; // кінець рекурсії - досягнення "листка" (повертається значення покажчика left==NULL або right==NULL)

    PrintPKL(Tree->right); // обхід правого піддерева
    printf("%s - %s ",Tree->name, Tree->city);
    printf("%d - %d - %d\n", Tree->score, Tree->goalsScored, Tree->missedBalls); // виводимо  на екран
    PrintPKL(Tree->left); // обхід лівого піддерева

}
void AddToTree (PNode *Tree, int score,char name[],char city[], int goalsScored, int missedBalls)// покажчик на корінь, цілочисельний ключ
{
    if ( ! (*Tree) ) {
        (*Tree) = (PNode)calloc(1,sizeof(struct Node)); // створити новий вузол
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

    if (strcmp((*Tree)->name, name) >0) // додавання вузла у потрібне (ліве чи праве) піддерево
        AddToTree (&(*Tree)->left, score,name, city, goalsScored, missedBalls);
    else AddToTree (&(*Tree)->right, score,name, city, goalsScored, missedBalls);
}
PNode Search (PNode Tree, char *word) // word - покажчик на ключове слово
{
    if ( !Tree ) return NULL; // дійшли до листка - і потрібний ключ не знайшли...
    if (strcmp(word,Tree->name)==0){
        Tree->count++;        // ключ знайдено! (в корені всього дерева або будь-якого піддерева)
        return Search ( Tree->right, word);
    }
    if (strcmp(Tree->name,word) > 0) // якщо шуканий ключ за алфавітом йде раніше кореня - шукаємо далі в лівому піддереві
        return Search ( Tree->left, word);
    else return Search ( Tree->right, word); // інакше - в правому піддереві
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
    PNode Tree; // покажчик на корінь дерева
    Tree = NULL;
    Load(&Tree);
    if(Tree){
        printf("The tournament table: \n");//від найменшої до найбільшої кількості очок)
        PrintLKP(Tree); //здійснити обхід дерева за схемою ЛКП
    }
    else
        printf("File is absent in the currant directory");

    free(Tree);
    Tree = NULL;
    return 0;
}
