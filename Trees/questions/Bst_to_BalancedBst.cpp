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
//problem link:https://leetcode.com/problems/balance-a-binary-search-tree/submissions/
class Solution {
    private: 
    void inorder(TreeNode* root, vector<int> &in){
        if(root==NULL)
            return;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
   TreeNode* createBst(TreeNode* root, vector<int> in,int start,int end){
       if(start>end)
           return NULL;
       int mid=(start+end)/2;
       root=new TreeNode(in[mid]);
       root->left=createBst(root->left,in,start,mid-1);
       root->right=createBst(root->right,in,mid+1,end);
       return root;
   }
public:
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<int> inorderVal;
         inorder(root,inorderVal);
      
       
        int start=0,end=inorderVal.size()-1;
        
      
        return createBst(root,inorderVal,start,end);
    }
};
