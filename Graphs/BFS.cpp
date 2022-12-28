// problem link: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        queue<int> q;
        vector<bool>visited(V,false);
        q.push(0);
        visited[0]=true;
        int u;
        while(!q.empty()){
           u=q.front();
           ans.push_back(u);
           q.pop();
           for(auto i: adj[u]){
               if(!visited[i]){
                   visited[i]=true;
                   q.push(i);
               }
           }
        }
    return ans;}
};