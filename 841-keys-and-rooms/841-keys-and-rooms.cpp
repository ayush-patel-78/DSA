class Solution {
public:
    void dfs(vector<vector<int>>& rooms,int v,vector<int> & vis){
        vis[v]=1;
        for(auto x:rooms[v]){
            if(!vis[x]) dfs(rooms,x,vis);
        }
        
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size(),0);
        
        for(auto x:rooms[0]){
            vis[0]=1;
            dfs(rooms,x,vis);
        }
        for(auto x:vis){
            if(x==0) return false;
        }
        return true;
    }
};