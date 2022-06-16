#include <iostream>
using namespace std;
int main()
{
    int n, i=1, sp, j, k = 1;
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
        j = 1;
        k=i;
        while (j <= i)
        {
            cout << k;
            k++;
            j++;
        }
        cout << endl;
        i++;
    }

    return 0;
}