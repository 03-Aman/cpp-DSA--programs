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
// void append(node *&last, int d)
// {
//     node *temp = new node(d);
//     last->next = temp;
//     last = temp;
// }
void insertAtPos(node *&head, int pos, int d)
{
    node *p = head;
    if (pos == 1)
        insertAtHead(head, d);
    else
    {
        int count = 1;
        while (p != NULL && count < pos - 1)
        {
            p = p->next;
            count++;
        }
        node *temp = new node(d);
        temp->next = p->next;
        p->next = temp;
    }
}
void del(node *&head, int pos)
{
    node *p = head;
    // deleting first node
    if (pos == 1)
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }

    else
    { // deleting middle node
        node *curr = head;
        node *prev = NULL;
        int count = 1;
        while (count < pos)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        delete curr;
    }
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

    // append(last, 12);
    insertAtPos(head, 3, 100);
    print(head);
    del(head, 4);
    print(head);

    return 0;
}