#include <iostream>
#include <malloc.h>

using namespace std;
struct Club
{
    char name[25];
    char city[25];
    int place;
    int score;
};
typedef struct Club *pclub;

void inputClub(char*, int*);
void inputClub(char*, char*, int);
void inputClub(char*, char*, int*, int*);
int main()
{
   int n;
   pclub myclub;
   do{
      printf("Input N(4<n<=20): ");
      scanf("%i",&n);
   }
   while(!(n>4 && n<=20));
   myclub = (pclub)calloc(n, sizeof(pclub));
   /*
    *  - в першому циклі за допомогою функції inputClub(char*, int*)
    * вводяться назви клубів і кількість набраних очок
    * (аргументи функції - адреси полів name i score кожної структури динамічного масиву);
    */
//---------------------------------------------
   for(int i=0; i<n; i++){
       inputClub(myclub[i].name, &(myclub[i].score));
   }

//---------------------------------------------
    for(int i=0; i<n; i++){
        inputClub(myclub[i].name, myclub[i].city, (myclub[i].score));
    }

    return 0;

}
void inputClub(char*name, int*score){
    cout << "Input name(club): ";
   cin >> name;
    cout << "Input score: ";
    int n;
    cin >> n;
    *score =n;
}
void inputClub(char*name, char*city, int score){

    cout <<"|-----------------------------------------------------------------|\n";
    cout << "CLUB: " << name;
printf("  %d  ",score);
    cout << "\tSCORE: " <<  score << endl;
    //cout << "|-----------------------------------------------------------------|\n\n\n";
    cout << "Input city(club): ";
    cin >> city;
}

