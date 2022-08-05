#include <iostream>
using namespace std;

int main()
{
  int n, m;
  cout << "Enter the dimensions of the array: ";
  cin >> n >> m;
  int arr[n][m];
  cout << "Enter the elements of the array: " << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      cin >> arr[i][j];
  }
  cout << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int rem, rev = 0, num = arr[i][j];
      while (num > 0)
      {
        rem = num % 10;
        rev = rev * 10 + rem;
        num = num / 10;
      }
      arr[i][j] = rev;
    }
  }
  for (int j = 0; j<m ; j++)
  {
    for (int i = n - 1; i >= 0; i--)
      cout << arr[i][j] << " ";
    cout << endl;
  }

  return 0;
}