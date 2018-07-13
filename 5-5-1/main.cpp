#include <string>
#include <iostream>
using namespace std;
#define N 80
void copy2(char* str1, char* str2);
int find(char *str);
int main()
{
    char name[N]="Input first name and last name:";
    string text = "Inputy first name and last namye:";
    //char t = (char)find(name);

        int p = -1;
        int x=-1;
        while(p==-1){
            p= text.find_last_of('y');
            if(p !=-1 || p==x){
                if(p==x)
                    break;
                else {
                    x=p;
                    p =-1;
                }
            }
        }


    printf("%i",x);


    return 0;
}

//void copy2(char* str1, char* str2)
//{
//    while((*str1++ = *str2++));
//    }
//int find(string str){
//        char *ps;
//        int i=0,k=-1;
//        ps = &str;
//        while(*ps !=0){
//            i++;
//            if(*ps++ =='y')
//                k = i;
//        }
//    return k;
//}
