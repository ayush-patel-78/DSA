#define ll long long
class Solution {
public:
    int memo[51][51][51];
    ll mod = 1e9 + 7;
    ll dfs(int m, int n, int maxMove, int startRow, int startColumn) {
       if((startRow<0) || (startRow>=m) || startColumn<0 || startColumn>=n)        {
           return 1;   
       }
       if(maxMove<=0){
           return 0;
       }
        ll res = 0;
        if(memo[startRow][startColumn][maxMove] != -1){
            return memo[startRow][startColumn][maxMove]; 
        }
        
            res+=dfs(m,n,maxMove-1,startRow+1,startColumn);
            res+=dfs(m,n,maxMove-1,startRow-1,startColumn);
            res+=dfs(m,n,maxMove-1,startRow,startColumn+1);
            res+=dfs(m,n,maxMove-1,startRow,startColumn-1);
            
           return memo[startRow][startColumn][maxMove] = res%mod;
      
        
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
       ll count = 0;
        
        memset(memo,-1,sizeof(memo));
        return dfs(m,n,maxMove,startRow,startColumn);
      
    }
};