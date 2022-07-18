#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[2 * n] = {0};
    cout << "Enter the elements of array: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int x;
    cout << "Now enter the element that you wish to insert: ";
    cin >> x;
    int i = n - 1;
    for (; arr[i] > x; i--)
    {
        swap(arr[i + 1], arr[i]);
    }
    arr[i + 1] = x;
    cout << "The array after insertion is: " << endl;
    for (int i = 0; i < n + 1; i++)
        cout << arr[i] << " ";

    return 0;
}