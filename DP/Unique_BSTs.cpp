// problem link: https://leetcode.com/problems/unique-binary-search-trees/description/
class Solution {
private:
    int solveRec(int n){
        if(n<=1)
        return 1;

        int ans=0;

        // think i as root node
        for(int i=1;i<=n;i++)
           ans +=solveRec(i-1)*solveRec(n-i);

        return ans; 
    }

    int solveMem(int n, vector<int>& dp){
        if(n<=1)
        return 1;
        
        // check if answer already exists
        if(dp[n]!=-1)
        return dp[n];

        int ans=0;

        // think i as root node
        for(int i=1;i<=n;i++)
           ans +=solveMem(i-1,dp)*solveMem(n-i,dp);

        dp[n]= ans;
        return dp[n]; 
    }
public:
    int numTrees(int n) {
        // return solveRec(n);
        vector<int> dp(n+1,-1);
        return solveMem(n,dp);
    }
};
