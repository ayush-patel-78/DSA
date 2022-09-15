class Solution {
public:
    bool dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int i,int j,int check){
        if(i==0 || j==0 || i==grid.size()-1 || j==grid[0].size()-1)  check = true;
        vis[i][j]=1;
        vector<int> rows = {-1,0,+1,0};
        vector<int> cols = {0,-1,0,+1};
        
        for(int k =0;k<4;k++){
            if(i+rows[k]>=0 && i+rows[k] <grid.size() && j+cols[k] >=0 && j+cols[k]<grid[0].size() && !vis[i+rows[k]][j+cols[k]] && grid[i+rows[k]][j+cols[k]]==0){
                check = dfs(grid,vis,i+rows[k],j+cols[k],check);
            }
        }
        return check;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> vis(row,vector<int> (col,0));
        int count = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                bool check = false;
                if(!vis[i][j] && grid[i][j]==0){
                    check = dfs(grid,vis,i,j,check);
                    if(check == false){
                        cout<<i<<" "<<j<<endl;
                        count++;
                    }
                }
            }
        }
        return count;
    }
};