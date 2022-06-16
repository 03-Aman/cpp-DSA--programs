#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char s1[100], s2[100];
    cout << "Enter the string: ";
    cin.getline(s1, 100);
    int count = 0, len = strlen(s1);
    for (int i = 0; i <= len; i++)
    {

        if (s1[i] == ' ' || s1[i] == '\0')
        {
            int j = i - 1;
            while (j >= 0 && count < i)
            {
                s2[count] = s1[j];
                s2[count + 1] = ' ';
                count++, j--;
            }
            count = i + 1;
        }
    }

    s2[len] = '\0';
    cout << "The string after reversing each word is: => " << s2;
    return 0;
}