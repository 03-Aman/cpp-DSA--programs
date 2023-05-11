// problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
class Solution {
private:
   int solveRec(int index, vector<int>& prices, int buy, int k){
       if(index==prices.size() || k==0)
       return 0;
       
       int profit=0;
       if(buy){
           int buyit=-prices[index]+solveRec(index+1,prices,0,k);
           int skipit=solveRec(index+1,prices,1,k);
           profit=max(buyit,skipit);
       }
       else{
           int sellit=prices[index]+solveRec(index+1,prices,1,k-1);
           int skipit=solveRec(index+1,prices,0,k);
           profit=max(sellit,skipit);
       }
       return profit;
   }

   int solveMem(int index, vector<int>& prices, int buy, int k, vector<vector<vector<int>>>& dp){
       if(index==prices.size() || k==0)
       return 0;

       if(dp[index][buy][k]!=-1)
       return dp[index][buy][k];
       
       int profit=0;
       if(buy){
           int buyit=-prices[index]+solveMem(index+1,prices,0,k,dp);
           int skipit=solveMem(index+1,prices,1,k,dp);
           profit=max(buyit,skipit);
       }
       else{
           int sellit=prices[index]+solveMem(index+1,prices,1,k-1,dp);
           int skipit=solveMem(index+1,prices,0,k,dp);
           profit=max(sellit,skipit);
       }
       return dp[index][buy][k]=profit;
   }

public:
    int maxProfit(int k, vector<int>& prices) {
        // return solveRec(0,prices,1,k);
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solveMem(0,prices,1,k,dp);
    }
};
