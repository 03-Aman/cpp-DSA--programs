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
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}
void disp(node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
node *reverse(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *secondEle = head->next;
    head->next = NULL;
    node *ReverseRest = reverse(secondEle);
    secondEle->next = head; 
    return ReverseRest;
}
int main()
{
    node *head = NULL;
    cout << "Start entering the elements in the list and press -99 to terminate: ";
    int ele;
    cin >> ele;
    while (ele != -99)
    {
        insertAtHead(head, ele);
        cin >> ele;
    }
    cout << "The Linled list is: ";
    disp(head);
    cout << "The Reversed Linked list is: ";
    head = reverse(head);
    disp(head);

    return 0;
}