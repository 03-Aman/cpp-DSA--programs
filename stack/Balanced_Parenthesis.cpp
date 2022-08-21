#include <bits/stdc++.h>
using namespace std;
bool is_balanced(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        // agar opening bracket aata hai toh
        if (s[i] == '[' || s[i] == '{' || s[i] == '(')
            st.push(s[i]);
        // agar closing bracket aata hai toh
        else
        {
            if (!st.empty())
            {
                if ((s[i] == ']' && st.top() == '[') ||
                    (s[i] == '}' && st.top() == '{') ||
                    (s[i] == ')' && st.top() == '('))
                    st.pop();
                else
                    return false;
            }
            else
                return false;
        }
    }
    if (st.empty())
        return true;
    else
        return false;
}
int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;
    if (is_balanced(s))
        cout << "Balanced";
    else
        cout << "Unbalanced";

    return 0;
}