#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
class stack
{
    node *top;

public:
    stack()
    {
        top = NULL;
    }
    void push(int d);
    void pop();
    void print();
};
void stack::push(int d)
{
    node *t = new node;
    if (t == NULL)
        cout << "Stack is full" << endl;
    else
    {
        t->data = d;
        t->next = top;
        top = t;
    }
}
void stack::pop()
{

    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << top->data << endl;
        node *t = top;
        top = top->next;
        delete t;
    }
}
void stack::print()
{
    while (top != NULL)
    {
        cout << top->data << " ";
        top = top->next;
    }
    cout << endl;
}
int main()
{
    stack st;
    st.push(3);
    st.push(2);
    st.push(1);
    st.pop();
    // st.print();
    st.pop();
    st.pop();
    st.pop();
    
    return 0;
}