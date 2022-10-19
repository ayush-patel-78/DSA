class Solution {
public:
    int dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int i,int j){
        
        // if(i < 0 || i >=grid.size() || j < 0 || j>=grid[0].size()) return 0;
        vis[i][j]=1;
        vector<int> rows = {+1,0,-1,0};
        vector<int> cols = {0,+1,0,-1};
        int count =0;
        for(int k=0;k<4;k++){
            if(i+rows[k] >=0 && i+rows[k] <grid.size() && j+cols[k]>=0 && j+cols[k]<grid[0].size() && !vis[i+rows[k]][j+cols[k]] && grid[i+rows[k]][j+cols[k]]==1){
                count+=dfs(grid,vis,i+rows[k],j+cols[k])+1;
            }
        }
        return count;
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        int max_land = 0;
        vector<vector<int>> vis(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int land = dfs(grid,vis,i,j)+1;
                    max_land = max(max_land,land);
                }
            }
        }
        return max_land;
    }
};