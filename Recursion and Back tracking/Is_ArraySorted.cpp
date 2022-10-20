#include <bits/stdc++.h>
using namespace std;
bool IsSorted(int arr[], int n)
{
    if (n == 0 || n == 1)
        return true;
    if (arr[0] > arr[1])
        return false;
    IsSorted(arr + 1, n - 1);
}
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (IsSorted(arr, n))
        cout << "Sorted";
    else
        cout << "Unsorted";

    return 0;
}