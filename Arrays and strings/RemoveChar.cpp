#include <iostream>
using namespace std;
int main()
{
    char s1[100], s2[100], x;
    cout << "Enter the string : ";
    cin >> s1;
    cout << "Enter the character that you wish to remove from the entered string: ";
    cin >> x;
    int j = 0;
    for (int i = 0; s1[i] != '\0'; i++)
    {
        if (s1[i] == x)
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
    cout << "The string after removing '" << x << "' from it is => " << s2;
    return 0;
}