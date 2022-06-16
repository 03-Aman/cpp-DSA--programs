
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char s1[100];
    cout << "Enter the string: ";
    cin.getline(s1, 100);
    int len1 = strlen(s1);
    char s2[100];
    int j = 0;
    for (int i = 0; i < len1; i++)
    {
        if (s1[i] == ' ')
        {
            continue;
        }
        else
        {
            s2[j] = s1[i];
            s2[j+1]='\0';
            j++;
        }
    }
    cout << s2;

    return 0;
}