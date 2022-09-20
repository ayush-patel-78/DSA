class Solution {
public:
    void dfs(vector<vector<int>>& rooms,int v,vector<int> & ans,vector<int> & vis){
        vis[v]=1;
        ans[v]=1;
        for(auto x:rooms[v]){
            if(!vis[x]) dfs(rooms,x,ans,vis);
        }
        
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size(),0);
        vector<int> ans(rooms.size(),0);
        
        for(auto x:rooms[0]){
            ans[0]=1;
            vis[0]=1;
            dfs(rooms,x,ans,vis);
        }
        for(auto x:ans){
            if(x==0) return false;
        }
        return true;
    }
};