class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
         int row =  maze.size();
         int col = maze[0].size();
        
         queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(row,vector<int>(col,0));
        // Boundary Traversal 
         
         for(int j = 0,i=0;j<col;j++){
             if((i!=entrance[0] || j!=entrance[1])&&!vis[i][j] && maze[i][j]=='.'){
                 q.push({make_pair(i,j),0});
                 vis[i][j]=1;
                 
             }
         }
        
         for(int j=0,i=row-1;j<col;j++){
             if((i!=entrance[0] || j!=entrance[1])&&!vis[i][j]&& maze[i][j]=='.'){
                 q.push({make_pair(i,j),0});
                 vis[i][j]=1;
             }
         }
        
         for(int i = 0,j=0;i<row;i++){
             if((i!=entrance[0] || j!=entrance[1]) &&!vis[i][j]&& maze[i][j]=='.'){
                 q.push({make_pair(i,j),0});
                 vis[i][j]=1;
             }
         }
        
         for(int i = 0,j=col-1;i<row;i++){
             if((i!=entrance[0] || j!=entrance[1])&&!vis[i][j] && maze[i][j]=='.'){
                 q.push({make_pair(i,j),0});
                 vis[i][j]=1;
             }
         }
        int ans = INT_MAX;
        // cout<<q.size()<<endl;
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int dis = q.front().second;
            
            q.pop();
            // cout<<i<<" "<<j<<endl;
            if(i==entrance[0] && j==entrance[1]){
               
                if(dis < ans) ans = dis;
            }
            else{
                vector<int> rows = {+1,-1,0,0};
                vector<int> cols = {0,0,+1,-1};
                for(int k = 0;k< 4;k++){
                    if(i+rows[k]>=0 && i+rows[k] < row && j+cols[k] >= 0 && j+cols[k] < col &&!vis[i+rows[k]][j+cols[k]] && maze[i+rows[k]][j+cols[k]]=='.'){
                        vis[i+rows[k]][j+cols[k]]=1;
                        q.push({make_pair(i+rows[k],j+cols[k]),dis+1});
                    }
                }
               
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
         
    }
};