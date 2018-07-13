//Напишіть функцію, яка б мала вхідним параметром статичний масив arr з 20 дійсних чисел і виконувала наступне:
//1) підрахунок (із записом відповідної кільності у змінну N) від’ємних чисел у масиві arr;
//2) створити 2 динамічні масиви (розмірністю N і 20-N), в які окремо розмістити від’ємні і додатні числа з масиву arr;
//3) порахувати середнє арифметичне обох масивів;
//4) в динамічному масиві, середнє арифметичне елементів якого виявиться більше (за модулем) - записати це середнє арифметичне замість елемента (елементів), який (які) виявиться до нього найближчим(и);
//5) змінений в п.4. динамічний масив скопіювати до масиву arr (в перші N або 20-N комірок), решту комірок масиву arr - обнулити;
//6) повернути через return масив arr.
//!!! Пройшла з першого разу!!!

#include <stdio.h>
#include <iostream>

using namespace std;
#define M 20
float * func (float * arr)
{
    int N=0;
    int k , j;
    float sar=0, sum1=0,sum2=0;
    float * mas = new float [20];
    mas = arr;
    for(int i=0; i<20; i++){
        if(mas[i]<0){
            N++;
        }
    }
    //створення динамічних масивів

    float * mas_new1 = new float [N];
    float * mas_new2 = new float [20-N];
    k=0; j=0; sum1= 0; sum2 = 0;
    //Заповнення масивів - і + елементами з масиву arr
    for(int i=0; i<20; i++){
        if(mas[i]<0){
            mas_new1[k] = arr[i];
            sum1+=mas_new1[k];
            k++;
        }
        else if(mas[i] > 0){
            mas_new2[j] = arr[i];
            sum2+=mas_new2[j];
            j++;
        }

    }
    //середнє арифметичне і

    if((sum1*(-1)/k)> (sum2/j)){
        sar = sum1/j;
        float min, bl=mas_new1[0];

        if(bl >= sar) min = bl -sar;
        else min = sar - bl;

        for(int i=0; i< N; i++){
            if(mas_new1[i] >= sar && (mas_new1[i] - sar) < min){
                bl=mas_new1[i];
                min = mas_new1[i]-sar;
            }
            if(mas_new1[i]<= sar && (sar-mas_new1[i]) <min){
                bl = mas_new1[i];
                min = sar - mas_new1[i];
            }
        }
        //cout << sar << endl;
        //заміна на середнє арифметичне
        for(int i = 0; i< N; i++){
            if(sar - mas_new1[i] == min || mas_new1[i] - sar == min){
                mas_new1[i] = sar;
            }

        }
        //for (int i = 0; i <1; i ++)
           //printf ( "%f ", mas_new1 [i]);
           //cout << endl;
        //Заповнення основного масиву зміненими елементами
        for(int i=0; i<20; i++){
            if( i< N){
                mas[i] = mas_new1[i];
            }
            else{
                mas[i] = 0;
            }
        }
    }
    else{
        sar = sum2/j;
        float min, bl=mas_new2[0];

        if(bl >= sar) min = bl -sar;
        else min = sar - bl;

        for(int i=0; i<20 - N; i++){
            if(mas_new2[i] >= sar && (mas_new2[i] - sar) < min){
                bl=mas_new2[i];
                min = mas_new2[i]-sar;
            }
            if(mas_new2[i]<= sar && (sar-mas_new2[i]) <min){
                bl = mas_new2[i];
                min = sar - mas_new2[i];
            }
        }
        //cout << sar << endl;
        //заміна на середнє арифметичне
        for(int i = 0; i<20 - N; i++){
            if(sar - mas_new2[i] == min || mas_new2[i] - sar == min){
                mas_new2[i] = sar;
            }

        }
        //for (int i = 0; i <20 - N; i ++)
           //printf ( "%f ", mas_new2 [i]);
          // cout << endl;
        //Заповнення основного масиву зміненими елементами
        for(int i=0; i<20; i++){
            if( i< 20 - N){
                mas[i] = mas_new2[i];
            }
            else{
                mas[i] = 0;
            }
        }
    }



 return mas;
}

int main ()
{
 float mas [M] = {6.0, 8.0, 10.0, 12.0, 14.0, 16,0,0,0,0,-12,-18,-16,-14,-9, -12.0, -20.0, -6.0, -24.0, -10.0};
 float * mas_new;

 for (int i = 0; i <M; i ++)
    printf ( "%f ", mas [i]);
    cout << endl;
 mas_new = func (mas);

 for (int i = 0; i <20; i ++)
printf ( "%f ", mas_new [i]);
    cout << endl;
 delete mas_new;
 return 0;
}
