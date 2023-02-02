// problem link: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
    int solveRec(int capacity, int wt[], int val[], int index){
        // Base case
        if(index==0){
            if(wt[index]<=capacity)
              return val[index];
            
            else
            return 0;
        }
        
        int include;
        
        if(wt[index]<=capacity)
        include=val[index]+solveRec(capacity-wt[index],wt,val,index-1);
        
        int exclude=0+solveRec(capacity,wt,val,index-1);
        
        return max(include,exclude);
    }
    
   int solveMem(int capacity, int wt[], int val[], int index,vector<vector<int>>& dp){
        // Base case
        if(index==0){
            if(wt[0]<=capacity)
              return val[0];
            
            else
            return 0;
        }
        
        if(dp[index][capacity]!=-1)
        return dp[index][capacity];
        
        
        int include=0;
        
        if(wt[index]<=capacity)
        include=val[index]+solveMem(capacity-wt[index],wt,val,index-1,dp);
        
        int exclude=0+solveMem(capacity,wt,val,index-1,dp);
        
        dp[index][capacity]= max(include,exclude);
        
        return dp[index][capacity];
        
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int capacity, int wt[], int val[], int n) 
    { 
       // Your code here
       //return solveRec(capacity,wt,val,n-1);
       
       // memoization
       
       vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
       return solveMem(capacity,wt,val,n-1,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
