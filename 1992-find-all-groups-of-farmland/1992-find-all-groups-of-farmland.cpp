class Solution {
public:
    vector<int> dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int i,int j,vector<int>& hue){
        
        if(i <= hue[0] && j <= hue[1]){
            hue[0]=i;
            hue[1]=j;
        }
        if(i>=hue[2] && j>= hue[3]){
            hue[2]=i;
            hue[3]=j;
        }
        vis[i][j]=1;
        vector<int> rows = {+1,0,-1,0};
        vector<int> cols = {0,+1,0,-1};
        int count =0;
        for(int k=0;k<4;k++){
            if(i+rows[k] >=0 && i+rows[k] <grid.size() && j+cols[k]>=0 && j+cols[k]<grid[0].size() && !vis[i+rows[k]][j+cols[k]] && grid[i+rows[k]][j+cols[k]]==1){
                hue=dfs(grid,vis,i+rows[k],j+cols[k],hue);
            }
        }
        return hue;
        
        
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& grid) {
          int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> vis(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<int> hue ={row,col,0,0};
                    vector<int> hehe = dfs(grid,vis,i,j,hue);
                    ans.push_back(hehe);
                }
            }
        }
        return ans;
    }
};