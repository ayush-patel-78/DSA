class Solution {
public:
    int dp[101][101];
    int solve(vector<vector<int>>& og,int i,int j){
        if(i<0 || i>= og.size() || j<0 || j>= og[0].size()) return 0;
        if(i==og.size()-1 && j == og[0].size()-1) return 1;
        int count = 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(og[i][j] == 0){
           count += solve(og,i+1,j);
           count += solve(og,i,j+1);
        }
        return dp[i][j] = count;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp,-1,sizeof(dp));
        if(obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1]==1)return 0;
         return solve(obstacleGrid,0,0);
        
    }
};

// 0 0 0 0
// 0 1 0 0
// 0 0 0 0
// 0 0 1 0
// 0 0 0 0
