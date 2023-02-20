// problem link: https://leetcode.com/problems/longest-arithmetic-subsequence/description/
class Solution {
private:
    // int solveRec(int index,vector<int>& nums, int diff){
    //   // backward check

    //     if(index<0)
    //     return 0;

    //     int ans=0;
    //     for(int j=index-1;j>=0;j--)
    //         if(nums[index]-nums[j]==diff)
    //           ans=max(ans,1+solveRec(j,nums,diff));

    //     return ans;
           
    // }

     int solveMem(int index,vector<int>& nums, int diff, vector<unordered_map<int,int>>& dp){
      // backward check

        if(index<0)
        return 0;
        
        if(dp[index].count(diff))
        return dp[index][diff];
        int ans=0;
        for(int j=index-1;j>=0;j--)
            if(nums[index]-nums[j]==diff)
              ans=max(ans,1+solveMem(j,nums,diff,dp));

        dp[index][diff]= ans;
        return dp[index][diff];
           
    }
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)
          return n;
        
        // vector<unordered_map<int,int>> dp(n);   // ek particular index pe ek difference k saath kitni length ka arthematic sequence hai
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         ans=max(ans,2+solveMem(i,nums,nums[j]-nums[i],dp));

        //     }
        // }
        
      
      // TOP DOWN DP--->
        int ans=0;
        vector<unordered_map<int,int>> dp(n);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff=nums[i]-nums[j];
                int cnt=1;
                // check if answer already exists
                if(dp[j].count(diff))
                  cnt=dp[j][diff];
                
                dp[i][diff]=1+cnt;
                ans=max(ans,dp[i][diff]);
            }
        }
        return ans;

        
    }
};
