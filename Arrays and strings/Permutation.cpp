#include <iostream>
using namespace std;
int main()
{
    int freq[256] = {0}, count = 0;
    char s1[100], s2[100];
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;

    for (int i = 0; s1[i] != '\0'; i++)
    {
        int index = s1[i];
        freq[index]++;
    }

    for (int i = 0; s2[i] != '\0'; i++)
    {
        int index = s2[i];
        freq[index]--;
    }
    for (int i = 0; i < 256; i++)
    {
        if (freq[i] != 0)
        {
            count--;
        }
    }
    if (count < 0)
    {
        cout << "No.......Both the strings are not permutation of each other !";
    }
    else
    {
        cout << "YES......Both the strings are  permutation of each other !";
    }

    return 0;
}