// problem link: https://leetcode.com/problems/partition-equal-subset-sum/description/
class Solution {
private:
    bool solveRec(int index, int n, vector<int>& nums, int target){
          if(index>=n)
         return false;

         if(target<0)
         return false;

         if(target==0)
         return true;

         bool include=solveRec(index+1,n,nums,target-nums[index]);
         bool exclude=solveRec(index+1,n,nums,target);

        return include || exclude;
    }

    bool solveMem(int index, int n, vector<int>& nums, int target,vector<vector<int>>& dp){
         if(index>=n)
         return false;

         if(target<0)
         return false;

         if(target==0)
         return true;

         // check if answer already exists
         if(dp[index][target]!=-1)
         return dp[index][target];

         bool include=solveMem(index+1,n,nums,target-nums[index],dp);
         bool exclude=solveMem(index+1,n,nums,target,dp);

        dp[index][target]= include || exclude;
        return dp[index][target];
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto i:nums)
        sum+=i;

        if(sum%2!=0)   // if the total sum is odd ,then it can't be divided in to two halves
        return false;

        // Recursion 
        // return solveRec(0,nums.size(),nums,sum/2);

        // Recursion + Memoization 
        int target=sum/2;
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        return solveMem(0,nums.size(),nums,target,dp);
    }
};
