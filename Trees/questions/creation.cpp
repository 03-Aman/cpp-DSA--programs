#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *right;
    node *left;
    node(int d)
    {
        this->data = d;
        this->right = NULL;
        this->left = NULL;
    }
};

node *create_tree(node *&root)
{
    cout << "Enter the data: ";
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
        return NULL;
    cout << "Enter the data you wish to insert in to the LEFT of the " << data << endl;
    root->left = create_tree(root->left);
    cout << "Enter the data you wish to insert in to the RIGHT of the " << data << endl;
    root->right = create_tree(root->right);
    return root;
}

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

void levelOrder(node *root)
{
    queue<node *> q;
    q.push(root);
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
}

// int main()
// {
//     node *root = NULL;
//     create_tree(root);
//     cout << "Level order traversal of the tree is: ";
//     levelOrder(root);
//     cout << endl;
//     return 0;
// }
