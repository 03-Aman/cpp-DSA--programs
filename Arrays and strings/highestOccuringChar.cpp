#include <iostream>
using namespace std;
int main()
{
    char s[256];
    cout << "Enter the string: ";
    cin >> s;
    int freq[256] = {0}, maxFreq = 0, maxIndex;
    for (int i = 0; s[i] != '\0'; i++)
    {
        int index = s[i];
        freq[index]++;
    }
    for (int i = 0; i < 256; i++)
    {
        if (freq[i] > maxFreq)
        {
            maxFreq = freq[i];
            maxIndex = i;
        }
    }
    cout << "The highest occuring character is => '" << char(maxIndex) << "' and it is occuring " << maxFreq << " times";

    return 0;
}