#include <iostream>
#include <time.h>
using namespace std;

int NumNum( int *array, int array_size, int findnum, int *index )
{
    int flag =0;
    for(int i = *index; i< array_size; i++){
        if(array[i] == findnum){
            flag = 1;
            *index = i+1;
            break;
        }
    }
    if(flag == 0)
        return 0;
    else{
        return 1 + NumNum(array, array_size, findnum, index);
    }
}
void Fillarray(int *array, int arraySize){
    for( int i = 0; i < arraySize; i++ )// заповнення масиву
    {
        array[ i] = rand() % 100;
        cout << array[ i] << " ";
    }
}
int main()
{
    int index = 0;//початковий індекс шуканого елемента
    int find;//шуканий елемент
    int *pindex= &index;
    cout << "Enter size of array: ";
    int arraySize;

    cin >> arraySize;
    int *myArray = new int[ arraySize];
    srand( time(NULL) );

    cout << "Find an item: ";
    cin >> find;

    Fillarray(myArray, arraySize);//виклик функції заповнення масиву
    cout << endl;

    int foundIndex = NumNum( myArray, arraySize, find, pindex );
    cout<<"The number " << find << " of elements in this array: "<< foundIndex << endl;

    system("pause");
    return 0;
}
