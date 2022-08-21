#include <iostream>
using namespace std;
class stack
{
public:
    int size;
    int top = -1;
    int *s;
};
void create(stack *st)
{
    cout << "Enter the size of the stack: ";
    cin >> st->size;
    st->s = new int[st->size];
}
void print(stack st)
{
    for (int i = st.top; i >= 0; i--)
        cout << st.s[i] << " ";
    cout << endl;
}
void push(stack *st, int d)
{
    if (st->top == st->size - 1)
        cout << "Stack overflow " << endl;
    else
    {
        st->top++;
        st->s[st->top] = d;
    }
}
int pop(stack *st)
{
    int x = -1;
    if (st->top == -1)
        cout << "Stack underflow" << endl;
    else
    {
        x = st->s[st->top--];
    }
    return x;
}
int peek(stack st, int index)
{
    int x = -1;
    if (st.top - index + 1 < 0)
        cout << "Invalid index " << endl;
    else
    {
        x =st.s[ st.top - index + 1];
    }
    return x;
}
int main()
{
    stack st;
    create(&st);
    push(&st, 10);
    push(&st, 11);
    push(&st, 12);
    push(&st, 13);
    push(&st, 14);
    push(&st, 15);
    print(st);
    // cout<<pop(&st)<<endl;
    // cout<<pop(&st)<<endl;
    // cout<<pop(&st)<<endl;
    cout << peek(st, 7);

}