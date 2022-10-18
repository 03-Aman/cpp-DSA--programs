#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array :";
    int zero = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 0)
            zero++;
    }
    cout << "Array after pushing all the zeroes to the end is: ";
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
            cout << arr[i] << " ";
    }
    for (int i = 0; i < zero; i++)
        cout << 0 << " ";

    return 0;
}