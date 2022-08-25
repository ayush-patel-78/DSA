class Solution {
public:
    int solve(int n,vector<int>&dp){
        int ans=0;
        if(n==2) return 2;
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        
        ans+=solve(n-1,dp);
        ans+=solve(n-2,dp);
        return dp[n]=ans;
        
        
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
        // if(n==1)return 1;
        // dp[0]=0;
        // dp[1]=1;
        // dp[2]=2;
        // for(int i=3;i<=n;i++){
        //     dp[i]=dp[i-1]+dp[i-2];
        // }
        // return dp[n];
      
    }
};