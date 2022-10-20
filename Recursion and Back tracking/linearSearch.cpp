#include <bits/stdc++.h>
using namespace std;
bool linearSearch(int arr[], int n, int key)
{
    if (n == 0)
        return false;
    if (arr[0] == key)
        return true;
    linearSearch(arr + 1, n - 1, key);
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
    if (linearSearch(arr, n, key))
        cout << "Found ";
    else
        cout << "Not found";
    return 0;
}