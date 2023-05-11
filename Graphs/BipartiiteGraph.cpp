// problem link: https://leetcode.com/problems/is-graph-bipartite/description/
class Solution {
private:
    bool checkBfs(int n, vector<vector<int>>& graph, vector<int>& color){
        queue<int> q;
        q.push(n);
       color[n]=0;
       while(!q.empty()){
           int node=q.front();
           q.pop();
           for(auto i:graph[node]){
               if(color[i]==-1){
                color[i]=1-color[node];
                q.push(i);
               }
               if(color[i]==color[node])
               return false;
           }
       }
       return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
       int n=graph.size();
       vector<int> color(n,-1);
       for(int i=0;i<n;i++){
           if(color[i]==-1)
           if(!checkBfs(i,graph,color))
           return false;
       }
       return true;
    }
};
