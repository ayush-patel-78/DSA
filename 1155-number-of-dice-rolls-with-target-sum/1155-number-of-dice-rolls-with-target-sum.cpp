#define ll long long
class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int n,int k,int target,int curr_sum,int dice,vector<vector<int>>& dp){
        if(curr_sum == target && dice==n) return 1;
        if(curr_sum > target) return 0;
        if(dice==n) return 0;
        if(dp[dice][curr_sum] != -1) return dp[dice][curr_sum];
        ll ways = 0;
        for(int i=1;i<=k;i++){
            ways += solve(n,k,target,curr_sum+i,dice+1,dp);
        }
        return dp[dice][curr_sum]=ways%mod;
        
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(1001,-1));
        return solve(n,k,target,0,0,dp);
    }
};