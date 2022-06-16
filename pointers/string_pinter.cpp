#include <iostream>
#include <string>
using namespace std;
int main()
{

    string var = "abc";
    string *ptr = &var;
    cout << var << endl;
    cout << &var << endl;
    cout << *ptr << endl;
    *ptr = "efg";
    cout << *ptr << endl;
    cout << var;

    return 0;
}