#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the length of array: ";
    cin >> n;
    int v[n];
    cout << "Enter the elements of array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int *ptr = &v[0];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = *ptr + sum;
        ptr++;
    }
    cout << "The sum is : " << sum;

    return 0;
}