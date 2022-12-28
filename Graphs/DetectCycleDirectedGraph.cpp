// problem link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
class Solution {
    private:
 bool isCycleDfs(int node,vector<bool> &visited,vector<bool> &dfsVisited,vector<int> adj[]){
     visited[node]=true;
     dfsVisited[node]=true;
     for(auto i: adj[node]){
         if(!visited[i]){
             bool cycleDetected=isCycleDfs(i,visited,dfsVisited,adj);
             if(cycleDetected)   // cycle present
             return true;    
         }
         else if(dfsVisited[i])
         return true;
     }
     dfsVisited[node]=false;
     return false;
 }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> visited(V,false);
        vector<bool> dfsVisited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i])
          {bool cycleFound=isCycleDfs(i,visited,dfsVisited,adj);
          if(cycleFound)
          return true;}
        }
        return false;
    }
};