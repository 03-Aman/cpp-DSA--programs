#include <bits/stdc++.h>
#include "creation.cpp"
using namespace std;
int count(node *root)
{
    if (root == NULL)
        return 0;
    int x = count(root->left);
    int y = count(root->right);
    if (root->left == NULL && root->right == NULL)
        return x + y + 1;
    else
        return x + y;
}
int main()
{
    node *root;
    create_tree(root);
    cout << "The level order traversal of the tree is: ";
    levelOrder(root);
    cout << endl;
    cout << "The number of the LEAF NODES in tree is :  " << count(root);
    return 0;
}
