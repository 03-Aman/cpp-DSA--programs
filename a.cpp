#include <iostream>
using namespace std;
void getmax(int input[], int n)
{
    int max = input[0];
    for (int i = 0; i < n; i++)
    {
        if (input[i] > max)
            max = input[i];
    }
    cout << max;
}
int main()
{
    int input[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    getmax(input, n);
    return 0;
}