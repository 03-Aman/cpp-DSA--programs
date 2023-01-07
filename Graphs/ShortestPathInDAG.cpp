// problem link: https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
class Solution {
    private:
    void dfs(int node,vector<bool> &visited,stack<int> &topoSort,   unordered_map<int,list<pair<int,int>>> adj){
        visited[node]=true;
        for(auto i: adj[node])
        if(!visited[i.first])
        dfs(i.first,visited,topoSort,adj);
        
        topoSort.push(node);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<int> dist(N,INT_MAX);
        dist[0]=0;    // hamara source kya hai "0";
        unordered_map<int,list<pair<int,int>>> adj;
       for(int i=0;i<M;i++){
           adj[edges[i][0]].push_back(make_pair(edges[i][1],edges[i][2]));
       }
      
      
      // printing adj list
    //   for(auto i: adj){
    //       cout<<i.first<<" ->";
    //       for(auto j: i.second){
    //           cout<<"("<<j.first<<","<<j.second<<")";
    //       }
    //       cout<<endl;
    //   }
      
      vector<bool> visited(N,false);
      stack<int> topoSort;
      for(int i=0;i<N;i++)
      if(!visited[i])
      dfs(i,visited,topoSort,adj);
      
    //   while(!topoSort.empty()){
    //       cout<<topoSort.top()<<" ";
    //       topoSort.pop();
    //   }
    //   cout<<endl;
      
      while(!topoSort.empty()){
          int node =topoSort.top();
          topoSort.pop();
          if(dist[node]!=INT_MAX){
              for(auto i:adj[node]){
                  if(dist[node]+i.second<dist[i.first])
                  dist[i.first]=dist[node]+i.second;
              }
          }
      }
      for(int i=0;i<N;i++)
      if(dist[i]==INT_MAX)
        dist[i]=-1;
        
       return dist;
    }
};