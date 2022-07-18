#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cout << "Enter the length of the 1st array: ";
    cin >> n;
    int A[n];
    cout << "Enter the elements of 1st array: " << endl;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << "Enter the length of the 2nd array: ";
    cin >> m;
    int B[m];
    cout << "Enter the elements of 2st array: " << endl;
    for (int i = 0; i < m; i++)
        cin >> B[i];
    int C[m + n] = {0};
    int i, k;
    i = k = 0;
    for (; i < n;)
    {
        C[k++] = A[i++];
    }
    int count = 0;
    for (int j = 0; j < m;j++)
    {int flag=1;
        for (int x = 0; x < n; x++)
        {
            if (B[j] == A[x])
                flag =0,count++;
        }
        if (flag)
            C[k++] = B[j];
           
    }

    cout << "The union of the two arrays is-> ";
    for (int l = 0; l < ((m + n) - count); l++)
        cout << C[l] << " ";
    return 0;
}