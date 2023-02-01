// problem link: https://leetcode.com/problems/house-robber-ii/description/
class Solution {
    private:
    // int solveRec(vector<int>& nums,int index){
    //     if(index<0)
    //     return 0;
        
    //     if(index==0)
    //     return nums[0];

    //     int include=nums[index]+solveRec(nums,index-2);
    //     int exclude=0+ solveRec(nums,index-1);

    //     return max(include,exclude);
    // }

    int solveTabulation(vector<int>& nums){
        int n=nums.size();
        vector<int> dp(n+1,0);
        dp[0]=nums[0];

        for(int i=1;i<n;i++){
            int include=nums[i];
            if(i>1)
             include=dp[i-2]+nums[i];
            int exclude=dp[i-1]+0;
            dp[i]=max(include,exclude);
        }

        return dp[n-1];
    }


    // int solveMem(vector<int> &arr,int index, vector<int> &dp){
    //     if(index<0)
    //     return 0;
    //     if(index==0)
    //     return arr[0];

    //    if(dp[index]!=-1)
    //    return dp[index]; 

    //     int include=arr[index]+solveMem(arr,index-2,dp);
    //     int exclude=0+solveMem(arr,index-1,dp);
    //     dp[index]=max(include,exclude);
        
    //     return dp[index];


    // }
public:
    int rob(vector<int>& nums) {

         if(nums.size()==1)
        return nums[0];
        
        // nums=[1,2,3,4,5]
        // fist house last house ka neighbour hai
        // first=[1,2,3,4]
        // second=[2,3,4,5]
        vector<int> first,second;   
        
        for(int i=0;i<nums.size();i++){
            if(i!=nums.size()-1)
            first.push_back(nums[i]);

            if(i!=0)
            second.push_back(nums[i]);
        }
        
        // recursion---->
       // return max(solveRec(first,first.size()-1),solveRec(second,second.size()-1));
      


        
       
           
        // tabulation----->

         return max(solveTabulation(first),solveTabulation(second));


        // recursion + memoization----->

        // vector<int> dp1(first.size()+1,-1);
        //  vector<int> dp2(second.size()+1,-1);
        // return max(solveMem(first,first.size()-1,dp1),solveMem(second,second.size()-1,dp2));
        
    }
};
