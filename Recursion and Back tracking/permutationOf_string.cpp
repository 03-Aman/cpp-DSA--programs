#include <bits/stdc++.h>
using namespace std;
void solve(vector<string> &ans, string s, int index)
{
    if (index >= s.length())
    {
        ans.push_back(s); 
        return;
    }
    for (int i = index; i < s.length(); i++)
    {
        swap(s[index], s[i]);
        solve(ans, s, index + 1);
        swap(s[index], s[i]);
    }
}
vector<string> permutation(string s)
{
    vector<string> ans;
    int index = 0;
    solve(ans, s, index);
    return ans;
}
int main()
{
    cout << "Enter the string: ";
    string s;
    cin >> s;
    cout << "The permutation of the string are: ";
    vector<string> ans = permutation(s);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}