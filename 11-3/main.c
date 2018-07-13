#include <stdio.h>
struct Node {
    char data; // символ, що зберігається в стеку
    struct Node *next, *prev;
};
typedef struct Node* PNode;


int main()
{
    printf("Hello World!\n");
    return 0;
}
void Push ( Stack *S, char x) // процедура додавання вузла в стек

{// &S - посилання на структуру з параметрами стека; х - символ, що вноситься в стек

    PNode NewNode; // покажчик на новий вузол
    NewNode = (PNode)calloc(1,sizeof(struct Node));; // виділяємо пам’ять під новий вузол
    NewNode->data = x; // записуємо символ у новий вузол
    NewNode->next = *S.Head; // встановлюємо в новому вузлі покажчик next на колишній вузол-вершину (Head),
    NewNode->prev = NULL; // а покажчик prev - “обнуляємо”
    if (*S.Head ) // якщо стек був не пустий -
    *S.Head->prev = NewNode; // в колишньому вузлі-вершині покажчик prev встановлюємо на щойно доданий вузол NewNode
    *S.Head = NewNode; // так само - покажчик вершини стеку
    if (!*S.Tail ) *S.Tail = *S.Head; // змінюємо покажчик на “хвіст” (якщо стек був початково пустий)
}
