#include <iostream>
#include <string.h>
using namespace std;

int main()
{
      int n=2;
      string str1= "Test56789101213";
      string str2 = "Strokast";
      char *s1 = &str1[0];
      char *s2 = &str2[0];

      //cin >> n;
    //getchar();
      freopen("out.txt", "r",stdin);//зчитування з файлу
      //getline(cin, str2);


         if(n <= (int)strlen(s1) && n < (int)strlen(s2)){
             if((int)strlen(s1)>= (int)strlen(s2)-n){
                 strcpy(s1+n,s2);
                  cout << s1;
             }
             else cout << "Error";

         }
         else cout << "Error";

    return 0;
}
