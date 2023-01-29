// problem link: https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{   private:
    
    void dfs(int node, stack<int> &topo,vector<bool> &visited,vector<int> adj[]){
        visited[node]=true;
        for(auto i: adj[node])
           if(!visited[i])
           dfs(i,topo,visited,adj);
           
        topo.push(node);
    } 
    
    void revDfs(int node,vector<bool> &visited,unordered_map<int,list<int>> &transpose){
        visited[node]=true;
        for(auto i: transpose[node])
           if(!visited[i])
           revDfs(i,visited,transpose);
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        
        // topo sort
        stack<int> topo;
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++)
           if(!visited[i])
           dfs(i,topo,visited,adj);
        
        // create transpose of graph
        
        unordered_map<int,list<int>> transpose;
        for(int i=0;i<V;i++){
            visited[i]=false;                  // jab upr dfs call ki thi toh visited array update ho gaya hoga toh isse dobara false krna pdega
            for(auto nbr: adj[i])
                transpose[nbr].push_back(i);
        }
        
        
        // dfs call using topo order and transpose
        int cnt=0;
        while(!topo.empty()){
            int node=topo.top();
            topo.pop();
            if(!visited[node]){
                cnt++;
            revDfs(node,visited,transpose);
                
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
