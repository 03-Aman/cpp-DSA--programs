// problem link: https://leetcode.com/problems/network-delay-time/description/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        unordered_map<int,list<pair<int,int>>> adj;
        for(auto i: times){
            int u=i[0];
            int v=i[1];
            int cost=i[2];
            adj[u].push_back(make_pair(v,cost));
        }
        
        vector<int> distance(n+1,INT_MAX);   // we will take distance array which represent minimum distance/time to reach that node from src node
        distance[src]=0;
        set<pair<int,int>> st;   // pair--> (nodeDistance,node)
        st.insert(make_pair(0,src));

        while(!st.empty()){
            // fetch top record
            auto top=*(st.begin());
            int topNode=top.second;
            int nodeDistance=top.first;
            //  erase top record
            st.erase(st.begin());

            // travesing neighbour
            for(auto neighbour: adj[topNode]){
                if(nodeDistance+neighbour.second<distance[neighbour.first]){
                    // finding if record already exists
                    auto record=st.find(make_pair(distance[neighbour.first],neighbour.first));
                    // if found then erase it
                    if(record!=st.end())
                    st.erase(record);
                    // update distance
                    distance[neighbour.first]=nodeDistance+neighbour.second;
                    // insert it into set
                    st.insert(make_pair(distance[neighbour.first],neighbour.first));
                }
            }

        }
    int ans=INT_MIN;
    for(int i=1;i<distance.size();i++)
       ans=max(ans,distance[i]);


    if(ans==INT_MAX)
    return -1;

    return ans;      
    
    }
};
