#include <bits/stdc++.h>
#include "creation.cpp"
using namespace std;
bool Isidentical(node *r1, node *r2)
{
    if (r1 == NULL && r2 == NULL)
        return true;
    if (r1 == NULL && r2 != NULL)
        return false;
    if (r2 == NULL && r1 != NULL)
        return false;
    bool left = Isidentical(r1->left, r2->left);
    bool right = Isidentical(r1->right, r2->right);
    bool val = r1->data == r2->data;
    if (left && right && val)
        return true;
    else
        return false;
}
int main()
{
    node *root1 = NULL;
    node *root2 = NULL;
    cout << "Enter the data in tree 1: ";
    create_tree(root1);
    levelOrder(root1);
    cout << endl;
    cout << "Enter the data in tree 2: ";
    create_tree(root2);
    levelOrder(root2);
    cout << endl;
    if (Isidentical(root1, root2))
        cout << "Identical ";
    else
        cout << "Not identical";
    return 0;
}