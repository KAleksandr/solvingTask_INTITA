#include <stdio.h>

int main()
{
    int place[7];
     enum BULGARCLUBS{
        Ludogorec = 1, Dunav = 3, Beroe = 5, Levsky = 7, ChernoMore = 8, Loko = 10, Etyr = 11,
         Razgrad = 1,Ruse = 3,StaraZagora = 5,Sofia = 7,Varna = 8,Plowdyv = 10,VelykoTyrnovo = 11
         };

    enum BULGARCLUBS f;
    for(int i = 0, j = 0; i <= Etyr && j < 7; i++){
        switch (i) {
        case(Ludogorec): place[j++]=i;
            break;
        case(Dunav): place[j++]=i;
            break;
        case(Beroe): place[j++]=i;
            break;
        case(Levsky): place[j++]=i;
            break;
        case(ChernoMore): place[j++]=i;
            break;
        case(Loko): place[j++]=i;
            break;
        case(Etyr): place[j++]=i;
            break;
        default:
            break;
        }
    }
    for(int i=0; i < 7; i++)
        printf("%d ", place[i]);
    return 0;
}
