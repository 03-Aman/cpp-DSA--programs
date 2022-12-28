// problem link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
    private:
  bool  isCyclicBfs(int src,vector<bool> &visited,vector<int> adj[]){
        unordered_map<int,int> parent;
        parent[src]=-1;
        queue<int>q;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto i: adj[node]){
                if(visited[i]&&i!=parent[node])
                return true;
                else if(!visited[i]){
                    q.push(i);
                    visited[i]=true;
                    parent[i]=node;
                }
            }
            
        }
        return false;
    }
    bool isCyclicDfs(int node,int parent,vector<bool> &visited,vector<int> adj[]){
        visited[node]=true;
        for(auto i: adj[node]){
            if(visited[i]&&i!=parent)
            return true;
            else if(!visited[i]){
               if(isCyclicDfs(i,node,visited,adj))
               return true;
            }
        }return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(isCyclicDfs(i,-1,visited,adj))
                return true;
            }
        }
        return false;
    }
};