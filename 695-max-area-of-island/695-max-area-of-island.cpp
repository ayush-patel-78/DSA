#define ll long long
class Solution {
public:
    bool isValid(int i,int j,int n,int m,vector<vector<int>>& grid){
        if(i>=0 && j>=0 && i<n && j<m && grid[i][j]==1){
            return true;
        }
        else return false;
    }
    void dfs(int i,int j,int n,int m,vector<vector<int>>& grid,ll & area)     {
        area++;
        grid[i][j]=0;
        if(isValid(i+1,j,n,m,grid)){
            dfs(i+1,j,n,m,grid,area);
        }
        if(isValid(i,j+1,n,m,grid)){
            dfs(i,j+1,n,m,grid,area);
        }
        if(isValid(i-1,j,n,m,grid)){
            dfs(i-1,j,n,m,grid,area);
        }
        if(isValid(i,j-1,n,m,grid)){
            dfs(i,j-1,n,m,grid,area);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m = grid[0].size();
        ll ans = 0;
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ll area = 0;
                    dfs(i,j,n,m,grid,area);
                    
                    ans = max(ans,area);
                }
            }
        }
        return ans;
    }
};