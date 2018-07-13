#include "ranking.h"
void fileAnalize(Node **Tree){// and fileRead

    string file_name;

    cout << "Please enter a file name: ";
    cin >> file_name;
    ifstream file(file_name+".txt");
        if (file.good())
            cout << "Open file\n";
        else{
            cout << "Error!  File not found";
            return;
        }
        Club *myClub = new Club[1];
         int n =0;
         char buffer[1024];

         while (!file.eof()){
             myClub = (Club*)realloc(myClub,sizeof(*myClub)*(n+1));
             file.getline(buffer,1024);
             strcat(buffer," ");

             inputClub(buffer, myClub[n].name,myClub[n].city,&myClub[n].wins, &myClub[n].draws, &myClub[n].defeats,  &myClub[n].score);

             n++;
         }
         for(int i=0; i<n;i++){
             makeTree(Tree, myClub[i].name, myClub[i].city, myClub[i].wins, myClub[i].draws, myClub[i].defeats,  myClub[i].score);
            //cout << myClub[i].score << endl;
         }
    //printClub(myClub,n);
    file.close();
    delete(myClub);
}
void inputClub(char buffer[], char*name, char*city, int *wins, int *draws,int *defeats, int *score){
    char *p = buffer;
    char k[10];
    char k2[10];

    sscanf(p, "%s", name);
    p += strlen(name)+1;
    sscanf(p, "%s", city);
    p += strlen(city)+1;
    sscanf(p, "%s", k);
    p += strlen(k)+1;
    *wins = atoi(k);
    sscanf(p, "%s", k2);
    *score = countScore(k,k2);
    *draws = atoi(k2);
    sscanf(p, "%s", k);
    *defeats = atoi(k);


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
       cout << "\t\tSCORE: " <<  pmyclub[i].wins;
       cout.setf(ios::right);
       cout.width(10);
       cout << "\tPLACE: " << pmyclub[i].draws << endl;
    }
}
