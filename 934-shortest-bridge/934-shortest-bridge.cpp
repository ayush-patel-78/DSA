class Solution {
public:
    bool isNeighbourZero(vector<vector<int>>& grid,int i,int j){
         vector<int> rows={0,0,+1,-1};
        vector<int> cols ={+1,-1,0,0};
        for(int k=0;k<4;k++){
            if(i+rows[k]>=0 && i+rows[k]<grid.size() && j+cols[k]>=0 && j+cols[k]<grid[0].size() && grid[i+rows[k]][j+cols[k]]==0){
                return true;
            }
        }
        return false;
    }
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int i,int j,stack<pair<int,int>> & st){
        vis[i][j]=1;
        vector<int> rows={0,0,+1,-1};
        vector<int> cols ={+1,-1,0,0};
        
        for(int k=0;k<4;k++){
            if(i+rows[k]>=0 && i+rows[k]<grid.size() && j+cols[k]>=0 && j+cols[k]<grid[0].size() && !vis[i+rows[k]][j+cols[k]] && grid[i+rows[k]][j+cols[k]]==1){
                dfs(grid,vis,i+rows[k],j+cols[k],st);
            }
        }
        st.push({i,j});
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> vis(row,vector<int> (col,0));
        
        stack<pair<int,int>> st1;
        bool ck= false;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++){
                 if(!vis[i][j] && grid[i][j]==1){
                    dfs(grid,vis,i,j,st1);
                     ck=true;
                    break;
                }
            }
            if(ck) break;
        }
        // cout<<st1.size()<<endl;
        ck = false;
        stack<pair<int,int>> st2;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    dfs(grid,vis,i,j,st2);
                    ck = true;
                    break;
                }
            }
            if(ck) break;
        }
         // cout<<st2.size()<<endl;
        vector<pair<int,int>> vec1;
        while(!st1.empty()){
              int i = st1.top().first;
              int j = st1.top().second;
              if(isNeighbourZero(grid,i,j)){
                  vec1.push_back({i,j});
                  // cout<<i<<" "<<j<<endl;
              }
            st1.pop();
        }
        vector<pair<int,int>> vec2;
         while(!st2.empty()){
              int i = st2.top().first;
              int j = st2.top().second;
              if(isNeighbourZero(grid,i,j)){
                  vec2.push_back({i,j});
              }
             st2.pop();
        }
        int ans=INT_MAX;
        for(int x=0;x<vec1.size();x++){
            for(int y=0;y<vec2.size();y++){
                if(abs(vec1[x].first - vec2[y].first)+abs(vec1[x].second - vec2[y].second) < ans){
                    ans = abs(vec1[x].first - vec2[y].first)+abs(vec1[x].second - vec2[y].second);
                }
            }
        }
        
        return ans-1;
    }
};