class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{    vector<int> ans;
	
	   vector<int> indegree(V,0);
	   // creating indegree array
	   for(int i=0;i<V;i++)
	     for(auto j: adj[i])
	        indegree[j]++;
	   
	   queue<int>q;
	   for(int i=0;i<V;i++)
	       if(indegree[i]==0)   // agar kisi jis vertex ki indegree 0 hai usse queue m push kro
	       q.push(i);
	       
	       
	   // aage saara bfs waala khel
	   
	   while(!q.empty()){
	       int node =q.front();
	       q.pop();
	       ans.push_back(node);
	       for(auto i: adj[node])
	       {indegree[i]--; // jo node k neighboour hai unki indegree minus one krdi
	        if(indegree[i]==0)
	        q.push(i);
	                        }
	       
	   }
	   
return ans;	}
};