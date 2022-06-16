#include <iostream>
using namespace std;
int main()
{

    int v[3] = {10, 20, 30};
    int *ptr[3];
    for (int i=0; i < 3; i++)
    {
        ptr[i] = &v[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cout << *ptr[i] << " ";
    }

    return 0;
}