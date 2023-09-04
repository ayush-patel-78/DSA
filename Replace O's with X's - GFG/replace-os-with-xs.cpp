//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    vector<int> row = {1,-1,0,0};
    vector<int> col = {0,0,1,-1};
    
    void solve(int i,int j,vector<vector<char>>& mat,vector<vector<int>>& vis){
        if(i<0 || i>= mat.size() || j<0 || j>=mat[0].size() || vis[i][j]==1 || mat[i][j]!='O') return;
        vis[i][j]=1;
        mat[i][j]='Y';
       
        for(int k=0;k<4;k++){
            solve(i+row[k],j+col[k],mat,vis);
        }
        return;
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(mat[0][i]=='O')  solve(0,i,mat,vis);
            if(mat[n-1][i]=='O') solve(n-1,i,mat,vis);
        }
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O') solve(i,0,mat,vis);
            if(mat[i][m-1]=='O') solve(i,m-1,mat,vis);
             
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='Y') mat[i][j]='O';
                else mat[i][j]='X';
            }
        }
        return mat;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends