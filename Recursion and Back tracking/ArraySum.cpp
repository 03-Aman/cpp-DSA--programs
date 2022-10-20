#include <bits/stdc++.h>
using namespace std;
int arrSum(int arr[], int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return arr[0];
    int sum = arr[0] + arrSum(arr + 1, n - 1);
    return sum;
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 0 };
    cout << arrSum(arr, 5);
    return 0;
}