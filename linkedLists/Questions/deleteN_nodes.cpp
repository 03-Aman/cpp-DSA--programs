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
void delete_N_nodes(node *&head, int m, int n)
{

    node *p = head;
    while (p != NULL)
    {
        int cnt = 1;
        while (cnt < m & p != NULL)
        {
            p = p->next;
            cnt++;
        }
        node *nodeAfterDeletion = p;
        int nodesToDelete = 0;
        while (nodesToDelete < n)
        {
            nodeAfterDeletion = nodeAfterDeletion->next;
            nodesToDelete++;
        }
        if (p != NULL)
            p->next = nodeAfterDeletion->next;
        else
            p = p->next;
    }
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
    int m, n;
    cout << "Enter the values of m and n: ";
    cin >> m >> n;
    delete_N_nodes(head, m, n);
    print(head);

    return 0;
}