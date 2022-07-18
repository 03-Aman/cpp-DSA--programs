#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int *p = new int[n];
    p[n] = {0};
    cout << "Enter the elements of array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    int in;
    cout << "Enter the index no. of element you wish to delete: ";
    cin >> in;
    for (int i = in; i < n; i++)
    {
        p[i] = p[i + 1];
        
    }
    
    for (int i = 0; i < n-1; i++)
    {
        cout << p[i] << " ";
    }

    return 0;
}