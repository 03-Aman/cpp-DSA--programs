// problem link: https://leetcode.com/problems/house-robber/description/
class Solution {
    private:
    int solve(vector<int>& nums,int index,vector<int> &dp){
        if(index<0)
        return 0;
        if(index==0)
        return nums[0];

        if(dp[index]!=-1)
        return dp[index];

        int  include=nums[index]+solve(nums,index-2,dp);
        int exclude=0+solve(nums,index-1,dp);
        dp[index]= max(include,exclude);
        return dp[index];
    }

public:
    int rob(vector<int>& nums) {
        
        vector<int> dp(nums.size()+1,-1);
         return solve(nums,nums.size()-1,dp);
    }
};
