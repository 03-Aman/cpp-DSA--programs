// https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution
{   private:
void dfs(int node,vector<bool> &visited,stack<int> &topoOrder, vector<int> adj[]){
    visited[node]=true;
    for(auto i: adj[node])
        if(!visited[i])
          dfs(i,visited,topoOrder,adj);
    
topoOrder.push(node);
    
}
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{ 
	  vector<bool> visited(V,false);
	  stack<int> topoOrder;
	  for(int i=0;i<V;i++)
	  if(!visited[i])
	  dfs(i,visited,topoOrder,adj);
	  
	  vector<int> ans;
	  while(!topoOrder.empty()){
	      ans.push_back(topoOrder.top());
	      topoOrder.pop();
	  }
	  return ans;
	}
};
