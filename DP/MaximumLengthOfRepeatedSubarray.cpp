// problem link: https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
class Solution {
int ans=0;
private:
    int solveRec(int in1, int in2, int &n, int &m, vector<int>& nums1, vector<int>& nums2){
        if(in1>=n || in2>=m)
        return 0;
        int val=0;
        if(nums1[in1]==nums2[in2]){
        val=1+solveRec(in1+1,in2+1,n,m,nums1,nums2);
        }

        ans=max(ans,val);
        
        solveRec(in1+1,in2,n,m,nums1,nums2); // nums1 ka element skip kiya
        solveRec(in1,in2+1,n,m,nums1,nums2); // nums2 ka element skip kiya
        
        
        return val;
    }

    int solveMem(int in1, int in2, int &n, int &m, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp){
        if(in1>=n || in2>=m)
        return 0;

        if(dp[in1][in2]!=-1)
        return dp[in1][in2];
        
        int val=0;
        if(nums1[in1]==nums2[in2]){
        val=1+solveMem(in1+1,in2+1,n,m,nums1,nums2,dp);
        }

        ans=max(ans,val);

        solveMem(in1+1,in2,n,m,nums1,nums2,dp); // nums1 ka element skip kiya
        solveMem(in1,in2+1,n,m,nums1,nums2,dp); // nums2 ka element skip kiya
        
        
        return dp[in1][in2]=val;
    }
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        // solveRec(0,0,n,m,nums1,nums2);
        vector<vector<int>> dp(n,vector<int>(m,-1));
        solveMem(0,0,n,m,nums1,nums2,dp);
        return ans;
    }
};
