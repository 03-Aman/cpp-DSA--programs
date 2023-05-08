// problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
class Solution {
private:
    int solveRec(int index,vector<int>& prices,int buy){
        if(index==prices.size())
        return 0;
        int profit=0;
        if(buy){
            int buyKro= -prices[index]+solveRec(index+1,prices,0);
            int skipKro= 0+solveRec(index+1,prices,1);
            profit=max(buyKro,skipKro);
        }
        else
        {
            int sellKro= prices[index]+solveRec(index+1,prices,1);
            int skipKro=0+solveRec(index+1,prices,0);
            profit=max(sellKro,skipKro);
        }
        return profit;
        
    }

    int solveMem(int index,vector<int>& prices,int buy,vector<vector<int>>& dp){
        if(index==prices.size())
        return 0;

        if(dp[index][buy]!=-1)
        return dp[index][buy];
        int profit=0;
        if(buy){
            int buyKro= -prices[index]+solveMem(index+1,prices,0,dp);
            int skipKro= 0+solveMem(index+1,prices,1,dp);
            profit=max(buyKro,skipKro);
        }
        else
        {
            int sellKro= prices[index]+solveMem(index+1,prices,1,dp);
            int skipKro=0+solveMem(index+1,prices,0,dp);
            profit=max(sellKro,skipKro);
        }
        return dp[index][buy]=profit;
        
    }
public:
    int maxProfit(vector<int>& prices) {
        // return solveRec(0,prices,1);
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solveMem(0,prices,1,dp);
    }
};
