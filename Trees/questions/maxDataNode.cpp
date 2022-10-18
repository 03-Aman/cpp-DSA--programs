#include <bits/stdc++.h>
#include "creation.cpp"
using namespace std;
int Maximum(node *root)
{
    if (root == NULL)
        return -1;
    int x = Maximum(root->left);
    int y = Maximum(root->right);
    return max(max(x, y), root->data);
}
int main()
{
    node *root;
    create_tree(root);
    cout << "The level order traversal of the tree is: ";
    levelOrder(root);
    cout << endl;
    cout << "The Maximum data of the node is :  " << Maximum(root);
    return 0;
}
