class Solution {
public:
    void dfs(int v,vector<vector<int>>& adj,vector<vector<int>>& fake,int& ans ,vector<int>& vis){
      vis[v]=1;
        for(int i=0;i<adj[v].size();i++){
            if(!vis[adj[v][i]]){
                ans++;
                dfs(adj[v][i],adj,fake,ans,vis);
            }
        }
        for(int i=0;i<fake[v].size();i++){
            if(!vis[fake[v][i]]){
                dfs(fake[v][i],adj,fake,ans,vis);
            }
        }
   
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<vector<int>> fake(n);
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            fake[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> vis(n,0);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(i,adj,fake,ans,vis);
        }
        return ans;
       
    }
};