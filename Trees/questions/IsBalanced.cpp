#include <bits/stdc++.h>
#include "creation.cpp"
using namespace std;
int height(node *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}
bool isBalanced(node *root)
{
    if (root == NULL)
        return true;
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool ans = abs(height(root->left) - height(root->right)) <= 1;
    if (left && right && ans)
        return true;
    else
        return false;
}
int main()
{
    node *root = NULL;
    create_tree(root);
    cout << "LEVEL ORDER: ";
    levelOrder(root);
    cout << endl;
    if (isBalanced(root))
        cout << "Balanced ";
    else
        cout << "Unbalanced";
    return 0;
}