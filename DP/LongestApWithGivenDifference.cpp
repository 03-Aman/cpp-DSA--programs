// problem link: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int,int> dp;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            int temp=arr[i]-diff;
            int tempAns=0;
            
            // check if temp ans already exists in dp 
            if(dp.count(temp))
              tempAns=dp[temp];

            // update the dp 
            dp[arr[i]]=1+tempAns;

            ans=max(ans,dp[arr[i]]);
        }
        return ans;
    }
};
