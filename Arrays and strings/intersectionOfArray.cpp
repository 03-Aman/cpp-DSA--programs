#include <iostream>
using namespace std;
int main()
{
    int n1, n2, ans;
    cout << "Enter the sizes of array: ";
    cin >> n1 >> n2;
    int arr1[n1], arr2[n2];
    cout << "Enter the elements of first array: " << endl;
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    cout << "Enter the elements of second array: " << endl;
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                ans = arr1[i];
                break;
            }
        }
    }
    cout << "The common element is: " << ans;

    return 0;
}