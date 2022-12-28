  // problem link: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
  class Solution {
    private:
    void dfs( int node,vector<int> &ans, vector<int> adj[],vector<bool> &visited){
        ans.push_back(node);
        visited[node]=true;
        for(auto i: adj[node])
        if(!visited[i])
        {
            dfs(i,ans,adj,visited);
        }
        
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[0])
            dfs(i,ans,adj,visited);
        }
   return ans; }