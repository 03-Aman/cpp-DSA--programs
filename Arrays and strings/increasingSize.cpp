#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int *p = new int[n];
    int *q = new int[2 * n];
    cout << "Enter the elements of array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++)
    {
        q[i] = p[i];
    }
    delete[] p;
    p = q;
    q=NULL;
    
    cout << "Enter the no. element: ";
    int y;
    cin >> y;
    cout << "Now start entering the elements" << endl;
    for (int i = 0; i < y; i++)
    {
        cin >> p[n + i];
    }
    cout << "Your after insertion is : " << endl;
    for (int i = 0; i < n+y ; i++)
    {
        cout << p[i] << " ";
    }

    return 0;
}