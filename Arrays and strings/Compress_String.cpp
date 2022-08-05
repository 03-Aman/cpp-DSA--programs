#include <iostream>
using namespace std;
int main()
{
    string s, compressStr = "";
    cout << "Enter the string: ";      
    cin >> s;
    cout << s.length();
    int StartIn = 0, EndIn = 0;
    while (StartIn < s.length())
    {
        while (EndIn < s.length() && (s[EndIn] == s[StartIn]))
        {
            EndIn += 1;
        }
        int totalCount = EndIn - StartIn;
        if (totalCount != 1)
        {
            compressStr += s[StartIn];
            compressStr += char(totalCount + '0');
        }
        else
        {
            compressStr += s[StartIn];
        }
        StartIn = EndIn;
    }
    cout << "The compressed string is : => '" << compressStr << "'";
    return 0;
}