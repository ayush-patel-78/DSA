class Solution {
public:
    int dp[301][11][1001];
    int solve(vector<int>& jd,int d,int i,int md){
        if(i==jd.size() && d==0) return md;
        if(jd.size()-i < d) return INT_MAX;
        if(dp[i][d][md] != -1) return dp[i][d][md];
        int ans = INT_MAX;
        if(jd[i] > md) md = jd[i];
        if(d>0){
            ans = md + solve(jd,d-1,i+1,0);
        }
        int ans2 = solve(jd,d,i+1,md);
        return dp[i][d][md] = min(ans,ans2);
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(d > jobDifficulty.size()) return -1;
        memset(dp,-1,sizeof(dp));
        return solve(jobDifficulty,d,0,0);
    }
};