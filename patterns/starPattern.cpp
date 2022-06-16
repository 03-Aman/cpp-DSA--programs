#include <iostream>
using namespace std;
int main()
{
    int n, i = 1, sp, j;
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
        while (j <= 2*i-1)
        {
            cout << "*";
            j++;
        }
        cout << endl;
        i++;
    }
    

    return 0;
}