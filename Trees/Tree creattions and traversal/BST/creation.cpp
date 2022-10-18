#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node *insert(node *&p, int key)
{
    if (p == NULL)
    {
        p = new node(key);
    }
    if (p->data == key)
        return p;
    else if (key < p->data)
        p->left = insert(p->left, key);
    else
        p->right = insert(p->right, key);
    return p;
}
void levelOrder(node *p)
{
    queue<node *> q;
    q.push(p);
    while (!q.empty())
    {
        node *temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    cout<<endl;
}
int main()
{
    node *root = NULL;
    cout << "Enter the value you wish to insert in the binary search tree and enter -99 to to stop inserting : ";
    int ele;
    cin >> ele;
    while (ele != -99)
    {
       root= insert(root, ele);
        cin >> ele;
    }

    cout << "The level order traversal of the tree is : ";
    levelOrder(root);

    return 0;
}