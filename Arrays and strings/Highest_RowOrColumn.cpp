#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cout << "Enter the number of rows and column respectively: ";
    cin >> n >> m;
    int arr[n][m];
    int Rmax = 0, Cmax = 0, Rsum, Csum, Rno, Cno;
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        Rsum = 0;
        for (int j = 0; j < m; j++)
        {
            Rsum += arr[i][j];
        }
        if (Rsum > Rmax)
        {
            Rno = i;
            Rmax = Rsum;
        }
    }
    for (int i = 0; i < m; i++)
    {
        Csum = 0;
        for (int j = 0; j < n; j++)
        {
            Csum += arr[j][i];
        }
        if (Csum > Cmax)
        {
            Cno = i;
            Cmax = Csum;
        }
    }

    if (Rmax > Cmax)
    {
        cout << "Row " << Rmax << " " << Rno;
    }
    else
    {
        cout << "Column " << Cmax << " " << Cno;
    }

    return 0;
}