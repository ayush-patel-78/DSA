#define ll long long
class Solution {
public:
    int countVowelPermutation(int n) {
         ll mod = 1e9 +7;
        vector<vector<ll>> dp(n+1,vector<ll>(5));
        int a=0,e=1,i=2,o=3,u=4;
        for(int j=0;j<5;j++){
            dp[1][j]=1;
        }
        for(int j=2;j<n+1;j++){
            dp[j][a]=(dp[j-1][e] + dp[j-1][i] + dp[j-1][u]) % mod;
            dp[j][e]=(dp[j-1][a]+dp[j-1][i]) % mod;
            dp[j][i]=(dp[j-1][e]+dp[j-1][o]) % mod;
            dp[j][o]=dp[j-1][i];
            dp[j][u]=(dp[j-1][o]+dp[j-1][i])%mod;
        }
        int ans = (dp[n][a]+dp[n][e]+dp[n][i]+dp[n][o]+dp[n][u])%mod;
        return ans;
    }
};