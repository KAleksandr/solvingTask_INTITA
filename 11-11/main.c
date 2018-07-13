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
    int score; // корисні дані (ключ)

    struct Node *left, *right; // покажчики на "вузли-сини"
};
typedef struct Node* PNode; // покажчик на деяку вершину

PNode MakeTree(pClub data, int from, int n)
{
    PNode Tree;
    int n1, n2;
printf("%i", data[from].score);
    if ( n == 0 ) return NULL; // умова завершення рекурсії
    Tree = (PNode)calloc(1,sizeof(struct Node)); // виділити пам'ять під новий вузол (вершину)
    int score = data[from].score;
    Tree->score = score; // записати у вузол корисні дані (ключ)
     Tree->goalsScored = data[from].goalsScored;
    Tree->missedBalls = data[from].missedBalls;

    strcpy(Tree->city, data[from].city);
    strcpy(Tree->name, data[from].name);
    n1 = n / 2; // визначити розмір піддерева
    n2 = n - n1 - 1;
    Tree->left = MakeTree(data, from+1, n1);
    Tree->right = MakeTree(data, from+1+n1, n2);
    return Tree;
}

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
        PNode Tree; // покажчик на корінь дерева
        Tree = NULL;

        Tree = MakeTree(pmyclub, 0, n); // побудувати дерево з n вузлів, починаючи з елемента масиву під номером 0
        printf("Obxid dereva za LKP: ");
        PrintLKP(Tree); //здійснити обхід дерева за схемою ЛКП

    free(pmyclub);
    free(Tree);
    Tree = NULL;

    return 0;
}
