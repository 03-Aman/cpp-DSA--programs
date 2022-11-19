#include <bits/stdc++.h>
#include "creation.cpp"
using namespace std;
int ValueAt(Node *head, int k)
{
    Node *pTemp = head;
    Node *KthNode = head;
    int cnt = 0;
    for (; cnt < k - 1; cnt++)
        pTemp = pTemp->next;
    while (pTemp->next != NULL)
    {
        KthNode = KthNode->next;
        pTemp = pTemp->next;
    }
    return KthNode->data;
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
    int k;
    cout << "Enter the node number you wish to find from the end : ";
    cin >> k;
    cout << "The value at the " << k << " node from the end is: " << ValueAt(head, k);
    return 0;
}