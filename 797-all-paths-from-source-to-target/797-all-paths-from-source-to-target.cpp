class Solution {
public:
    void dfs(vector<vector<int>>& graph,int v,vector<int> path,vector<vector<int>>& ans,vector<int>& vis){
        if(v==graph.size()-1){
            path.push_back(v);
            ans.push_back(path);
        }
        vis[v]=1;
         path.push_back(v);
        for(auto x:graph[v]){
            if(!vis[x]) dfs(graph,x,path,ans,vis);
            
        }
        vis[v]=0;
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(),0);
        vector<vector<int>> ans;
         for(auto x:graph[0]){
             vector<int> path;
             path.push_back(0);
             dfs(graph,x,path,ans,vis);
         }
        return ans;
    }
};