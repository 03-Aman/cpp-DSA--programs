// problem link: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> distance(V,INT_MAX);
        distance[S]=0;
        set<pair<int,int>> st;    // pair-->(distance,node), hamne set isliye liya kyuki hum hrr baar shortest distance nikal rahe hai
        st.insert(make_pair(0,S));
        
        while(!st.empty()){
            // top ki node nikal lo
             auto top =*(st.begin());
             int nodeDistance=top.first;
             int topNode=top.second;
             
             //  remove record
             st.erase(st.begin());
             
             // travesing neighbour
             for(auto neighbour: adj[topNode]){
                 if(nodeDistance+neighbour[1]<distance[neighbour[0]]){
                     // finding if it already exists in set or not
                     auto record=st.find(make_pair(distance[neighbour[0]],neighbour[0]));
                      
                     // if record found then erase it 
                     if(record!=st.end()){
                         st.erase(record);
                     }
                     
                     // update distance
                     distance[neighbour[0]]=nodeDistance+neighbour[1];
                     // insert it in to set
                     st.insert(make_pair(distance[neighbour[0]],neighbour[0]));
                 }
             }
        }
    return distance;}
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
