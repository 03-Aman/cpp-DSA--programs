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
        this->next = NULL;
    }
};
void insertAtHead(node *&head, int d)
{
    if (head == NULL)
    {
        node *temp = new node(d);
        head = temp;
    }
    else
    {
        node *temp = new node(d);
        temp->next = head;
        head = temp;
    }
}
node *reverseK(node *&head, int k)
{
    if (head == NULL)
        return NULL;
    node *prev = NULL;
    node *nxt = NULL;
    node *curr = head;
    int count = 0;
    while (curr != NULL && count < k)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        count++;
    }
    if (nxt != NULL)
    {
        head->next = reverseK(nxt, k);
    }

    return prev;
}
void print(node *head)
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
    node *head = NULL;
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 6);
    //insertAtHead(head, 5);
    print(head);
    int k = 3;
    head = reverseK(head, k);
    print(head);
    return 0;
}