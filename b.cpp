#include <iostream>
using namespace std;
int *fun(int n)
{
	int *p;
	p = new int[n];
	cout << "Enter the elements of the array: " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	return p;
}
int main()
{
	int *a;
	a = fun(5);
	for (int i = 0; i < 5; i++)
	{
		cout << *a + i << " ";
	}

	return 0;
}