#include<iostream>
using namespace std;

// Есть ли середина?
int is_center(int left, int right)
{
  return !((left + right) % 2);
}
// Рекурсивный поиск минимума
int min(int a[], int left, int  right)
{
  int x, y, m, center;
  // Точка возврата из рекурсии
  if (left == right) return a[left];
  // Вычисляем середину
  m = (left + right) / 2;

  // Минимум слева от середины
  if(is_center(left, m))
    x = min(a, left, m);
  else
    x = min(a, left, m - 1);
  // Минимум справа от середины
  if(is_center(m, right))
    y = min(a, m, right);
  else
    y = min(a, m + 1, right);
  // Выбираем минимальный из результатов
  if (x < y) return x;
  else return y;
}
int main()
{
//  int mas[5]={1,2,3,4,5};
  int mas[5]={5,4,1,2,6};
  cout << min(mas, 0, 4) << endl;
  system("pause");
  return 0;
}
