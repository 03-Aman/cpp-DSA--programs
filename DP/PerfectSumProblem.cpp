// https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1
int mod=1000000007;
int solve(int i, int arr[], int n, int sum, vector<vector<int>>& dp){
    if(i == n || sum < 0)
        return 0;

    if(sum == 0)
        return 1;

    if(arr[i] == sum)
        return 1;

    if(dp[i][sum] != -1)
        return dp[i][sum];

    int take = solve(i + 1, arr, n, sum - arr[i], dp) % mod;
    int notTake = solve(i + 1, arr, n, sum, dp) % mod;

    return dp[i][sum] = (take + notTake) % mod;
}
