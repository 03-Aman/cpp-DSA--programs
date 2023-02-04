// problem link: https://leetcode.com/problems/minimum-cost-for-tickets/description/
class Solution {
    private:
    int solveRec(vector<int>& days, int index, vector<int>& costs){
        // base case
        if(index>=days.size())
        return 0;

        // 1 day pass
        int option1=costs[0]+solveRec(days,index+1,costs);

        int i;
        // 7 days pass
        for( i=index; i<days.size() && days[i]<days[index]+7; i++);
  
        int option2=costs[1]+solveRec(days,i,costs);

        // 30 days pass
        for(i=index; i<days.size() && days[i]<days[index]+30; i++);

        int option3=costs[2]+solveRec(days,i,costs);

        return min(option1,min(option2,option3));
    }

     private:
    int solveMem(vector<int>& days, int index, vector<int>& costs,vector<int>& dp){
        // base case
        if(index>=days.size())
        return 0;

        if(dp[index]!=-1)
        return dp[index];    

        // 1 day pass
        int option1=costs[0]+solveMem(days,index+1,costs,dp);

        int i;
        // 7 days pass
        for( i=index; i<days.size() && days[i]<days[index]+7; i++);
  
        int option2=costs[1]+solveMem(days,i,costs,dp);

        // 30 days pass
        for(i=index; i<days.size() && days[i]<days[index]+30; i++);

        int option3=costs[2]+solveMem(days,i,costs,dp);

        dp[index]= min(option1,min(option2,option3));

        return dp[index];
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // recursion
        // return solveRec(days,0,costs);

         // recursion + memoization
         vector<int> dp(days.size()+1,-1);
         return solveMem(days,0,costs,dp);
    }
};
