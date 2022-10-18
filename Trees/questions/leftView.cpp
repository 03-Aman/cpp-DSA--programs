#include <bits/stdc++.h>
#include "creation.cpp"
using namespace std;
void solve(node *root, vector<int> &ans, int level)
{
    if (root == NULL)
        return;
    if (level == ans.size()) // we entered in a new leveln
        ans.push_back(root->data);
    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}
void LeftView(node *root)
{
    vector<int> ans;
    solve(root, ans, 0);
    cout << "LEFT VIEW: ";
    for (auto &itr : ans)
        cout << (itr) << " ";
}
int main()
{
    node *root = NULL;
    create_tree(root); // 1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1
    cout << "LEVEL ORDER: ";
    levelOrder(root);
    cout << endl;
    LeftView(root);
    return 0;
}