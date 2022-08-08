#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        this->data = d;
        next = NULL;
    }
};
void insertAtHead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}
void append(node *&last, int d)
{
    node *temp = new node(d);
    last->next = temp;
    last = temp;
}
void print(node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    node *n = new node(1);
    node *head = n;
    node *last = n;
    cout << "enter ";
    int t, d;
    cout << "Enter the number of elements you want to add: ";
    cin >> t;
    while (t)
    {
        cin >> d;
        insertAtHead(head, d);
        t--;
    }
    print(head);
    append(last, 12);
    append(last, 123);
    print(head);
    return 0;
}