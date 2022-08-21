#include <bits/stdc++.h>
using namespace std;
int precedence(char m)
{
    if (m == '^')
        return 3;
    else if (m == '*' || m == '/')
        return 2;
    else if (m == '+' || m == '-')
        return 1;
    else
        return -1;
}
void infix_to_postfix(string t)
{
    stack<char> s;
    int l = t.length();
    string ans;
    for (int i = 0; i < l; i++)
    {
        if ((t[i] >= 'a' && t[i] <= 'z') || (t[i] >= 'A' && t[i] <= 'Z'))
            ans += t[i];
        else if (t[i] == '(')
            s.push('(');

        else if (t[i] == ')')
        {
            while (s.top() != '(')
            {
                char c = s.top();
                ans += c;
                s.pop();
            }

            s.pop();
        }
        else
        {
            while (!s.empty()  && precedence(t[i]) <= precedence(s.top()))
            {
                char c = s.top();
                ans += c;
                s.pop();
            }
            s.push(t[i]);
        }
    }

    while (!s.empty())
    {
        char c = s.top();
        ans += c;
        s.pop();
    }

    cout << ans << endl;
}
int main()
{
    string s = "a+b(c*d^e)-g";
    infix_to_postfix(s);
    return 0;
}