class Solution {
public:
    void dfs(int v,vector<int>& vis,vector<vector<int>>& isConnected){
        vis[v]=1;
        for(int j=0;j<isConnected[v].size();j++){
            if( !vis[isConnected[v][j]]){
                dfs(isConnected[v][j],vis,isConnected);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        vector<vector<int>> isConnected(n);
        for(int i=0;i<connections.size();i++){
            int x = connections[i][0];
            int y = connections[i][1];
            isConnected[x].push_back(y);
            isConnected[y].push_back(x);
        }
        for(int i=0;i<n;i++){
            isConnected[i].push_back(i);
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<isConnected[i].size();j++){
        //         cout<<isConnected[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
         vector<int> vis(n,0);
        
        int provinces = 0;
         for(int i=0;i<n;i++){
             for(int j=0;j<isConnected[i].size();j++){
                 if(!vis[i] && !vis[isConnected[i][j]])
                 {   
                     dfs(isConnected[i][j],vis,isConnected);
                     provinces++;
                     
                 }
             }
         }
        // cout<<provinces<<endl;
        if(edges >= (n -1)) return provinces-1;
        return -1;
    }
};