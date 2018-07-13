#include <stdio.h>
#include <malloc.h>
#include <windows.h>
typedef struct _Node {
    void *value;
    char nameTeam[50];
    char  city[50];
    char country[50];
    float rbd;
    int place;
    struct _Node *next;
    struct _Node *prev;
} Node;

typedef struct _pNode {
    size_t size;
    Node *head;
    Node *tail;
} pNode;
//створює екземпляр структури
pNode* createpNode() {
    pNode *tmp = (pNode*) malloc(sizeof(pNode));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;

    return tmp;
}
// видаляє екземпляр структури
void deletepNode(pNode **list) {
    Node *tmp = (*list)->head;
    Node *next = NULL;
    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*list);
    (*list) = NULL;
}
//вставити спереду
void pushFront(pNode *list, void *data) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        exit(1);
    }
    tmp->value = data;
    tmp->next = list->head;
    tmp->prev = NULL;
    if (list->head) {
        list->head->prev = tmp;
    }
    list->head = tmp;

    if (list->tail == NULL) {
        list->tail = tmp;
    }
    list->size++;
}
//вставка в кінець
void pushBack(pNode *list, void *value) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        exit(3);
    }
    tmp->value = value;
    tmp->next = NULL;
    tmp->prev = list->tail;
    if (list->tail) {
        list->tail->next = tmp;
    }
    list->tail = tmp;

    if (list->head == NULL) {
        list->head = tmp;
    }
    list->size++;
}
void CreateNode(pNode *list, char *nameTeam, char *city,char *country, float rdb, int place ) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        exit(3);
    }
    strcpy(tmp->nameTeam,nameTeam);
    strcpy(tmp->city, city);
    strcpy(tmp->country, country);
    tmp->rbd = rdb;
    tmp->place = place;

    tmp->next = NULL;
    tmp->prev = list->tail;
    if (list->tail) {
        list->tail->next = tmp;
    }
    list->tail = tmp;

    if (list->head == NULL) {
        list->head = tmp;
    }
    list->size++;
}
Node* Find(pNode *list, char *country) {
    Node *tmp = list->tail;
    size_t i = 0;

    while (tmp && i < index) {
        tmp = tmp->next;
        i++;
    }

    return tmp;
}
Node* Find (pNode Tail, char *country){

    pNode q = Tail;

    while (q && (strcmp(q->country, country) == 0))
        q = q->prev;

return q;

}
Node* getNthq(pNode *list, size_t index) {
    Node *tmp = NULL;
    size_t i;

    if (index < list->size/2) {
        i = 0;
        tmp = list->head;
        while (tmp && i < index) {
            tmp = tmp->next;
            i++;
        }
    } else {
        i = list->size - 1;
        tmp = list->tail;
        while (tmp && i > index) {
            tmp = tmp->prev;
            i--;
        }
    }

    return tmp;
}
void printpNode(pNode *list, void (*fun)(void*)) {
    Node *tmp = list->head;
    while (tmp) {

       fun(tmp->place);
        tmp = tmp->next;
    }
    printf("\n");
}
void printInt(int *value) {

    printf("%d ", *((int*) value));
}
int main()
{
    pNode *list = createpNode();
//    int a, b, c, d, e, f, g, h;

//       a = 10;
//       b = 20;
//       c = 30;
//       d = 40;
//       e = 50;
//       f = 60;
//       g = 70;
//       h = 80;
//       //pushFront(list, &a);
//       //pushFront(list, &b);
//      // pushFront(list, &c);
//       pushBack(list, &d);
//       pushBack(list, &e);
//       pushBack(list, &f);
       CreateNode(list, "Team1", "Omsk", "China", 2.6, 2);
       printpNode(list, printInt);
    return 0;
}
