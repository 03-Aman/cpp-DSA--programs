#include <iostream>
using namespace std;
int main()
{
    int i = 1, j, n, sp;
    cout << "Enter the number: ";
    cin >> n;
    while (i <= n)
    {
        sp = 1,j=1;
        if (i <= n / 2 + 1)
        {
            while (sp <= n / 2 + 1 - i)
            {
                cout << " ";
                sp++;
            }
            while (j <= 2 * i - 1)
            {
                cout << "*";
                j++;
            }
        }
        else
        {
            while (sp <= i - (n / 2 + 1))
            {
                cout << " ";
                sp++;
            }
            while (j)
            {
                /* code */
            }
            
        }

        cout << endl;
        i++;
        
    }

    return 0;
}