#include <iostream>
#include <string>
#include <malloc.h>
using namespace std;

int main () {
    string str1= "Test";
      string str2 = "Stroka";

      int n=2;



    string s3;
    if(n <= (int)str1.size()){
        if(str1.size() >= (str2.size()-n-1)){
            s3 = str2.substr(n-1);
            cout << s3<<endl;
        }
        else cout << "Error" <<endl;

    }
    else cout << "Error" <<endl;

//     cout << t <<endl;


     cin.get(); return 0;
}
