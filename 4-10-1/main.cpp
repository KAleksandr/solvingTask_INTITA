#include <iostream>

using namespace std;

void Natural(int n);

int main()
{
    int a;
    do{
        cout << "Input number: ";
        cin >> a;
    }
    while (!(a>0));

    cout << "Natural numbers ";
    Natural(a);
    cout << endl;

    cout << endl;
    return 0;
}


void Natural (int n)
{
    if  (n > 1)
        Natural (n - 1) ;
    cout  << n <<  " ";
}


