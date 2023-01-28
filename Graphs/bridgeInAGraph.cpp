// problem link: https://leetcode.com/problems/critical-connections-in-a-network/description/
class Solution {
    private: 
    void dfs(int node,int parent,int &timer,vector<int> &disc,vector<int> &low,vector<vector<int>> &res,unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited){
        visited[node]=true;
        disc[node]=low[node]=timer++;

        for(auto nbr: adj[node]){
            if(nbr==parent)
            continue;
            if(!visited[nbr]){
               dfs(nbr,node,timer,disc,low,res,adj,visited);
               low[node]=min(low[node],low[nbr]);

               // check edge is bridge
               if(low[nbr]>disc[node]){
                   vector<int> ans;
                   ans.push_back(nbr);
                   ans.push_back(node);
                   
                   res.push_back(ans);
               }

            }
            else{
                // back edge
                low[node]=min(disc[nbr],low[node]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    unordered_map<int,list<int>> adj;
    for(auto i: connections){
        int u=i[0];
        int v=i[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer=0;
    vector<int> disc(n,-1);
    vector<int> low(n,-1);
    int parent=-1;
    unordered_map<int,bool> visited;

 vector<vector<int>> res;
    // dfs
   for(int i=0;i<n;i++){
       if(visited[i]==false)
        dfs(i,parent,timer,disc,low,res,adj,visited);  
   }
         

    return res;


    }

   

};
