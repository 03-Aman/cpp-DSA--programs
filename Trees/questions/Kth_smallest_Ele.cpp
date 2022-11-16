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
//problem: link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/
// Input: root = [3,1,4,null,2], k = 1
// Output: 1
// Input: root = [5,3,6,2,4,null,null,1], k = 3
// Output: 3

class Solution {
    private: 
    void inorder( TreeNode* root,vector<int> &ans){
        if(root==NULL)
            return ;
        inorder(root->left,ans);
         ans.push_back(root->val);
        inorder(root->right,ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root,ans);
        return ans[k-1];
    }
};