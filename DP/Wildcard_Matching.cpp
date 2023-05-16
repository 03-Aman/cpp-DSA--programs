// problem link: https://leetcode.com/problems/wildcard-matching/description/
class Solution {
private:
    bool solveRec(int i, int j, string& s, string& p){
        if(i<0 && j<0)
        return true;

        if(i>=0 && j<0)
        return false;
        
        if(i<0 && j>=0){
            for(int k=0;k<=j;k++)
               if(p[k]!='*')
               return false;
            
            return true;
        }

        if(s[i]==p[j] || p[j]=='?')
        return solveRec(i-1,j-1,s,p);
        else if(p[j]=='*')
        return solveRec(i-1,j,s,p) || solveRec(i,j-1,s,p);
        else
        return false;
    }

    bool solveMem(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        if(i<0 && j<0)
        return true;

        if(i>=0 && j<0)
        return false;
        
        if(i<0 && j>=0){
            for(int k=0;k<=j;k++)
               if(p[k]!='*')
               return false;
            
            return true;
        }

        if(dp[i][j]!=-1)
        return dp[i][j];

        if(s[i]==p[j] || p[j]=='?')
        return dp[i][j]=solveMem(i-1,j-1,s,p,dp);
        else if(p[j]=='*')
        return dp[i][j]=solveMem(i-1,j,s,p,dp) || solveMem(i,j-1,s,p,dp);
        else
        return dp[i][j]=false;
    }

public:
    bool isMatch(string s, string p) {
        // return solveRec(s.length()-1,p.length()-1,s,p);
        vector<vector<int>> dp(s.length(),vector<int>(p.length(),-1));
        return solveMem(s.length()-1,p.length()-1,s,p,dp);
    }
};
