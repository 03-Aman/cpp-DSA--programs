// problem link: https://leetcode.com/problems/all-paths-from-source-to-target/
class Solution {
    public:
    vector<int> path;
private: 

void dfs(int curr,vector<vector<int>>&res,vector<vector<int>>adj,int target){
   
    path.push_back(curr);
    if(curr==target)
    res.push_back(path);
    else{
        for(auto i: adj[curr])
            dfs(i,res,adj,target);
    }
    path.pop_back();    // back tracking
    
}
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<vector<int>> res;
        dfs(0,res,adj,n-1);
   return res; }
};