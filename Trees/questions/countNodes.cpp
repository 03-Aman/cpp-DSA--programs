#include <bits/stdc++.h>
#include "creation.cpp"
using namespace std;
int count_nodes(node *root)
{
    if (root == NULL)
        return 0;
    int x = count_nodes(root->left); //counting the left nodes
    int y = count_nodes(root->right);// counting the right nodes
    return x + y + 1;
}

int main()
{
    node *root = NULL;
    create_tree(root);
    cout<<"The level order traversal of the tree is: ";
    levelOrder(root);
    cout << endl;
    cout << "The total nodes in tree is/are: " << count_nodes(root);

    return 0;
}