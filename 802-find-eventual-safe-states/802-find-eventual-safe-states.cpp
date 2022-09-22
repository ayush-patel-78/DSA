class Solution {
public:
    int dfs(int v,vector<vector<int>>& graph,vector<int>& vis,vector<int>& safe){
        
        if(safe[v]!=-1) return safe[v];
        if(graph[v].size()==0) {
            safe[v]=1;
            return 1;
        }
        for(int i=0;i<graph[v].size();i++){
            if(!vis[graph[v][i]]){
                vis[v]=1;
                int j = dfs(graph[v][i],graph,vis,safe);
                vis[v]=0;
                if(j==0) {
                    safe[v]=0;
                }
            }
            else{
                safe[v]=0;
            }
        }
       
        if(safe[v] != -1){
            return 0;
        }
        return safe[v]=1;
        
   
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> safe(n,-1);
        
        for(int i=0;i<n;i++){
            if(graph[i].size()==0) safe[i]=1;
        }
        
        for(int i=0;i<n;i++){
            
            dfs(i,graph,vis,safe) ;
            
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(safe[i]==1) ans.push_back(i);
        }
        return ans;
    }
};