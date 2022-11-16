/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        bool toright = true;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<int> res(n);
            for (int i = 0; i < n; i++)
            {
                TreeNode *temp = q.front();
                res.push_back(temp->val);
                q.pop();
                if (toright)
                {
                    if (temp->right)
                        q.push(temp->right);
                    if (temp->left)
                        q.push(temp->left);
                }
                else
                {
                    if (temp->left)
                        q.push(temp->left);
                    if (temp->right)
                        q.push(temp->right);
                }
            }
            // next level
            toright = !toright;
            ans.push_back(res);
        }
        return ans;
    }
};