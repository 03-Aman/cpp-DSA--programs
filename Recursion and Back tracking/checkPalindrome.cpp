#include <bits/stdc++.h>
using namespace std;
bool IsPalindrome(string st, int i, int j)
{
    if (i > j)
        return true;
    if (st[i] != st[j])
        return false;
    return (IsPalindrome(st, i + 1, j - 1));
}
int main()
{
    string st = "amakjjhuhih";
    cout << IsPalindrome(st, 0, st.length() - 1);
    return 0;
}