// problem Link: https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/
class Solution {
private:
    int solveRec(vector<int>& nums1, vector<int>& nums2, int index, bool swapped){
        if (index==nums1.size())
        return 0;

        int ans=INT_MAX;
        int prev1=nums1[index-1];
        int prev2=nums2[index-1];
        
        // here's a catch
        if(swapped)
          swap(prev1,prev2);
        
        // no swap
        if(nums1[index]>prev1 && nums2[index]>prev2)
           ans=min(ans,solveRec(nums1,nums2,index+1,0));
        
        // swap
        if(nums2[index]>prev1 && nums1[index]>prev2)
          ans=min(ans,1+solveRec(nums1,nums2,index+1,1));
        
        return ans;
    }

    int solveMem(vector<int>& nums1, vector<int>& nums2, int index, bool swapped,vector<vector<int>>& dp){
        if (index==nums1.size())
        return 0;

        int ans=INT_MAX;
        int prev1=nums1[index-1];
        int prev2=nums2[index-1];

        // check if answer already exists
        if(dp[index][swapped]!=-1)
        return dp[index][swapped];
        
        // here's a catch
        if(swapped)
          swap(prev1,prev2);
        
        // no swap
        if(nums1[index]>prev1 && nums2[index]>prev2)
           ans=min(ans,solveMem(nums1,nums2,index+1,0,dp));
        
        // swap
        if(nums2[index]>prev1 && nums1[index]>prev2)
          ans=min(ans,1+solveMem(nums1,nums2,index+1,1,dp));
        
        dp[index][swapped]=ans;
        return dp[index][swapped];
    }

public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        bool swapped=0;
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        // return solveRec(nums1,nums2,1,swapped);
        int n=nums1.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return solveMem(nums1,nums2,1,swapped,dp);
    }
};
