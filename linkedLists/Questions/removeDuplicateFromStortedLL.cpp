#include <bits/stdc++.h>
#include "creation.cpp"
using namespace std;
/*
input: 1->2->2->3->4->4
output: 1->2->3->4
*/
void solve(Node *&head)
{
    if (!head || !head->next)
        return;
    Node *curr = head;
    Node *nxt;
    while (curr->next)
    {
        if (curr->data == curr->next->data)
        {
            nxt = curr->next;
            while (nxt && curr->data == nxt->data)
                nxt = nxt->next;
            if (!nxt) // matlb list khatm
            {
                curr->next = NULL;
                break;
            }
            else
            {
                curr->next = nxt;
            }
        }
        curr = curr->next;
    }
}

int main()
{
    Node *head = NULL;
    insertAtEnd(head, 1);
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 3);
    print(head);
    solve(head);
    print(head);
    return 0;
}