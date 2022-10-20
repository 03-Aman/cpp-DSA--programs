#include <bits/stdc++.h>
#include "creation.cpp"
using namespace std;
bool IfLoop(Node *head)
{
    if (head == NULL || head->next == NULL)
        return false;
    else
    {
        Node *slow = head;
        Node *fast = head;
        while (slow != NULL && fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
}
int main()
{
    Node *head = NULL;
    cout << "Enter the elements you wish to enter in the Linked list and enter -99 to terminate : ";
    int ele;
    cin >> ele;
    while (ele != -99)
    {
        insertAtEnd(head, ele);
        cin >> ele;
    }
    cout << "Linked list is: ";
    print(head);
    head->next->next->next->next = head;
    if (IfLoop(head))
        cout << "Loop";
    else
        cout << "No loop";

    return 0;
}