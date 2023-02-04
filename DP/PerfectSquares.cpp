// problem link: https://leetcode.com/problems/perfect-squares/description/

class Solution {
    private:
    int solveRec(int n){
        // base case
        if(n==0)
        return 0;

        int ans=n;   // lets say n=1 hai toh 1 ko banane k maximumm ways kitne hai 1 hi
        for(int i=1;i*i<=n;i++){
            ans=min(ans,1+solveRec(n-i*i));
        }

        return ans;
    }

     int solveMem(int n,vector<int>& dp){
        // base case
        if(n==0)
        return 0;

        if(dp[n]!=-1)
        return dp[n];

        int ans=n;   // lets say n=1 hai toh 1 ko banane k maximumm ways kitne hai 1 hi
        for(int i=1;i*i<=n;i++){
            ans=min(ans,1+solveMem(n-i*i,dp));
        }

        dp[n]=ans;
        return dp[n];
    }

public:
    int numSquares(int n) {
        // recursion -->
        //return solveRec(n);

        // recursion + memoization 
        vector<int> dp(n+1,-1);     
        return solveMem(n,dp);
    }
};
