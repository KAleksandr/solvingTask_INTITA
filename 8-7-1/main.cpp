#include <iostream>

using namespace std;

int main()
{
    string teams[10]={"Ludogorec", "Dunav", "Beroe", "Levsky", "ChernoMore", "Loko", "Etyr","Vorskla", "Tels", "Bruclin"}
                     , towns[10]={"Razgrad", "Ruse", "StaraZagora", "Sofia", "Varna", "Plowdyv", "VelykoTyrnovo", "Tokio", "Lunes", "Kim"};
    int places[10] = {2,5,3,1,4,7,6,8,10,9};
    int N=8;

    typedef struct{
        string name;
        string city;
        int place;
    }Club;
    Club myClub[10];
    Club* pmyClub;
    pmyClub = myClub;
    for(int i=0; i<N; i++){
        (pmyClub)->name = teams[i];
        (pmyClub)->city = towns[i];
        (pmyClub)->place = places[i];
        pmyClub++;
    }
    pmyClub-=N;

   for(int i =0; i<N; i++){
       cout << pmyClub[i].name<<" ";
       cout << pmyClub[i].city << " ";
        printf("%d\n", pmyClub[i].place);
    }
   for(int i =0; i<N; i++)
       cout << places[i] << " ";
   cout << "---------------------" <<endl;

   for(int i =N; i>0; i--){
       pmyClub[i] = pmyClub[i-1];
   }

   pmyClub->name = "Neftohimik";
   pmyClub->city = "Burgas";
   pmyClub->place = 8;
   for(int i =0; i<N; i++){
       cout << pmyClub[i].name<<" ";
       cout << pmyClub[i].city << " ";
        printf("%d\n", pmyClub[i].place);
    }
   for(int i =0; i<N+1; i++)
       places[i]=(pmyClub++)->place;

   for(int i =0; i<N+1; i++)
       cout << places[i] << " ";
    return 0;
}

