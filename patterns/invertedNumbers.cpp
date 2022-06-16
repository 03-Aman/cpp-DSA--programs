#include <iostream>
using namespace std;
int main()
{

    int i, n, j, k;
    cout << "Enter the number: ";
    cin >> n;
    i = n;
    while (i > 0)

    {
        j = i;
        k = i;
        while (j > 0)
        {
            cout << k;
            j--;
        }

        i--;
        cout << endl;
    }

    return 0;
}