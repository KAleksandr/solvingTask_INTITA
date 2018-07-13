#include <iostream>

int main()

{

const int MAX = 80; // оголошуємо константу - максимальну довжину рядка

char str[MAX];



cout << "Input string: "; // виводимо підказку

cin >> str; // програма готова до введення (в кінці - натиснути Enter)

cout << "You’ve input: " << str << endl; // вивести введений рядок на екран

     return 0;

}
