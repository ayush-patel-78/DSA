class Solution {
public:
    int solve(int n,vector<int>&dp){
        int ans=0;
        if(n==0) return 1;
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        
        ans+=solve(n-1,dp);
        ans+=solve(n-2,dp);
        return dp[n]=ans;
        
        
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};