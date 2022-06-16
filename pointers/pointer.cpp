#include <iostream>
using namespace std;
int main()
{
    int a, b, *i1 = &a, *i2 = &b;
    string x, y, *s1 = &x, *s2 = &y;
    float p, *f = &p;
    cout << "Enter two integers: " << endl;
    cin >> a;
    cin >> b;
    cout << "the address of intergers are: " << i1 << " " << i2 << endl;
    cout << "the values of intergers are: " << *i1 << " " << *i2 << endl;

    cout << "Enter two strings: " << endl;
    cin >> x;
    cin >> y;
    cout << "the address of intergers are: " << s1 << " " << s2 << endl;
    cout << "the values of intergers are: " << *s1 << " " << *s2 << endl;
    cout << "Enter the value of float: " << endl;
    cin >> p;
    cout << "The address of float is: " << f << endl;
    cout << "The value of float is: " << *f << endl;

    return 0;
}