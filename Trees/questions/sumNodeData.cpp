#include <bits/stdc++.h>
#include "creation.cpp"
using namespace std;
int sum_ofNodes(node *root)
{
    if (root == NULL)
        return 0;
    int x = sum_ofNodes(root->left);
    int y = sum_ofNodes(root->right);
    return x + y + root->data;
}
int main()
{
    node *root;
    create_tree(root);
    cout << "The level order traversal of the tree is: ";
    levelOrder(root);
    cout << endl;
    cout << "The sum of the data of all nodes is: " << sum_ofNodes(root);
    return 0;
}