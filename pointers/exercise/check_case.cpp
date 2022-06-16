#include <iostream>
using namespace std;
int main()
{

    char alph;
    cin >> alph;
    int i = alph;
    if (i >= 97 & i <= 122)
    {
        cout << "-1";
    }
    else if (i >= 65 & i <= 90)
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }

    return 0;
}