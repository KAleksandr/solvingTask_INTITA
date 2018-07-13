#include <iostream>
using namespace std;
struct Club
{
    char name[25];
    char city[25];
    int place;
    int score;
};

void inputClub(char*, int*);
void inputClub(char*, char*, int*);
void inputClub(char*, char*, int*, int*);
void sortClub(Club *pmyClub, int size);
void printClub(Club *pmyclub, int n);
int main()
{
   int n;

   do{
      printf("Input N(4<n<=20): ");
      scanf("%i",&n);
   }
   while(!(n>4 && n<=20));
   Club *myclub = new Club[n];
   /*
    *  - в першому циклі за допомогою функції inputClub(char*, int*)
    * вводяться назви клубів і кількість набраних очок
    * (аргументи функції - адреси полів name i score кожної структури динамічного масиву);
    */
//---------------------------------------------
   for(int i=0; i<n; i++){
       inputClub(myclub[i].name, &(myclub[i].score));
   }
   cout << endl;

/*
 * в другому циклі за допомогою функції inputClub(char*, char*, int*) виводяться на екран назви клубів
 *  і кількість набраних очок, після чого вводиться назва міста, яке представляє клуб
 * (аргументи функції - адреси полів name, city i score кожної структури динамічного масиву);
 */
//---------------------------------------------
    for(int i=0; i<n; i++){
        inputClub(myclub[i].name, myclub[i].city, &(myclub[i].score));
    }
    cout << endl;
    sortClub(myclub,n);
    //-----------------------------------------------
    for(int i=0; i<n; i++){
        cout << "[" << i+1 << "] ";
        inputClub(myclub[i].name, myclub[i].city, &(myclub[i].score), &(myclub[i].place));
    }
    cout << endl;
    //------------------------------------------------
    printClub(myclub, n);

    free(myclub);
    myclub = NULL;
    return 0;

}
void inputClub(char*name, int*score){
    cout << "Input name(club): ";
    cin >> name;
    cout << "Input score: ";
    cin >> *score;
    //
}
void inputClub(char*name, char*city, int *score){

    cout << "CLUB: " << name;
    cout << "\tSCORE: " <<  *score << " ";
    cout << "\tInput city(club): ";
    cin >> city;
}
void inputClub(char*name, char*city, int*score, int*place){
    cout << "CLUB: " << name << "\tCITY: " << city;
    cout << "\tSCORE: " <<  *score;
    cout << "\tInput place(club): ";
    cin >> *place;
}
void sortClub(Club *pmyClub, int size)
{
    Club tmp;
    int min;
    for(int i=0; i<size-1;i++){
        min=i;
        for(int j=i+1; j<size;j++){
            if(pmyClub[i].score < pmyClub[j].score)
                if(pmyClub[min].score < pmyClub[j].score)
                   min = j;
         }
        tmp=pmyClub[i];
        pmyClub[i]=pmyClub[min];
        pmyClub[min] = tmp;
    }
}
void printClub(Club *pmyclub, int n){
   for(int i=0; i<n; i++){
       cout << "[" << i+1 << "] ";
       cout << "CLUB: " << pmyclub[i].name << "\tCITY: " << pmyclub[i].city;
       cout << "\tSCORE: " <<  pmyclub[i].score;
       cout << "\tPLACE: " << pmyclub[i].place << endl;
    }
}
