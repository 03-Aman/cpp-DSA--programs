#include <iostream>
using namespace std;
int main()
{
    int n, i = 1, j, k;
    cout << "Enter the number: ";
    cin >> n;
    while (i <= n)
    {
        j = 1;
        k = i;
        while (j <= i)
        {
            cout << k;
            j++;
            k++;
        }
        cout << endl;
        i++;
    }

    return 0;
}