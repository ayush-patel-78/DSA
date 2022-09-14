class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int row,int col){
        vis[row][col] = 1;
        vector<int> row_vec ={-1,0,+1,0};
        vector<int> col_vec = {0,-1,0,+1};
        for(int i=0;i<4;i++){
            if(row+row_vec[i] >= 0 && row +row_vec[i] < grid.size() &&  col + col_vec[i] >= 0 && col + col_vec[i] < grid[0].size() && !vis[row+row_vec[i]][col + col_vec[i]] && grid[row+row_vec[i]][col + col_vec[i]] ==1){
                dfs(grid,vis,row+row_vec[i],col+col_vec[i]);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> vis(row,vector<int>(col,0));
        // traverse row 
        for(int j = 0;j<col;j++){
            // traverse first row
            if(!vis[0][j] && grid[0][j]==1){
                dfs(grid,vis,0,j);
            }
            
            // traverse last row 
            if(!vis[row-1][j] && grid[row-1][j]==1){
                dfs(grid,vis,row-1,j);
            }
        }
        // traverse col
        for(int i = 0;i<row;i++){
            // traverse first col
            if(!vis[i][0] && grid[i][0]==1){
                dfs(grid,vis,i,0);
            }
            
            // traverse last col 
            if(!vis[i][col-1] && grid[i][col-1]==1){
                dfs(grid,vis,i,col-1);
            }
        }
        
        int count = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
        
    }
};