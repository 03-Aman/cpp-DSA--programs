#include <bits/stdc++.h>
#include "creation.cpp"
using namespace std;
bool IsSumTree(node *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    bool left = IsSumTree(root->left);
    bool right = IsSumTree(root->right);
    bool sum = root->left->data + root->right->data == root->data;
    if (left && right && sum)
        return true;
    else
        return false;
}
int main()
{
    node *root = NULL;
    create_tree(root);
    levelOrder(root);
    cout << endl;
    if (IsSumTree(root))
        cout << "Sum tree";
    else
        cout << "Not sum tree";
    return 0;
}