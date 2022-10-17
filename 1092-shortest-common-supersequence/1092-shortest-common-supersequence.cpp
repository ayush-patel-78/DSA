class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string s;
        int i = n;
        int j = m;
      while(i>0 && j>0){
          if(str1[i-1] == str2[j-1]){
              s.push_back(str1[i-1]);
              i--;
              j--;
          }
          else{
              if(dp[i-1][j] > dp[i][j-1]){
                  s.push_back(str1[i-1]);
                  i--;
              }else{
                  s.push_back(str2[j-1]);
                  j--;
              } 
          }
      }
      while(i>0){
          s.push_back(str1[i-1]);
          i--;
      }
      while(j>0){
          s.push_back(str2[j-1]);
          j--;
      }
      reverse(s.begin(),s.end());
        return s;
        
    // my version little bit extended approach 
      //   i = 0;
      //   j = 0;
      //   int k = 0;
      //   string ans;
      // while(i<n || j<m){
      //     if(str1[i]==str2[j] && str1[i]==s[k]){
      //         ans.push_back(s[k]);
      //         i++;
      //         j++;
      //         k++;
      //     }
      //     if(i<n && str1[i] != s[k]){
      //         ans.push_back(str1[i]);
      //         i++;
      //     }
      //     if(j<m && str2[j] != s[k]){
      //         ans.push_back(str2[j]);
      //         j++;
      //     }
      // }
      // return ans;
    }
};