// problem link: https://leetcode.com/problems/minimum-sideway-jumps/description/

class Solution {
private:
    int solveRec(vector<int>& obstacles, int currLane, int currPos){
        int n=obstacles.size()-1;
        // Base case
        if(currPos==n)
        return 0;

        if(obstacles[currPos+1]!=currLane){
            return solveRec(obstacles,currLane,currPos+1); // straight jaara hai
        }
        else{

            // sideways jump
            int ans=INT_MAX;
            for(int i=1;i<=3;i++)
               if(currLane!=i && obstacles[currPos]!=i)
               ans=min(ans,1+solveRec(obstacles,i,currPos));

            return ans;
        }

    }

    int solveMem(vector<int>& obstacles, int currLane, int currPos, vector<vector<int>>& dp){
        int n=obstacles.size()-1;
        // Base case
        if(currPos==n)
        return 0;


        // check if answer already exists
        if(dp[currPos][currLane]!=-1)
        return dp[currPos][currLane];

        if(obstacles[currPos+1]!=currLane){
            return dp[currPos][currLane]= solveMem(obstacles,currLane,currPos+1,dp); // straight jaara hai
        }
        else{

            // sideways jump
            int ans=INT_MAX;
            for(int i=1;i<=3;i++)
               if(currLane!=i && obstacles[currPos]!=i)
               ans=min(ans,1+solveMem(obstacles,i,currPos,dp));

            return dp[currPos][currLane]= ans;
        }

    }

public:
    int minSideJumps(vector<int>& obstacles) {
        // Recursion--->
        //return solveRec(obstacles,2,0);

        // Recursion+Memoization
        vector<vector<int>> dp(obstacles.size(),vector<int>(3+1,-1));
        return solveMem(obstacles,2,0,dp);
    }
};
