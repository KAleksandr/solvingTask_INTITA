#include <iostream>

using namespace std;

int main()
{
//    int N;
//    string teams[N],towns[N];
//    int places[N];

    string teams[10]={"Ludogorec", "Dunav", "Beroe", "Levsky", "ChernoMore", "Loko", "Etyr","Vorskla", "Tels", "Bruclin"}
                     , towns[10]={"Razgrad", "Ruse", "StaraZagora", "Sofia", "Varna", "Plowdyv", "VelykoTyrnovo", "Tokio", "Lunes", "Kim"};
    int places[10] = {2,5,3,1,4,7,6,8,10,9};
    int N=10;

    string names[N];
    struct Club
    {
       string name;
       string city;
       int place;
    };
    Club *clubs;
    clubs = new Club[N];
    for(int i=0; i<N;i++){
        clubs[i].name = teams[i];
        clubs[i].city = towns[i];
        clubs[i].place = places[i];
    }
    int kiter;
    Club tmp;
    //sort вибором
    for(int i=0; i<N-1; i++){
        kiter = i;
        tmp = clubs[i];
        for(int j=i+1; j <N;j++){
            if(clubs[j].place < tmp.place){
                kiter = j;
                tmp = clubs[kiter];
            }
        }
        clubs[kiter] = clubs[i];
        clubs[i] = tmp;
    }
    for(int i=0; i<N;i++){
        names[i]=clubs[i].name;
    }
    for(auto now : names)
        cout << now << endl;
    delete[]clubs;
    return 0;
}
