// problem link:https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/
class Solution {
private:
    int solveRec(int start, int end){
        if(start>=end)
          return 0;
        
        int ans=INT_MAX;
        for(int i=start; i<=end; i++)
           ans=min(ans,i+max(solveRec(start,i-1),solveRec(i+1,end)));

        return ans;
    }

    int solveMem(int start, int end, vector<vector<int>>& dp){
        if(start>=end)
          return 0;
        
        // check if answer already exists
        if(dp[start][end]!=-1)
        return dp[start][end];
        int ans=INT_MAX;
        for(int i=start; i<=end; i++)
           ans=min(ans,i+max(solveMem(start,i-1,dp),solveMem(i+1,end,dp)));

        dp[start][end]= ans;
        return ans;
    }
public:
    int getMoneyAmount(int n) {
        // return solveRec(1,n);

        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return solveMem(1,n,dp);
    }
};
