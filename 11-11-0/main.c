// побудова двійкового дерева за допомогою рекурсії
#include <stdio.h>
#include <conio.h>

struct Node {
    int key; // корисні дані (ключ)

    struct Node *left, *right; // покажчики на "вузли-сини"
};
typedef struct Node* PNode; // покажчик на деяку вершину

PNode MakeTree(int* data, int from, int n)
{
    PNode Tree;
    int n1, n2;
printf("%i\n", data[from]);
    if ( n == 0 ) return NULL; // умова завершення рекурсії
    Tree = (PNode)calloc(1,sizeof(struct Node)); // виділити пам'ять під новий вузол (вершину)
    Tree->key = data[from]; // записати у вузол корисні дані (ключ)
    n1 = n / 2; // визначити розмір піддерева
    n2 = n - n1 - 1;
    Tree->left = MakeTree(data, from+1, n1);
    Tree->right = MakeTree(data, from+1+n1, n2);
    return Tree;
}

// обхід дерева за схемою ЛКП
void PrintLKP(PNode Tree)
{
    if ( ! Tree ) return; // кінець рекурсії - досягнення "листка" (повертається значення покажчика left==NULL або right==NULL)
    PrintLKP(Tree->left); // обхід лівого піддерева
    printf("%d ", Tree->key); // виводимо "ключ" на екран
    PrintLKP(Tree->right); // обхід правого піддерева
}

void PrintKLP(PNode Tree)
{
    if ( ! Tree ) return; // кінець рекурсії - досягнення "листка" (повертається значення покажчика left==NULL або right==NULL)
    printf("%d ", Tree->key); // виводимо "ключ" на екран
    PrintKLP(Tree->left); // обхід лівого піддерева
    PrintKLP(Tree->right); // обхід правого піддерева
}

void PrintLPK(PNode Tree)
{
    if ( ! Tree ) return; // кінець рекурсії - досягнення "листка" (повертається значення покажчика left==NULL або right==NULL)
    PrintLPK(Tree->left); // обхід лівого піддерева
    PrintLPK(Tree->right); // обхід правого піддерева
    printf("%d ", Tree->key); // виводимо "ключ" на екран
}

// вставка нового вузла в дерево пошуку
void AddToTree (PNode *Tree, int data)// покажчик на корінь, цілочисельний ключ
{
    if ( ! (*Tree) ) {
        (*Tree) = (PNode)calloc(1,sizeof(struct Node)); // створити новий вузол
        (*Tree)->key = data;
        (*Tree)->left = NULL;
        (*Tree)->right = NULL;
        return;
    }
//	else printf("%d ",inTree->key);
//	getchar();
    if ( data < (*Tree)->key ) // додавання вузла у потрібне (ліве чи праве) піддерево
        AddToTree (&(*Tree)->left, data);
    else AddToTree (&(*Tree)->right, data);
}

PNode Search (PNode Tree, int what)
{
    if ( ! Tree ) return NULL; // все обійшли - і потрібний ключ не знайшли...
    if ( what == Tree->key ) return Tree; // ключ знайдено! (в корені)
    if ( what < Tree->key ) // якщо шуканий ключ менше кореня - шукаємо далі в лівому піддереві
        return Search ( Tree->left, what );
    else return Search ( Tree->right, what ); // інакше - в правому піддереві
}

main()
{
    int data[] = {17, 21, 8, 9, 11, 15, 19, 20, 7};
    PNode Tree; // покажчик на корінь дерева
    int i,n = sizeof(data) / sizeof(int); // розмір масиву
    char c;

    Tree = MakeTree(data, 0, n); // побудувати дерево з n вузлів, починаючи з елемента масиву під номером 0
    printf("Obxid dereva za LKP0: ");
    PrintLKP(Tree); //здійснити обхід дерева за схемою ЛКП
    printf("\nObxid dereva za KLP: ");
    PrintKLP(Tree); //здійснити обхід дерева за схемою ЛКП
    printf("\nObxid dereva za LPK: ");
    PrintLPK(Tree); //здійснити обхід дерева за схемою ЛКП
    Tree = NULL;
    for (i=0; i<n; i++) // побудувати дерево пошуку
        AddToTree(&Tree, data[i]);
    printf("\nObxid dereva za LKP: ");
    PrintLKP(Tree); //здійснити обхід дерева за схемою ЛКП
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
