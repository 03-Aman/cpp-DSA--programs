// problem link: https://leetcode.com/problems/coin-change-ii/description/?envType=study-plan-v2&id=dynamic-programming
class Solution {
private:
    int solveRec(int index, int amount, vector<int>& coins){
         if(amount==0)
            return 1;
        if(index==coins.size())
            return 0;
      
        int include=0;
        if(amount>=coins[index])
        include=solveRec(index,amount-coins[index],coins);
        
        int exclude=solveRec(index+1,amount,coins);

        return include+exclude;
    }

    int solveMem(int index, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(index==coins.size()){
            if(amount==0)
            return 1;
            else
            return 0;
        }

        if(dp[index][amount]!=-1)
        return dp[index][amount];
        
        int include=0;
        if(amount>=coins[index])
        include=solveMem(index,amount-coins[index],coins,dp);
        
        int exclude=solveMem(index+1,amount,coins,dp);

        return dp[index][amount]=include+exclude;
    }

public:
    int change(int amount, vector<int>& coins) {
        // return solveRec(0,amount,coins);
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return solveMem(0,amount,coins,dp);

    }
};
