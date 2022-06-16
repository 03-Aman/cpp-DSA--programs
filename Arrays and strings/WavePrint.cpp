#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cout << "Enter the number of rows and column respectively: " << endl;
    cin >> n >> m;
    int arr[n][m];
    cout << "Enter the elements of array: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int i = 0, top = 0, bottom = n - 1;
    cout << "The wave print for your array is: " << endl;
    while (i < m) // i<m =>> as we have to print the array column wise(m= no. of columns)
    {
        while (top <= bottom && i < m)
        {
            cout << arr[top][i] << " ";
            top++;
        }
        top = bottom, bottom = 0, i++;
        while (top >= bottom && i < m)
        {
            cout << arr[top][i] << " ";
            top--;
        }
        top = 0, bottom = n - 1, i++;
    }

    return 0;
}