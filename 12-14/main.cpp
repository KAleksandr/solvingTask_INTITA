#include <fstream>
#include "ranking.h"
using namespace std;

int main()
{
    Node *Tree = NULL;
    fileAnalize(&Tree);
    if(Tree){
        printf("The tournament table: \n");//від найбільшої до найменшої кількості очок)
        PrintPKL(Tree); //здійснити обхід дерева за схемою
    }
    else
        printf("File is absent in the currant directory");
    free(Tree);
    Tree = NULL;
    return 0;
}
