class Solution {
public:
    int path(int i,int j,int m,int n,vector<vector<int>>& dp){
        if(i>=m || j>=n){
            return 0;
        }
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        else{
            dp[i][j]=path(i+1,j,m,n,dp)+path(i,j+1,m,n,dp);
            return dp[i][j];
        }
        
        
    }
    int uniquePaths(int m, int n) {
        
        // 1st approach dynamic programming
        // int ways=0;
        // int i=0,j=0;
       
        // vector<vector<int>> dp;
        // dp = vector<vector<int>>(m,vector<int>(n,-1)); 
        
        // ways = path(i,j,m,n,dp);
        // return ways;
        
        //2nd approach formula based  
        // total number of steps we have to travel is (no.of rows - 1) + (number of cols -1)
        // number of down steps we have to take out of total steps is calculated by ncr               //(permutation and combination) formula here n is total steps and r is no. of down steps.
        
        // or 
        
        // we can also calculate number of right steps we have to take from total steps by using the same formula ncr . here n is total steps and r is no. of right steps.
        
        
        // calculating ncr ;
        int total_steps = (m-1)+(n-1);  //total steps required to reach finish 
        int down_steps = m-1;
        double res=1;
        for(int i=1;i<=m-1;i++){
             res = res*(total_steps-down_steps+i)/i;
        }
        return (int)res;
        
    }
};