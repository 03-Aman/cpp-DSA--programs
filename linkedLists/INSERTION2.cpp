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
        next = NULL;
    }
};
void create(node *first, int *arr, int n)
{
    node *t, *last;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new node(arr[i]);
        last->next = t;
        last = t;
    }
}
void max(node *p)
{
    int ma = INT_MIN;
    while (p != NULL)
    {
        if (p->data > ma)
            ma = p->data;
        p = p->next;
    }
    cout << "The maximum element is :" << ma << endl;
}
void min(node *p)
{
    int mi = INT_MAX;
    while (p != NULL)
    {
        if (p->data < mi)
            mi = p->data;
        p = p->next;
    }
    cout << "The minimum element is: " << mi << endl;
}
void insertAtPos(node **first, int pos, int d)
{
    node *t = new node(d);
    node *temp = first;
    node *p = first;
    if (pos == 0)
    {
        t->next = first;
        temp = t;
    }
    else
    {
        for (int i = 1; i <= pos - 1 && p; i++)
            p = p->next;
        if (p)
        {
            t->next = p->next;
            p->next = t;
        }
    }
}
void print(node *p)
{

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
void search(node *p, int ele)
{
    bool flag = true;
    int count = 0;
    while (p != NULL)
    {
        count++;
        if (p->data == ele)
        {
            flag = false;
            cout << ele << " is present at position " << count << endl;
            break;
        }
        p = p->next;
    }
    if (flag)
        cout << "The given element is not present in the list!" << endl;
}
int main()
{
    int arr[5] = {1, 2, 5, 3, 6};
    node *first = new node(arr[0]); // creating the first node and setting it's data to 0th element of the array.
    create(first, arr, 5);
    cout << "Linked list is: ";
    print(first);
    cout << "List after insertion is: ";
    insertAtPos(&first, 0, 13);
    print(first);
    // search(first, 5);
    return 0;
}