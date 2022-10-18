#include <bits/stdc++.h>
#include "creation.cpp"
using namespace std;
void VerticalTraversal(node *root, int hdis, map<int, vector<int>> &Hd_Val)
{
    if (root == NULL)
        return;
    Hd_Val[hdis].push_back(root->data);
    VerticalTraversal(root->left, hdis - 1, Hd_Val);
    VerticalTraversal(root->right, hdis + 1, Hd_Val);
}
void TopView(node *root, map<int, vector<int>> Hd_Val)
{

    int hdis = 0;
    VerticalTraversal(root, hdis, Hd_Val);
    cout << "The top view of the tree is : ";
    map<int, vector<int>>::iterator itr;
    for (itr = Hd_Val.begin(); itr != Hd_Val.end(); itr++)
        cout << (itr->second)[0] << " ";
}

int main()
{
    node *root = NULL;
    create_tree(root); // 1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1
    cout << "The level order traversal of the tree is: ";
    levelOrder(root);
    cout << endl;
    map<int, vector<int>> Hd_Val;
    // top view k liye jo vertical traversal se vector milega uska bss 1st element print kradenge aur baaki ko ignore krdenge
    TopView(root, Hd_Val);

    return 0;
}