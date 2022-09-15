class Solution {
public:
    bool dfs(vector<vector<int>>& grid1,vector<vector<int>>& grid2 ,vector<vector<int>>& vis ,int i,int j,bool check){
        if(grid2[i][j]==1 && grid1[i][j]==0) check = false;
        vis[i][j]=1;
        
        vector<int> row ={0,-1,+1,0};
        vector<int> col = {1,0,0,-1};
        
        for(int k=0;k<4;k++){
            if(i+row[k] >=0 && i+row[k]<grid1.size() && j+col[k] >=0 && j+col[k] <grid1[0].size() && !vis[i+row[k]][j+col[k]] && grid2[i+row[k]][j+col[k]]==1){
                check = dfs(grid1,grid2,vis,i+row[k],j+col[k],check);
            }
        }
        return check;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int row = grid1.size();
        int col = grid1[0].size();
        
        int count = 0;
        vector<vector<int>> vis(row,vector<int> (col,0));
        
        for(int i=0;i<grid2.size();i++){
            for(int j=0;j<grid2[0].size();j++){
                bool check = true;
                if(!vis[i][j] && grid2[i][j]==1){
                    check = dfs(grid1,grid2,vis,i,j,check);
                    if(check) count++;
                }
            }
        }
        return count;
        
    }
};