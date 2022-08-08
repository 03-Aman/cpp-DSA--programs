#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *prev;
    node *next;
    node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};
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
int getlength(node *head)
{
    int len = 0;
    node *p = head;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}
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
        head->prev = temp;
        head = temp;
    }
}
void insertAtPos(node *&head, int pos, int d)
{
    if (pos == 1)
        insertAtHead(head, d);
    else
    {
        node *temp = new node(d);
        node *p = head;
        int count = 1;
        while (count < pos - 1)
        {
            p = p->next;
            count++;
        }
        temp->next = p->next;
        temp->prev = p;
        p->next = temp;
    }
}
void del(node *&head, int pos)
{
    // deleting the first node
    if (pos == 1)
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        node *prevPtr = NULL; // pointer to the previous node
        node *currPtr = head; // pointer to the next node
        int count = 1;
        while (count < pos)
        {
            prevPtr = currPtr;
            currPtr = currPtr->next;
            count++;
        }
        currPtr->prev=NULL; // ye jaroori ni hai karana 
        prevPtr->next = currPtr->next;
        currPtr->next=NULL;
        delete currPtr;
    }
}

int main()
{

    node *head = NULL;
    ;

    // cout << getlength(head)<<endl;
    insertAtHead(head, 11);

    print(head);
    insertAtPos(head, 1, 12);
    insertAtHead(head, 13);
    insertAtHead(head, 14);
    print(head);
    del(head, 2);
    print(head);
    return 0;
}