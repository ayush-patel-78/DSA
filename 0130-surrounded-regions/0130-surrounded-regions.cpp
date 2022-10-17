class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<int>>& vis,int i,int j){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()) return;
        if(vis[i][j]==1 || board[i][j]=='X') return;
        vis[i][j]=1;
        dfs(board,vis,i+1,j);
        dfs(board,vis,i,j+1);
        dfs(board,vis,i-1,j);
        dfs(board,vis,i,j-1);
        
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(!vis[i][0]);
            dfs(board,vis,i,0);
        }
        for(int i=0;i<n;i++){
            if(!vis[i][m-1]);
            dfs(board,vis,i,m-1);
        }
        for(int i=0;i<m;i++){
            if(!vis[0][i]);
            dfs(board,vis,0,i);
        }
        for(int i=0;i<m;i++){
            if(!vis[n-1][i]);
            dfs(board,vis,n-1,i);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
    }
};