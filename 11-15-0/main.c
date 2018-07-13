#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct Node {
    char key[40]; // корисні дані (слово-ключ)
    int count;  // лічильник повторень
    struct Node *left, *right; // покажчики на "вузли-сини"
};
typedef struct Node* PNode; // покажчик на деякий вузол

// обхід дерева за схемою ЛКП
void PrintLKP(PNode Tree)
{
    if ( ! Tree ) return; // кінець рекурсії - досягнення "листка" (повертається значення покажчика left==NULL або right==NULL)
    PrintLKP(Tree->left); // обхід лівого піддерева
    printf("%s - %d\n", Tree->key,Tree->count); // виводимо "ключ" кореня на екран
    PrintLKP(Tree->right); // обхід правого піддерева
}
//і за іншими схемами
void PrintLPK(PNode Tree)
{
    if ( ! Tree ) return; // кінець рекурсії - досягнення "листка" (повертається значення покажчика left==NULL або right==NULL)
    PrintLPK(Tree->left); // обхід лівого піддерева
    PrintLPK(Tree->right); // обхід правого піддерева
    printf("%s - %d\n", Tree->key,Tree->count); // виводимо "ключ" кореня на екран
}

void PrintKLP(PNode Tree)
{
    if ( ! Tree ) return; // кінець рекурсії - досягнення "листка" (повертається значення покажчика left==NULL або right==NULL)
    printf("%s - %d\n", Tree->key,Tree->count); // виводимо "ключ" кореня на екран
    PrintKLP(Tree->left); // обхід лівого піддерева
    PrintKLP(Tree->right); // обхід правого піддерева
}

void PrintPKL(PNode Tree)
{
    if ( ! Tree ) return; // кінець рекурсії - досягнення "листка" (повертається значення покажчика left==NULL або right==NULL)
    PrintPKL(Tree->right); // обхід правого піддерева
    printf("%s - %d\n", Tree->key,Tree->count); // виводимо "ключ" кореня на екран
    PrintPKL(Tree->left); // обхід лівого піддерева
}

// вставка нового вузла в дерево пошуку
void AddToTree(PNode *Tree, char *word)// параметри - адреса покажчика на корінь, покажчик на ключове слово
{// щоб доступитися до даних кореня - адресу його покажчика далі всюди розіменовуємо
    if ( ! *Tree ) { // якщо дерево пусте або дійшли до "листка" -
        (*Tree) = (PNode)calloc(1,sizeof(struct Node)); // створити новий вузол
        strcpy((*Tree)->key,word);
        (*Tree)->count=1;
        (*Tree)->left = NULL;
        (*Tree)->right = NULL;
        return;
    }
    if (strcmp((*Tree)->key,word) > 0) // додавання вузла у потрібне (ліве чи праве) піддерево
        AddToTree ( &(*Tree)->left, word);
    else AddToTree ( &(*Tree)->right, word);
}
// пошук ключового слова в дереві
PNode Search (PNode Tree, char *word) // word - покажчик на ключове слово
{
    if ( ! Tree ) return NULL; // дійшли до листка - і потрібний ключ не знайшли...
    if (strcmp(word,Tree->key)==0) return Tree; // ключ знайдено! (в корені всього дерева або будь-якого піддерева)
    if (strcmp(Tree->key,word) > 0) // якщо шуканий ключ за алфавітом йде раніше кореня - шукаємо далі в лівому піддереві
        return Search ( Tree->left, word);
    else return Search ( Tree->right, word); // інакше - в правому піддереві
}

int main()
{
    FILE *in;
    int n;
    char word[40];
    PNode p,Tree; // покажчик на корінь дерева

    Tree = NULL;
    in = fopen("inp_eng.txt","r");
    if (in) {
      printf("File open successful! Press ENTER\n");
      getchar();

      while(1) {
        n = fscanf(in,"%s",word); // читаємо слово з файлу
        if (n<=0) break; // якщо слова закінчились - вихід з циклу
        p=Search(Tree,word); // пошук адреси вузла, де поточне слово вже існує
        if (p) p->count++; // якщо знайшли - інкремент лічильника
        else AddToTree(&Tree,word); // інакше - утвор. новий вузол і вставка в нього слова, прочитаного з файлу
      }
      fclose(in);
      if (Tree) {

        PrintLKP(Tree);
        getchar();
        PrintPKL(Tree);
        getchar();

      }
      else printf("File is absent in the currant directory");
    }
    else printf("File is empty");
    getchar();
    return 0;
}
