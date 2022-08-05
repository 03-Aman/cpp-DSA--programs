#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void insertAtHead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}
void insertAtTail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}
void insertAtPosition(node *&head, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }
    else
    {
        node *temp = head;
        int cnt = 1;
        while (cnt < position - 1)
        {
            temp = temp->next;
            cnt++;
        }
        node *nodetoInsert = new node(d);
        nodetoInsert->next = temp->next;
        temp->next = nodetoInsert;
    }
}
void print(node *&head)
{
    node *p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int main()
{
    node *n = new node(10);
    node *head = n;
    node *tail = n;
    print(head);
    insertAtHead(head, 12);
    print(head);
    insertAtTail(tail, 15);
    print(head);
    insertAtPosition(head, 4, 13);
    print(head);
    return 0;
}