// problem link: https://leetcode.com/problems/reducing-dishes/description/
class Solution {
    private:
    // int solveRec(vector<int>& satis, int index, int time){
    //     if(index>=satis.size())
    //     return 0;

    //     int include=((time+1)*satis[index])+solveRec(satis,index+1,time+1);
    //     int exclude=0+solveRec(satis,index+1,time);

    //     return max(include,exclude);
    // }
    
    int solveMem(vector<int>& satis, int index, int time, vector<vector<int>>& dp){
        if(index>=satis.size())
        return 0;

        // checking if already answer exists
        if(dp[index][time]!=-1)
        return dp[index][time];

        int include=((time+1)*satis[index])+solveMem(satis,index+1,time+1,dp);
        int exclude=solveMem(satis,index+1,time,dp);

        dp[index][time]=max(include,exclude);
        return dp[index][time];
    }

     

public:
    int maxSatisfaction(vector<int>& satis) {
        sort(satis.begin(),satis.end());
        int n=satis.size();
        int time=0;
        // Recursion--->
        //return solveRec(satis,0,time); 

        // Recursion+Memoization
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));  // 2d vector as time and index i.e two things    are changing in function call
        return solveMem(satis,0,time,dp);

    }
};
