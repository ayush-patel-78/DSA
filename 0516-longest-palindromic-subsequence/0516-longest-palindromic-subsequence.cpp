class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s.begin(),s.end());
        string s2 = s;
        vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,0));
        for(int i=1;i<=s1.size();i++){
            for(int j = 1;j<=s1.size();j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int ans = dp[s.size()][s.size()];
        return ans;
        
    }
};