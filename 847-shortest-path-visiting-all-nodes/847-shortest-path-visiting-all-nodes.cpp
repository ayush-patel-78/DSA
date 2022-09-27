class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int all = (1<<n) - 1; 
        
        queue<pair<int,pair<int,int>>>q;
        set<pair<int,int>>st;
        
        for(int i = 0;i<n;i++){
            int mask = 1<<i;
            q.push({0,make_pair(i,mask)});
            st.insert({i,mask});
        }
        
        while(!q.empty()){
            int v = q.front().second.first;
            int mask = q.front().second.second;
            int dis = q.front().first;
            
            q.pop();
            
            for(int i=0;i<graph[v].size();i++){
                int new_mask = (mask | (1<<graph[v][i]));
                if(new_mask == all) return dis + 1;
                else if(st.find({graph[v][i],new_mask}) !=st.end()) continue;
                else {
                    q.push({dis+1,make_pair(graph[v][i],new_mask)});
                    st.insert({graph[v][i],new_mask});
                }
            }
        }
        return 0;
    }
};