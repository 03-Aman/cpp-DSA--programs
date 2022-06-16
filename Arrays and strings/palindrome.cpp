#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char s1[100];
    cout << "Enter the string: ";
    cin >> s1;
    int len = strlen(s1);

    char s2[100];
    int i = len - 1, j = 0;
    while (i >= 0)
    {
        s2[j] = s1[i];
        i--, j++;
    }
    s2[len] = '\0';

    if (strcmp(s2, s1) == 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}