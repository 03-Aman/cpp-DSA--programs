#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int s = i; s <= n - i; s++)
        {
            cout << " ";
        }
        int k = i;
        for (int j = 1; j <= (2 * i - 1); j++)
        {
            if (j < n - 1)
            {

                k++;
            }
            else
            {
                k--;
            }
            cout << k << " ";
        }
        cout << endl;
    }

    return 0;
}