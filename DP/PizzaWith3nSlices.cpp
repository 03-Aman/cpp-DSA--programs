// https://leetcode.com/problems/pizza-with-3n-slices/description/
class Solution {
private:
int solveRec(vector<int>& slices, int index, int endIndex, int n){
    if(n==0 || index > endIndex)
    return 0;

    int include=slices[index] + solveRec(slices, index+2, endIndex, n-1 );
    int exclude=solveRec(slices, index+1, endIndex, n);
    return max(include,exclude);
}

int solveMem(vector<int>& slices, int index, int endIndex, int n, vector<vector<int>>& dp){
    if(n==0 || index > endIndex)
    return 0;

    if(dp[index][n]!=-1)
    return dp[index][n];

    int include=slices[index] + solveMem(slices, index+2, endIndex, n-1, dp);
    int exclude=solveMem(slices, index+1, endIndex, n, dp);
    dp[index][n]= max(include,exclude);

    return dp[index][n];
}
public:
    int maxSizeSlices(vector<int>& slices) {
        int k=slices.size();
        // Recursion
        //return max(solveRec(slices,0,k-2,k/3),solveRec(slices,1,k-1,k/3));


        // Recursion+Memoization
        vector<vector<int>> dp1(k,vector<int>(k,-1));
        vector<vector<int>> dp2(k,vector<int>(k,-1));
        return max(solveMem(slices,0,k-2,k/3,dp1),solveMem(slices,1,k-1,k/3,dp2));
        

    }
};
