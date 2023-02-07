// problem link: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/

class Solution {
    private:
    int solveRec(vector<int>& val, int i, int j){
        // base case --> if the two vertices are adjacent i.e "i+1=j"
        if(i+1==j)
        return 0;

        int ans=INT_MAX;

        for(int k=i+1;k<j;k++){
            ans=min(ans,val[i]*val[k]*val[j]+solveRec(val,i,k)+solveRec(val,k,j));
        }
        return ans;
    }

    int solveMem(vector<int>& val, int i, int j, vector<vector<int>>& dp){
        // base case --> if the two vertices are adjacent i.e "i+1=j"
        if(i+1==j)
        return 0;

        // check if answer already exists
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        int ans=INT_MAX;

        for(int k=i+1;k<j;k++){
            ans=min(ans,val[i]*val[k]*val[j]+solveMem(val,i,k,dp)+solveMem(val,k,j,dp));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }

public:
    int minScoreTriangulation(vector<int>& val) {
     
     int n=val.size();

    // Recursion -->
    //return solveRec(val,0,n-1);

    // Recursion+Memoization
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return solveMem(val,0,n-1,dp);
    }
};
