#define ll long long
class Solution {
public:
    int help(vector<int>& cost,int n,int index,vector<ll>& dp){
        if(index>=n){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        ll ans1 = help(cost,n,index+1,dp);
        ll ans2 = help(cost,n,index+2,dp);
        dp[index]=cost[index]+min(ans1,ans2);
        return dp[index];
    }
    int minCostClimbingStairs(vector<int>& cost) {
       int n = cost.size();
        vector<ll> dp(n,-1);
        ll ans1 = help(cost,n,0,dp);
        ll ans2 = help(cost,n,1,dp);
        return min(dp[0],dp[1]);
    }
};