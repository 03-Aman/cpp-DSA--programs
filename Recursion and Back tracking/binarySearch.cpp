#include <bits/stdc++.h>
using namespace std;
bool binarySearch(int arr[], int start, int end, int key)
{
    if (start > end)
        return false;
    int mid = (start + end) / 2;
    if (arr[mid] == key)
        return true;
    else if (key > arr[mid])
        binarySearch(arr, mid + 1, end, key);
    else
        binarySearch(arr, start, mid - 1, key);
}
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int key;
    cout << "Now enter the key value you wish to find : ";
    cin >> key;
    if (binarySearch(arr, 0, n, key))
        cout << "Found ";
    else
        cout << "Not found";
    return 0;
}