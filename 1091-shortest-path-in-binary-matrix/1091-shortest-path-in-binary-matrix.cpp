class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        int n = grid.size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>>vis(n,vector<int>(n,0));
        vis[0][0]=1;
        q.push({make_pair(0,0),0});
        int ans = INT_MAX;
        while(!q.empty()){
            int i = q.front().first.first;
            int j= q.front().first.second;
            int dis = q.front().second;
            q.pop();
            if(i==n-1 && j==n-1){
                if(dis<ans) ans=dis;
            }
            for(int x=-1;x<2;x++){
                for(int y=-1;y<2;y++){
                    if(i+x>=0 && i+x <n && j+y >= 0 && j+y<n && !vis[i+x][j+y] && grid[i+x][j+y]==0){
                        vis[i+x][j+y]=1;
                        q.push({make_pair(i+x,j+y),dis+1});
                    }
                }
            }
        }
        if(ans==INT_MAX) return -1;
        return ans+1;
    }
};