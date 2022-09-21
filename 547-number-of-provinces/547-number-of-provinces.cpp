class Solution {
public:
    void dfs(int v,vector<int>& vis,vector<vector<int>>& isConnected){
        vis[v]=1;
        for(int j=0;j<isConnected.size();j++){
            if(isConnected[v][j]==1 && !vis[j]){
                dfs(j,vis,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
         int nodes = isConnected.size();
         vector<int> vis(nodes,0);
        
        int provinces = 0;
         for(int i=0;i<nodes;i++){
             for(int j=0;j<nodes;j++){
                 if(isConnected[i][j]==1 && !vis[j])
                 {
                     dfs(j,vis,isConnected);
                     provinces++;
                 }
             }
         }
        return provinces;
    }
};