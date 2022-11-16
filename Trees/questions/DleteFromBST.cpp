#include <bits/stdc++.h>
#include "creation.cpp"
using namespace std;
int minimum(node *root)
{
    node *p = root;
    while (p->left != NULL)
        p = p->left;
    int ans = p->data;
    return ans;
}

node *DeleteFromBST(node *root, int key)
{
    // base case
    if (root == NULL)
        return root;
    if (root->data == key)
    { // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child == left child
        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        // 1 child == right child
        if (root->right != NULL && root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minimum(root->right);
            root->data = mini;
            root->right = DeleteFromBST(root->right, mini);
            return root;
        }
    }
    else if (key < root->data)
    {
        root->left = DeleteFromBST(root->left, key);
        return root;
    }
    else
    {
        root->right = DeleteFromBST(root->right, key);

        return root;
    }
}
void inorder(node *root)
{
    if (root == NULL)
        return; 
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    node *root = NULL;
    cout << "Enter the value you wish to insert in the binary search tree and enter -99 to to stop inserting : ";
    int ele;
    cin >> ele;
    while (ele != -99)
    {
        root = insert(root, ele);
        cin >> ele;
    }

    cout << "The level order traversal of the tree is : ";
    levelOrder(root);
    cout << "Enter the node value you wish to delete from the tree: ";
    int key;
    cin >> key;
    DeleteFromBST(root, key);
    cout << "The level order traversal of the tree after deletion is: ";
    inorder(root);

    return 0;
}