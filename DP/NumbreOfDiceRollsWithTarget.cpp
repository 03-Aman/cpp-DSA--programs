// problem link: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/

class Solution {
private:
    #define MOD 1000000007
    int solveRec(int dices, int faces, int target){
        // base case
        if(target<0)
        return 0;
        if(dices==0 && target!=0)
        return 0;
        if(target==0 && dices!=0)
        return 0;
        if(target==0 && dices==0)
        return 1;

        int ans=0;
        for(int i=1;i<=faces;i++)
            ans=(ans%MOD)+(solveRec(dices-1,faces,target-i))%MOD;

        return ans;
    }

    int solveMem(int dices, int faces, int target,vector<vector<int>>& dp){
        // base case
        if(target<0)
        return 0;
        if(dices==0 && target!=0)
        return 0;
        if(target==0 && dices!=0)
        return 0;
        if(target==0 && dices==0)
        return 1;

        if(dp[dices][target]!=-1)
        return dp[dices][target];

        int ans=0;
        for(int i=1;i<=faces;i++){
            ans=ans + solveMem(dices-1,faces,target-i,dp);
            ans=ans%MOD;
        }
        dp[dices][target]= ans;
        return dp[dices][target];
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        //Recursion
        // return solveRec(n,k,target);

        // Recursion + Memoization
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
         return solveMem(n,k,target,dp);
    }
};
