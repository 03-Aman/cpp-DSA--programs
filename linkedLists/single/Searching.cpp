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
// Printing linked list
void print(node *p)
{

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
// linear search in a linked list
void linearSearch(node *p, int ele)
{
    int count = 0;
    bool flag = true;
    while (p != NULL)
    {
        count++;
        if (p->data == ele)
        {
            cout << ele << " is present at " << count << " position in the list ";
            flag = false;
            break;
        }
        p = p->next;
    }
    if (flag)
        cout << ele << " is not present in the list";
}

int main()
{
    int arr[5] = {1, 2, 5, 3, 6};
    node *first = new node(arr[0]); // creating the first node and setting it's data to 0th element of the array.
    create(first, arr, 5);
    cout << "Linked list is: ";
    print(first);
    linearSearch(first, 12);
    return 0;
}