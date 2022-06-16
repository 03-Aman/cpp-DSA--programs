#include <iostream>
using namespace std;
int main()
{
    int var = 30;
    int *ptr1, **ptr2;
    ptr1 = &var;
    ptr2 = &ptr1;
    cout << var << endl;
    cout << "at ptr1= " << *ptr1 << endl;
    cout << "at ptr2= " << *ptr2;

    return 0;
}