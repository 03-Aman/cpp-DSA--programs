// https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start==end)
        return 0;
        
        int mod=100000;
        queue<pair<int,int>> q;   // pair<steps,node> 
        vector<int> distance(mod,INT_MAX);
        distance[start]=0;
        q.push({0,start});
        while(!q.empty()){
            int steps=q.front().first;
            int num=q.front().second;
            q.pop();
            
            for(auto i: arr){
                int next=(i*num)%mod;
                if(next==end)
                return steps+1;
                
                if(steps+1<distance[next]){
                    distance[next]=steps+1;
                    q.push({steps+1,next});
                }
            }
        }
        
        return -1;
    }
};
