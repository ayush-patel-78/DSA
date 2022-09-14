class Solution {
public:
    int solve(vector<vector<int>>& grid,vector<vector<int>>& dp,int row,int col){
        if(row < 0 || col < 0) return 100000;
        if(row == 0 && col == 0) return dp[row][col]=grid[row][col];
        if(dp[row][col]!= -1) return dp[row][col];
        int ans1 ,ans2 ;
        ans1=solve(grid,dp,row-1,col)+grid[row][col];
        ans2=solve(grid,dp,row,col-1)+grid[row][col];
        return dp[row][col] = min(ans1,ans2);   
    }
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row,vector<int> (col,-1));
        solve(grid,dp,row-1,col-1);
        return dp[row-1][col-1];
    }
};