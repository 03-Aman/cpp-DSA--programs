#include <bits/stdc++.h>
#include "creation.cpp"
using namespace std;
void VerticalTraversal(node *root, int hdis, map<int, int> &Hd_Val)
{
    if (root == NULL)
        return;
    Hd_Val[hdis] = root->data; // jo value last aayegi vahi set reahegi ek particular horizontal distance k liye
    VerticalTraversal(root->left, hdis - 1, Hd_Val);
    VerticalTraversal(root->right, hdis + 1, Hd_Val);
}
void BottomView(node *root, map<int, int> Hd_Val)
{

    int hdis = 0;
    VerticalTraversal(root, hdis, Hd_Val);
    cout << "The BOTTOM VIEW of the tree is : ";
    map<int, int>::iterator itr;
    for (itr = Hd_Val.begin(); itr != Hd_Val.end(); itr++)
        cout << (*itr).second << " ";
}

int main()
{
    node *root = NULL;
    create_tree(root); // 1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1
    cout << endl;
    cout << "The level order traversal of the tree is: ";
    levelOrder(root);
    cout << endl;
    map<int, int> Hd_Val;
    BottomView(root, Hd_Val);
    return 0;
}