#include <iostream>
using namespace std;
int main()
{
    int n, sE = 0, sO = 0, digit;
    cout << "Enter the number: ";
    cin >> n;
    int remaingNo = n;
    while (remaingNo > 0)
    {
        digit = remaingNo % 10;
        remaingNo = remaingNo / 10;
        if (digit % 2 == 0)
        {
            sE += digit;
        }
        else
        {
            sO += digit;
        }
    }
        cout << sE << " " << sO;

    return 0;
}