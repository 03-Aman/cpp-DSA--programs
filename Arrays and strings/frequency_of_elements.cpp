#include <iostream>
using namespace std;
int main()
{
  int n;
  cout << "Enter the length of array: ";
  cin >> n;
  int arr[n];
  int ma = -999;
  cout << "Enter the elements of array: " << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++)
  {
    ma = max(ma, arr[i]);
  }
  int freq_arr[ma+1] = {0};
  for (int i = 0; i < n; i++)
  {
    freq_arr[arr[i]]++;
  }
  cout << "The frequencies of elements of array are=> " << endl;
  for (int i = 0; i < ma + 1; i++)
  {
    if (freq_arr[i] != 0)
    {
      cout << i << " - " << freq_arr[i] << endl;
    }
  }

  return 0;
}