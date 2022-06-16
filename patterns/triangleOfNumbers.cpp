#include <iostream>
using namespace std;
int main()
{
    int n, i = 1, sp, k, j;
    cout << "Enter the number: ";
    cin >> n;
    while (i <= n)
    {
        sp = 1;
        while (sp <= n - i)
        {
            cout << " ";
            sp++;
        }
        k = i;
        j = 1;
        while (j <= 2 * i - 1)
        {
            cout << k;
            if (j < i)
            {
                k++;
            }
            else
            {
                k--;
            }
            j++;
        }
        i++;
        cout << endl;
    }

    return 0;
}