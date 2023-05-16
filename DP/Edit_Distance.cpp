// https://leetcode.com/problems/edit-distance/description/
class Solution {
private:
   int solveRec(int i, int j, string &a, string &b){
       if(i==a.length())  // it means length of string (a) is smaller
       return b.length()-j;
       
       if(j==b.length()) // it means length of string (b) is smaller
       return a.length()-i; 
       
       int ans=0;
       if(a[i]==b[j])
       return solveRec(i+1,j+1,a,b);
       else{
           // insert
           int insert=1+solveRec(i,j+1,a,b);
           // delete
           int del=1+solveRec(i+1,j,a,b);
           // replace
           int replace=1+solveRec(i+1,j+1,a,b);
           
           ans=min(insert,min(del,replace));
       }
       return ans;
   }

   int solveMem(int i, int j, string &a, string &b,vector<vector<int>>& dp){
       if(i==a.length())  // it means length of string (a) is smaller
       return b.length()-j;
       
       if(j==b.length()) // it means length of string (b) is smaller
       return a.length()-i; 
       
       if(dp[i][j]!=-1)
       return dp[i][j];

       int ans=0;
       if(a[i]==b[j])
       return solveMem(i+1,j+1,a,b,dp);
       else{
           // insert
           int insert=1+solveMem(i,j+1,a,b,dp);
           // delete
           int del=1+solveMem(i+1,j,a,b,dp);
           // replace
           int replace=1+solveMem(i+1,j+1,a,b,dp);
           
           ans=min(insert,min(del,replace));
       }
       return dp[i][j]=ans;
   }

public:
    int minDistance(string word1, string word2) {
        // return solveRec(0,0,word1,word2);
        vector<vector<int>> dp(word1.length(),vector<int>(word2.length(),-1));
        return solveMem(0,0,word1,word2,dp);
    }
};
