class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({make_pair(i,j),0});
                }
            }
        }
        int ans = 0;
        while(!q.empty()){
            int i=q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            q.pop();
            vector<int> row = {-1,+1,0,0};
            vector<int> col = {0,0,+1,-1};
            if(time > ans) ans = time;
            for(int k=0;k<4;k++){
                if(i + row[k] >=0 && i+row[k]<grid.size() && j+col[k] >=0 && j+col[k] <grid[0].size() && grid[i+row[k]][j+col[k]]==1){
                    grid[i+row[k]][j+col[k]]=2;
                    q.push({make_pair(i+row[k],j+col[k]),time + 1});
                }
            }
            
        }
        
        for(int i=0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;

    }
};