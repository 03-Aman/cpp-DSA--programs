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
void inOrder(node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void preOrder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    node *root = NULL;
    create_tree(root);
    cout << "Level order traversal of the tree is: ";
    levelOrder(root);
    cout << endl;
    cout << "The INORDER traversal of the tree is: ";
    inOrder(root);
    cout << endl;
    cout << "The PREORDER traversal of the tree is: ";
    preOrder(root);
    cout << endl;
    cout << "The POSTORDER traversal of the tree is: ";
    postOrder(root);
    return 0;
}
