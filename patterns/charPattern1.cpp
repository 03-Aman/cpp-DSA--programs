#include <iostream>
using namespace std;
int main()
{
    int n, i = 0, j;
    cin >> n;
    while (i < n)
    {
        j = 0;
        while (j <= i)
        {
            cout << char('A' + i);
            j++;
        }
        i++;
        cout << endl;
    }

    return 0;
}