#include <bits/stdc++.h>
#include "creation.cpp"
using namespace std;
void solve(node *root, int len, int &maxlen, int sum, int &maxSum)
{
    if (root == NULL)
    {
        if (len > maxlen)
        {
            maxlen = len;
            maxSum = sum;
        }
        else if (len == maxlen)
        {
            maxSum = max(sum, maxSum);
        }

        return;
    }
    sum += root->data;
    solve(root->left, len + 1, maxlen, sum, maxSum);
    solve(root->right, len + 1, maxlen, sum, maxSum);
}
int SumOfLogPath(node *root)
{
    int len = 0;
    int maxlen = 0;
    int sum = 0;
    int maxSum = INT_MIN;
    solve(root, len, maxlen, sum, maxSum);
    return maxSum;
}
int main()
{
    node *root;
    create_tree(root); // 1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1
    cout << "The level order traversal of the tree is: ";
    levelOrder(root);
    cout << endl;
    cout << "BLOOD LINE sum: " << SumOfLogPath(root);
    return 0;
}