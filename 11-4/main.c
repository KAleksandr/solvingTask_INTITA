#include <stdio.h>

struct Node {
    char data; // символ, що зберігається в стеку
    struct Node *next, *prev;
};
typedef struct Node* PNode;
typedef struct  {
   PNode Head; // початкова ініціалізація “голови”
   PNode Tail;    // і “хвоста” стека
}Stack;
int main()
{
    printf("Hello World!\n");
    return 0;
}
char Pop (Stack *S ) // функція отримання і видалення “верхнього” вузла стеку

{
    PNode TopNode = *S.Head; // покажчик на вершину стеку
    char x;
    if (!TopNode ) // якщо стек пустий (TopNode==NULL) -
    return char(255); // то повернути символ з кодом 255
    x = TopNode->data; // отримуємо символ з вершини стеку
    *S.Head = TopNode->next; // пересуваємо покажчик вершини на наступний вузол
    // якщо вузлів у стеку більше немає - S.Head прийме значення NULL
    if (*S.Head) // якщо стек не залишився пустий
    *S.Head->prev = NULL; // “обнуляємо” покажчик prev вузла, який став вершиною
    else *S.Tail = NULL; // інакше - “обнуляємо” також покажчик на “хвіст”
    free(TopNode); // звільняємо пам’ять від елемента TopNode
    return x; // повертаємо в основну програму символ з вершини стеку

}
