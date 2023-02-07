// problem link: https://leetcode.com/problems/coin-change/description/
class Solution {
    private:
    int solve(vector<int> &coins,int amt,vector<int> &dp){
        // first step
        if(amt==0)
        return 0;
        if(amt<0)
        return INT_MAX;
        
        // third step -->checking if pehle se hi ans stored hai
      
        if(dp[amt]!=-1)
        return dp[amt];

        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans=solve(coins,amt-coins[i],dp);

            if(ans!=INT_MAX)
            mini=min(mini,1+ans);
        }
        // second step
        dp[amt]=mini;

        return dp[amt];
    }
public:
    int coinChange(vector<int>& coins, int amt) {
        vector<int> dp(amt+1,-1);

        int ans=solve(coins,amt,dp);
        if(ans!=INT_MAX)
        return ans;
        return -1;

    }
};
