// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,list<pair<int,int>>> adj;
        for(auto i: flights){
            adj[i[0]].push_back(make_pair(i[1],i[2])); // (node-->(neighbour,distance))
        }
      
        vector<int> distance(n,INT_MAX);
        distance[src]=0;
        queue<pair<int,pair<int,int>>> q;    // (k,(node,dist))
        q.push({0,make_pair(src,distance[src])});
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int stops=curr.first;
            int node=curr.second.first;
            int cost=curr.second.second;
            if(stops>k)
            continue;
            for(auto it: adj[node]){
                int neighNode=it.first;
                int wt=it.second;
                if(cost+wt<distance[neighNode] && stops<=k){
                    distance[neighNode]=cost+wt;
                    q.push({stops+1,make_pair(neighNode,cost+wt)});
                }
            }
        }

        if(distance[dst]==INT_MAX)
        return -1;

        return distance[dst];
    }
};
