#include <bits/stdc++.h>
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
    node *temp = new node(d);
    if (head == NULL)
        head = temp;
    else
    {
        temp->next = head;
        head = temp;
    }
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
void EvenOdd(node *&head)
{
    node *odd = head;
    node *even = odd->next;
    node *evenStart = even; // pointer to store the starting even node taki hum baad m ise last odd node se link kr ske
    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenStart;
}
int main()
{
    node *head = NULL;
    cout << "Now enter the elements in the list and press -1 to terminate: ";
    int ele;
    cin >> ele;
    while (ele != -1)
    {

        insertAtHead(head, ele);
        cin >> ele;
    }
    print(head);
    EvenOdd(head);
    print(head);
    return 0;
}