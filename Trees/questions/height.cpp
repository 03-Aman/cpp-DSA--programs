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
        this->left = NULL;
        this->right = NULL;
    }
};

node *create_tree(node *&root)
{
    cout << "Enter the  data: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
        return NULL;
    cout << "Enter the value you wish to insert in to the LEFT of " << data << endl;
    root->left = create_tree(root->left);
    cout << "Enter the value you wish to insert in to the RIGHT of " << data << endl;
    root->right = create_tree(root->right);
    return root;
}
void inOrder(node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
int height(node *Node)
{
    if (Node == NULL)
        return 0;
    int left = height(Node->left);
    int right = height(Node->right);
    return max(left, right) + 1;
}

int main()
{
    node *root = NULL;
    create_tree(root); //   5 3 2 -1 -1 -1 4 -1 6 -1 -1
    cout << "The INORDER traversal of the tree is: ";
    inOrder(root);
    cout<<endl; 
    cout << "The height of the tree is : " << height(root);
    return 0;
}