#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    //cout << "n";
    cin >> n;
    int arr[n];
    //cout << "arr" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int boast = 0;
    for (int i = 0; i < n; i++)
    {
        int marks_i = arr[i];
        int min = 0, max = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] > marks_i &&j!=i)
                max++;
            else if (arr[j]<=marks_i&&j!=i)
                min++;
        }
        if (min > max)
            boast++;
    }
    cout << boast << endl;

    return 0;
}