// https://leetcode.com/problems/house-robber-iii/description/

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
class Solution {
private:
unordered_map<TreeNode*,int> dp;
   int solve(TreeNode* root){
       if(!root)
       return 0;
       
       if(dp.count(root))
       return dp[root];

       int take=root->val;
       if(root->left)
       take+=solve(root->left->left)+solve(root->left->right);
       if(root->right)
       take+=solve(root->right->left)+solve(root->right->right);

       int notTake=solve(root->left)+solve(root->right);

       return dp[root]=max(take,notTake);
   }
public:
    int rob(TreeNode* root) {
        return solve(root);
    }
};
