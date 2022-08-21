#include <bits/stdc++.h>
using namespace std;
int solve_postfix(string s)
{
    stack<int> st;
    int x1, x2;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 48 && s[i] <= 57)
            st.push(s[i] - '0');
        else
        {
            x2 = st.top();
            st.pop();
            x1 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(x1 + x2);
                break;
            case '-':
                st.push(x1 - x2);
                break;
            case '*':
                st.push(x1 * x2);
                break;
            case '/':
                st.push(x1 / x2);
                break;
            }
        }
    }
    return st.top();
}
int main()
{
    string s;
    cout << "Enter the expression: ";
    cin >> s;
    cout << "The answer is : " << solve_postfix(s);
    return 0;
}