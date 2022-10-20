#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    if (head == NULL)
        head = temp;
    else
    {
        temp->next = head;
        head = temp;
    }
}
void insertAtEnd(Node *&head, int d)
{
    Node *temp = new Node(d);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        Node *p = head;
        while (p->next != NULL)
            p = p->next;
        p->next = temp;
    }
}
void print(Node *p)
{
    for (; p != NULL; p = p->next)
        cout << p->data << " ";
    cout << endl;
}
// int main()
// {
//     Node *head = NULL;
//     insertAtHead(head, 1);
//     insertAtHead(head, 2);
//     insertAtEnd(head, 3);
//     print(head);
//     return 0;
// }