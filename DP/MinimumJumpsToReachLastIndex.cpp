// problem link: https://leetcode.com/problems/jump-game-ii/description/
class Solution {
private:
    long long int solveRec(int curr, int dest, vector<int>& nums){     // long long int --> isliye liya taaki integer overflow na ho
        if(curr>=dest)
        return 0;
        
        long long int ans=INT_MAX;
        for(int i=1;i<=nums[curr];i++)
           ans=min(ans,1+solveRec(curr+i,dest,nums));
        
        return ans;
    }

    long long int solveMem(int curr, int dest, vector<int>& nums,vector<long long int>& dp){
        if(curr>=dest)
        return 0;

        // check if answer already exists
        if(dp[curr]!= -1)
        return dp[curr];


        long long int ans=INT_MAX;
        for(int i=1;i<=nums[curr];i++)
           ans=min(ans,1+solveMem(curr+i,dest,nums,dp));
        
        dp[curr]= ans;
        return dp[curr];
    }
