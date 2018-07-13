#ifndef RANKING_H
#define RANKING_H
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
using namespace std;
typedef struct
{
    char name[30];
    char city[30];
    int wins;
    int draws;
    int defeats;
    int score;
}Club;
struct Node {
    char name[30];
    char city[30];
    int wins;
    int draws;
    int defeats;
    int score;
    struct Node *left, *right; // покажчики на "вузли-сини"
};


void fileAnalize(Node **Tree);
void inputClub(char buffer[], char*name, char*city, int *wins, int *draws,int *defeats, int *score);
void printClub(Club *pmyclub, int n);
void makeTree(Node **Tree, char name[],char city[], int wins, int draws,int defeats, int score);
void PrintPKL(Node *Tree);
int countScore(char w[], char d[]);
#endif // RANKING_H
