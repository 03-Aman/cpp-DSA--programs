#include <iostream>
using namespace std;
int main()
{
   int n = 123;
   int rem, tem = 0;
   while (n > 0)
   {
      rem = n % 10;
      tem = tem * 10 + rem;
      n = n / 10;
   }
   cout << tem;
   return 0;
}