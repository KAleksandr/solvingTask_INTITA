#include <stdio.h>
#include <string.h>
char * STERT(char towns[][80]);
int main()
{
    char towns[7][80];
    STERT(towns);

    return 0;
}
char * STERT(char towns[][80]){
    typedef enum  {
        Ludogorec, Dunav, Beroe, Levsky, ChernoMore, Loko, Etyr, Clubend
    }CLUBS;
    typedef enum {
        Razgrad, Ruse, StaraZagora, Sofia, Varna, Plowdyv, VelykoTyrnovo, Townend
    }TOWN;

    typedef struct
    {
        char name[20];
        char city[20];
        int place;
    }Club;
    Club myClub[Clubend];


    for(int i =0; i<Clubend; i++){
        myClub[i].place = i;
        switch (i) {
        case Ludogorec: strcpy(myClub[i].name , "Ludogorec");
                        strcpy(myClub[i].city , "Razgrad");
            break;
        case Dunav: strcpy(myClub[i].name , "Dunav");
                    strcpy(myClub[i].city , "Ruse");
         break;
        case Beroe: strcpy(myClub[i].name , "Beroe");
                    strcpy(myClub[i].city , "StaraZagora");
         break;
        case Levsky: strcpy(myClub[i].name , "Levsky");
                    strcpy(myClub[i].city , "Sofia");
         break;
        case ChernoMore: strcpy(myClub[i].name , "ChernoMore");
                    strcpy(myClub[i].city , "Varna");
         break;
        case Loko: strcpy(myClub[i].name , "Loko");
                    strcpy(myClub[i].city , "Plowdyv");
         break;
        case Etyr: strcpy(myClub[i].name , "Etyr");
                    strcpy(myClub[i].city , "VelykoTyrnovo");
         break;
        default:
            break;
        }
    }

    for(int i =0; i<Clubend; i++){
        strcpy(towns[i], myClub[i].city);
        printf("%s\n",towns[i] );
    }
    return towns;
}
