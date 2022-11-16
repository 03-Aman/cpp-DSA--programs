#include <bits/stdc++.h>
using namespace std;
// problem link: https://leetcode.com/problems/longest-valid-parentheses/
int LongestLength(string s)
{
   int n = s.length();
        stack <int> st;// stack to store problematic indexes
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(') st.push(i);
            else
            {
                if(!st.empty() && s[st.top()]=='(')
                {
                    st.pop();ans= max(ans, st.empty() ? i+1 : i-st.top());
                }
                else st.push(i);
            }
        }
        return ans;
}
int main()
{
    string s = "(()";
    cout << "The length of the longest valid parenthesis: " << LongestLength(s);

    return 0;
}