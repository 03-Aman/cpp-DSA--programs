// problem link:https://leetcode.com/problems/longest-increasing-subsequence/description/
class Solution {
private:
    int solveRec(vector<int>& nums, int prev, int curr,int& n){
        if(curr==n)
        return 0;
        
        // including currrent element 
        int include=0;
        if(prev==-1 || nums[prev]<nums[curr])
        include=1+solveRec(nums,curr,curr+1,n);

        // excude
        int exclude=solveRec(nums,prev,curr+1,n);

        return max(include,exclude);
    }

    int solveMem(vector<int>& nums, int prev, int curr,int& n,vector<vector<int>>& dp){
        if(curr==n)
        return 0;

        //check if answer already exists
        if(dp[curr][prev+1]!=-1)
            return dp[curr][prev+1];    // prev+1---->bcoz prev=-1 it will give error as there is no -ve indexing in vector
       
        
        // including currrent element 
        int include=0;
        if(prev==-1 || nums[prev]<nums[curr])
        include=1+solveMem(nums,curr,curr+1,n,dp);

        // excude
        int exclude=solveMem(nums,prev,curr+1,n,dp);

        dp[curr][prev+1]= max(include,exclude);
        return dp[curr][prev+1];
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // Recursion
        //return solveRec(nums,-1,0,n);
        
        //Recursion+Memoization
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solveMem(nums,-1,0,n,dp);
    }
};
