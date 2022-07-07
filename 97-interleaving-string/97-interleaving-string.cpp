class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        vector<vector<bool>>dp(s1.size()+1,vector<bool>(s2.size()+1));
        dp[0][0]=true;
        for(int i=1;i<s1.size()+1;i++){
            if(s1[i-1]==s3[i-1]){
                dp[i][0]=dp[i-1][0];
            }
            else dp[i][0]=false;
        }
        for(int j=1;j<s2.size()+1;j++){
            if(s2[j-1]==s3[j-1]) dp[0][j]=dp[0][j-1];
            else dp[0][j]=false;
        }
        for(int i=1;i<s1.size()+1;i++){
            for(int j=1;j<s2.size()+1;j++){
                if(s1[i-1]==s3[i+j-1] && s2[j-1]==s3[i+j-1]){
                    if(dp[i-1][j]==true ||dp[i][j-1]==true){
                        dp[i][j]=true;
                    }
                    else dp[i][j]=false;
                }
                else if(s1[i-1]==s3[i+j-1]){
                    dp[i][j]=dp[i-1][j];
                }
                else if(s2[j-1]==s3[i+j-1]){
                    dp[i][j]=dp[i][j-1];
                }
                else dp[i][j]=false;
            }
        }
        return dp[s1.size()][s2.size()];
        
    }
};