class Solution {
public:
    int solve(vector<int>& prices,int index,int isbuy,int transaction,vector<vector<vector<int>>>& dp){
        if(transaction == 0 || index == prices.size()) return 0;
        int ans1 = 0;
        int ans2 = 0;
        if(dp[isbuy][transaction][index] != -1) return dp[isbuy][transaction][index];
        if(isbuy==1){
            ans1 = solve(prices,index+1,0,transaction,dp)-prices[index];
            ans2 = solve(prices,index+1,1,transaction,dp);
        }
        else{
            ans1 = solve(prices,index+1,1,transaction-1,dp)+prices[index];
            ans2 = solve(prices,index+1,0,transaction,dp);
        }
        
        return dp[isbuy][transaction][index]=max(ans1,ans2);
        
    }
    int maxProfit(int k, vector<int>& prices) {
        int isbuy = 1;
        int transaction = k;
        
        vector<vector<vector<int>>> dp(2,vector<vector<int>>(k+1,vector<int>(prices.size()+1,-1)));
        int ans = solve(prices,0,isbuy,transaction,dp);
        dp.clear();
        return ans;
    }
};