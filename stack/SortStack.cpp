#include <bits/stdc++.h>
using namespace std;
void sortedInsert(stack<int> &st, int n)
{
    if (st.empty() || st.top() < n)
    {
        st.push(n);
        return;
    }
    int num = st.top();
    st.pop();
    sortedInsert(st, n);
    st.push(num);
}
void sort(stack<int> &st)
{
    // Base case
    if (st.empty())
        return;
    int n = st.top();
    st.pop();

    // Recursive call
    sort(st);
    sortedInsert(st, n);
}
void display(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
int main()
{
    int size, cnt = 0;
    stack<int> st;
    cout << "Enter the size of the stack: ";
    cin >> size;
    int t = size;
    cout << "Now enter the elements: ";
    while (t--)
    {
        int ele;
        cin >> ele;
        st.push(ele);
    }
    cout << "Initial Stack: ";
    display(st);
    sort(st);
    cout << "Stack after sorting : ";
    display(st);
    return 0;
}