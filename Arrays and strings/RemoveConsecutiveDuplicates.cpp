#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char s1[100], s2[100];
    cout << "Enter the string: ";
    cin >> s1;
    int j = 0;
    for (int i = 0; s1[i] != '\0'; i++)
    {
        if (s1[i] == s1[i + 1])
        {
            continue;
        }
        else
        {
            s2[j] = s1[i];
            s2[j + 1] = '\0';
            j++;
        }
    }
    cout << "The string after removing consecutive duplicates is => " << s2;

    return 0;
}