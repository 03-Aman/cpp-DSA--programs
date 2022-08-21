#include <bits/stdc++.h>
using namespace std;
void insert_bottom(stack<int> &st,int x){
    if(st.empty()){
    st.push(x);
    return;}
    int d =st.top();
    st.pop();
    insert_bottom(st,x);
    st.push(d);
}
void disp_stack(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}
int main()
{
stack<int> st;
    int n;
    cout << "Enter the number of element you wish to insert in the stack: ";
    cin >> n;
    cout << "Now enter the elements : ";
    while (n--)
    {
        int ele;
        cin >> ele;
        st.push(ele);
    }
    int x;
    cout << "Enter the element you wish to insert at the bottom: ";
    cin >> x;
    insert_bottom(st, x);
    disp_stack(st);

    return 0;
}