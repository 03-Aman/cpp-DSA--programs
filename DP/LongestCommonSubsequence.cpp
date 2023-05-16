// problem link: https://leetcode.com/problems/longest-common-subsequence/description/
class Solution {
private:
    int solveRec(int i, int j, string &a, string &b){
        if(i==a.length() || j==b.length())
        return 0;

        int ans=0;
        if(a[i]==b[j])
          ans=1+solveRec(i+1,j+1,a,b);
        else
        ans=max(solveRec(i+1,j,a,b),solveRec(i,j+1,a,b));

        return ans;
    }

    int solveMem(int i, int j, string &a, string &b,vector<vector<int>>& dp){
        if(i==a.length() || j==b.length())
        return 0;

        if(dp[i][j]!=-1)
        return dp[i][j];

        int ans=0;
        if(a[i]==b[j])
          ans=1+solveMem(i+1,j+1,a,b,dp);
        else
        ans=max(solveMem(i+1,j,a,b,dp),solveMem(i,j+1,a,b,dp));

        return dp[i][j]=ans;
    }

public:
    int longestCommonSubsequence(string a, string b) {
        // return solveRec(0,0,a,b);
        vector<vector<int>> dp(a.length(),vector<int>(b.length(),-1));
        return solveMem(0,0,a,b,dp);
    }
};
