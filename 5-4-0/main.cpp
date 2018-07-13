#include <iostream>
#include <iomanip>
using namespace std;
int main()

{
    const int MAX = 10; // оголошуємо константу - максимальну довжину рядка

    char text[MAX];
    char *str;
    cout << "Input name: "; // виводимо підказку
    cin >> setw(MAX) >> text; // setw(MAX) може бути введено не більше, ніж MAX-1 символ,
    //інші символи будуть просто проігноровані програмою
    fflush(stdin);
    cout << "Hello " << text << endl; // вивести введений рядок на екран
    str = text;
    //виведення рядка за допомогою циклу по одному символу,
    //пересуваючи покажчик str кожного разу на наступний символ.
    while(*str != 0)
        cout << *str++;
    return 0;

}
