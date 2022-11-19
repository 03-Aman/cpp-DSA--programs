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
// problem link: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/submissions/
class Solution {
    private:
    void inorder(TreeNode* root, vector<int> &in){
        if (!root)
            return ;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    void solve(TreeNode* root,map<int,int> inSum){
        if(!root)
            return;
        root->val=inSum[root->val];
        solve(root->left,inSum);
        solve(root->right,inSum);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> in;
        inorder(root,in);
      map<int,int> inSum; // humne map bnaya to store the greater sum of each element;
        for(int i=0;i<in.size();i++){
            int sum=0;
            for(int j=i;j<in.size();j++)
                sum+=in[j];
            inSum[in[i]]=sum;
        }
        
        
            solve(root,inSum); // kisi bhi traversal se solve krdo (me:preorder);c
 return root;   }
    
};