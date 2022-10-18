#include <bits/stdc++.h>
#include "creation.cpp"
using namespace std;
void verticalTraversal(node *root, int hdis, map<int, vector<int>> &Hd_val)
{
    if (root == NULL)
        return;
    Hd_val[hdis].push_back(root->data);
    verticalTraversal(root->left, hdis - 1, Hd_val);
    verticalTraversal(root->right, hdis + 1, Hd_val);
}

int main()
{
    node *root = NULL;
    create_tree(root); // 1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1
    cout << endl;
    cout << "The level order traversal of the tree is: ";
    levelOrder(root);
    cout << endl;
    map<int, vector<int>> Hd_val; // Hd-> horizontal distance , val= value at that horizontal distance
    int hdis = 0;
    verticalTraversal(root, hdis, Hd_val);
    map<int, vector<int>>::iterator itr;
    cout << "The vertical order travesal of the tree is: ";
    for (itr = Hd_val.begin(); itr != Hd_val.end(); itr++)
    {
        for (int i = 0; i < (itr->second).size(); i++)
        {
            cout << (itr->second)[i] << " ";
        }
        cout << endl;
    }

    return 0;
}