class Solution {
public:
    int dp[1001];
    int solve(int k,int n){
        if(k==1 || n==1 ||n==0) return n;
        if(dp[n] != -1) return dp[n];
        int ans = INT_MAX;
        for(int z = 1;z<=n;z++){
            int temp = 1 + max(solve(k-1,z-1) , solve(k,n-z));
            ans = min(ans,temp);
        }
        return dp[n] = ans;
    }
    int twoEggDrop(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(2,n);
    }
};