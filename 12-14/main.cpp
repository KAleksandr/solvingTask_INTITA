#include <fstream>
#include "ranking.h"
using namespace std;

int main()
{
    Node *Tree = NULL;
    fileAnalize(&Tree);
    if(Tree){
        printf("The tournament table: \n");//�� �������� �� �������� ������� ����)
        PrintPKL(Tree); //�������� ����� ������ �� ������
    }
    else
        printf("File is absent in the currant directory");
    free(Tree);
    Tree = NULL;
    return 0;
}
