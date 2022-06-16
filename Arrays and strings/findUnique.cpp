#include <iostream>
using namespace std;
int main()
{
    int n, ans;
    cout << "Enter the size of array: " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int count = 0; // denotes that the element is same or not
    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        while (j < n)
        {
            if (arr[i] == arr[j])
            {
                count += 1;
            }
            j++;
        }
        
    }
    cout << count;

    return 0;
}                                                           

