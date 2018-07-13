#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
using namespace std;
enum FILES{
    clubs1 = 3,
    clubs2 = 4,
    clubs3 = 2
};
typedef struct
{
    string name;
    string city;
    int place;
    int score;
}Club;
int countWord( char str[]);
void inputClub(ifstream file,char*, char*, int*);
void inputClub(ifstream file,char*, char*, int*, int*);
void inputClub(ifstream file,char*, int*);
void printClub(Club *pmyclub, int n);
int main()
{
    string file_name;
    cout << "Please enter a file name: ";
    cin >> file_name;
    ifstream file(file_name+".txt");
        if (file.good())
            cout << "Open file\n";
        else{
            cout << "Error!  File not found";
            return -1;
        }
         int n =0;
         char buffer[1024];
         while (!file.eof()){
             file.getline(buffer,1024);
             strcat(buffer," ");
             n++;
         }
    Club *myclub = new Club[n];
    int type = countWord(buffer);

    switch (type) {
    case clubs1:

        break;
    case clubs2:
        break;
    case clubs3:
        break;
    default:
        break;
    }

    return 0;
}
int countWord( char str[1024]){
        char *p = str;
        char word[30];
        int i = 0;
        while (sscanf(p, "%s", word) != EOF )
        {
           p += strlen(word)+1;
            i++;
        }
        return i;
}
void inputClub(ifstream file, char*name, char*city, int *score){
    while (!file.eof()){
        cin >> name;
        cin >> city;
        cin >> *score;
    }
}
void inputClub(ifstream file, char*name, char*city, int *score, int* place){
    while (!file.eof()){
        cin >> name;
        cin >> city;
        cin >> *score;
        cin >> *place;
    }
}
void inputClub(ifstream file, char*name,int* place){
    while (!file.eof()){
        cin >> name;
        cin >> *place;
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
