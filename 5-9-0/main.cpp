#include <iostream>
#include <string>
#include <malloc.h>
using namespace std;

int main () {
    string str1= "Test";
      string str2 = "Stroka";

      int n=2;
//     str2.insert (1,"!");
//     cout << str2.c_str() << endl;
     int t1 = str1.size();
     int t2 = str2.size();
    const char *s1 = str1.c_str();
    const char *s2 = str2.c_str();
    char *pst = "Text";
    printf("%p\n",pst);
        printf("%p\n",s1);
    string s3;
    if(n <= (int)sizeof(s1)){
        if((int)sizeof(s1)>= (int)sizeof(s2)-n){
            s1 = s2+n-1;
            s3 = str2.substr(n-1);
             cout << s1<<endl;
             cout << s3<<endl;
        }
        else cout << "Error" <<endl;

    }
    else cout << "Error" <<endl;

//     cout << t <<endl;


     cin.get(); return 0;
}
