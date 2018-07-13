#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <cstdlib>
using namespace std;
enum FILES{
    clubs1 = 3,
    clubs2 = 4,
    clubs3 = 2
};
typedef struct
{
    char name[30];
    char city[30];
    int place;
    int score;
}Club;
int countWord( char str[]);
void inputClub(char buffer[],char*, char*, int*);
void inputClub(char buffer[],char*, char*, int*, int*);
void inputClub(char buffer[],char*, int*);
void printClub(Club *pmyclub, int n);
int main()
{
    string file_name;
    int type;
    cout << "Please enter a file name: ";
    cin >> file_name;
    ifstream file(file_name+".txt");
        if (file.good())
            cout << "Open file\n";
        else{
            cout << "Error!  File not found";
            return -1;
        }
        Club *myclub = new Club[1];
         int n =0;
         char buffer[1024];

         while (!file.eof()){
             myclub = (Club*)realloc(myclub,sizeof(*myclub)*(n+1));
             file.getline(buffer,1024);
             strcat(buffer," ");

             type = countWord(buffer);
             switch (type) {
             case clubs1:
                       inputClub(buffer, myclub[n].name,myclub[n].city,&myclub[n].score);
                 break;
             case clubs2:
                 inputClub(buffer, myclub[n].name,myclub[n].city,&myclub[n].score, &myclub[n].place);
                 break;
             case clubs3:
                  inputClub(buffer, myclub[n].name, &myclub[n].place);
                 break;
             default:
                 break;
             }
             n++;
         }
    printClub(myclub,n);
    file.close();
    free(myclub);
    myclub = NULL;
    return 0;
}
int countWord(char str[]){
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
void inputClub(char buffer[], char*name, char*city, int *score){
        char *p = buffer;
        char k[10];
        sscanf(p, "%s", name);
        p += strlen(name)+1;
        sscanf(p, "%s", city);
        p += strlen(city)+1;
        sscanf(p, "%s", k);
        *score = atoi(k);
}
void inputClub(char buffer[], char*name, char*city, int *score, int* place){
    char *p = buffer;
    char k[10];
    sscanf(p, "%s", name);
    p += strlen(name)+1;
    sscanf(p, "%s", city);
    p += strlen(city)+1;
    sscanf(p, "%s", k);
    p += strlen(k)+1;
    *score = atoi(k);
    sscanf(p, "%s", k);
    *place = atoi(k);
 }
void inputClub(char buffer[], char*name,int* place){
    char *p = buffer;
    char k[10];
    sscanf(p, "%s", name);
    p += strlen(name)+1;
    sscanf(p, "%s", k);
    *place = atoi(k);
}
void printClub(Club *pmyclub, int n){
   for(int i=0; i<n; i++){
       cout << "[" << i+1 << "] ";
       cout << "CLUB: " << pmyclub[i].name;
       cout.setf(ios::right);
       cout.width(10);
       cout << "\t\tCITY: " << pmyclub[i].city;
       cout.setf(ios::left);
       cout.width(15);
       cout << "\t\tSCORE: " <<  pmyclub[i].score;
       cout.setf(ios::right);
       cout.width(10);
       cout << "\tPLACE: " << pmyclub[i].place << endl;
    }
}
