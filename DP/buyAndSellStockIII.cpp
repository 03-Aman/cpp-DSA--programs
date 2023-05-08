// problemLink: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
class Solution
{
private:
    int solveRec(int index, int buy, vector<int> &prices, int limit)
    {
        if (index == prices.size() || limit == 0)
            return 0;

        int profit = 0;
        if (buy)
        {
            int buyKro = -prices[index] + solveRec(index + 1, 0, prices, limit); // sirf buy kiya hai toh transaction puri nahi hui twhy no change in limit
            int skipKro = 0 + solveRec(index + 1, 1, prices, limit);
            profit = max(buyKro, skipKro);
        }
        else
        {
            int sellKro = prices[index] + solveRec(index + 1, 1, prices, limit - 1); // agar sell kiya hai toh we have already bought it and the transaction is completed so limit-1
            int skipKro = 0 + solveRec(index + 1, 0, prices, limit);
            profit = max(sellKro, skipKro);
        }
        return profit;
    }

    int solveMem(int index, int buy, vector<int> &prices, int limit, vector<vector<vector<int>>>& dp)
    {
        if (index == prices.size() || limit == 0)
            return 0;

        if (dp[index][buy][limit] != -1)
            return dp[index][buy][limit];
        int profit = 0;
        if (buy)
        {
            int buyKro = -prices[index] + solveMem(index + 1, 0, prices, limit, dp); // sirf buy kiya hai toh transaction puri nahi hui twhy no change in limit
            int skipKro = 0 + solveMem(index + 1, 1, prices, limit, dp);
            profit = max(buyKro, skipKro);
        }
        else
        {
            int sellKro = prices[index] + solveMem(index + 1, 1, prices, limit - 1, dp); // agar sell kiya hai toh we have already bought it and the transaction is completed so limit-1
            int skipKro = 0 + solveMem(index + 1, 0, prices, limit, dp);
            profit = max(sellKro, skipKro);
        }
        return dp[index][buy][limit] = profit;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        // return solveRec(0,1,prices,2); // limit 2 --> hum atmost 2 transaction hi krr skte hai
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2,vector<int>(3,-1)));
        return solveMem(0, 1, prices, 2, dp);
    }
};
