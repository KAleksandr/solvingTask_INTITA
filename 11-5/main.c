#include <stdio.h>
struct Node {
        char name[20];
        char city[20];
        int goalsScored;
        int missedBalls;
        int score;
    struct Node *next, *prev;

};
typedef struct Node* PNode;
struct Queue { //Queue- ����� (����.)
    PNode Head ; // ����������� �������
    PNode Tail;// � ���� �����
};

int main()
{
    printf("Hello World!\n");
    return 0;
}
