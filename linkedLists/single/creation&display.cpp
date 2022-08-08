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
void print(node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
int main()
{
    int arr[5] = {1, 2, 5, 3, 6};
    node *first = new node(arr[0]); // creating the first node and setting it's data to 0th element of the array.
    create(first, arr, 5);
    cout << "Linked list is: ";
    print(first);
    return 0;
}