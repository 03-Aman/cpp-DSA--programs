#include <bits/stdc++.h>
using namespace std;
int required_Reversal(string s)
{
    stack<char> st;
    if (s.length() % 2 != 0)
        return -1;
    else
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '[') // if s[i] is a open brace
                st.push(s[i]);
            // if s[i] is a closed brace
            else
            {
                if (!st.empty() && st.top() == '[')
                    st.pop();
                else
                    st.push(s[i]);
            }
        }
        int closed = 0, open = 0;
        while (!st.empty())
        {
            if (st.top() == '[')
                open++;
            else
                closed++;
            st.pop();
        }

        return (open + 1) / 2 + (closed + 1) / 2;
    }
}
int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;
    cout << required_Reversal(s);
    return 0;
}