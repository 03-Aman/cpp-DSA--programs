#include <iostream>
using namespace std;
int main()
{
    int n, ans;
    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        while (j < n)
        {
            if (arr[i] == arr[j])
            {
                ans = arr[i];
                break;
            }
            j++;
        }
    }
    cout << "The Duplicate element is: " << ans;

    return 0;
}