#include <iostream>
using namespace std;
int main()
{
    int a[3] = {1, 5, 55};
    int *ptr = &a[0];
    for (int i = 0; i < 3; i++)
    {
        cout << *ptr<<endl;
        ptr++;
    }

    return 0;
}



