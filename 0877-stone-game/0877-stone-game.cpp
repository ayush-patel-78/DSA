class Solution {
public:
    int bob = 0;
    int alice = 0;
    int dp[501][501];
    int solve(vector<int>& piles,int i,int j,int count){
        if(i>j) return 0;
        if(i==j) return piles[i];
        if(dp[i][j] != -1) return dp[i][j];
        if(count%2==0){
            alice = max(piles[i] + solve(piles,i+1,j,count+1),piles[j] + solve(piles,i,j-1,count+1));
            return dp[i][j]=alice;
        }
        else{
            bob = max(piles[i] + solve(piles,i+1,j,count+1),piles[j] + solve(piles,i,j-1,count+1));
            return dp[i][j]=bob;
        }
        
    }
    bool stoneGame(vector<int>& piles) {
           memset(dp,-1,sizeof(dp));
           solve(piles,0,piles.size()-1,0);
           return alice > bob;
    }
};