#include <bits/stdc++.h>
using namespace std;
void reverse_st(string &st, int i, int j)
{
    if (i > j)
        return;
    swap(st[i], st[j]);
    reverse_st(st, i + 1, j - 1);
}
int main()
{
    string st = "Aman";
    reverse_st(st, 0, st.length() - 1);
    cout << st;

    return 0;
}