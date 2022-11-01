class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp){
        if(i==grid.size()){
           return j;
        }
        if(dp[i][j] != -2) return dp[i][j];
        int x = grid[i][j];
        if(j==grid[0].size()-1 && x==1 ) return -1;
        if(j==0 && x==-1) return -1;
        int ans = -1;
        if(x==1 && grid[i][j+1]==1){
            ans = solve(grid,i+1,j+1,dp);
        }
        else if(x==-1 && grid[i][j-1]==-1){
            ans = solve(grid,i+1,j-1,dp);
        }
        return dp[i][j] = ans;
        
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        vector<vector<int>> dp(grid.size()+1,vector<int>(grid[0].size()+1,-2));
        for(int i=0;i<grid[0].size();i++){
            int x = solve(grid,0,i,dp);
            ans.push_back(x);
            
        }
        return ans;
    }
};
