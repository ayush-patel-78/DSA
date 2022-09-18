#define ll long long
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        bool check1 = true;
        bool check0 = true;
        queue<pair<pair<int,int>,int>> que;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==0){
                    check1 = false;
                }
                if(grid[i][j]==1){
                    check0 = false;
                    que.push({make_pair(i,j),0});
                }
            }
           
        }
        if(check1 || check0) return -1;
        
        int dis = 0;
        int curr_dis=0;
        while(!que.empty()){
            int i = que.front().first.first;
            int j = que.front().first.second;
            
            curr_dis = que.front().second;
            que.pop();
            vector<int> rows = {+1,-1,0,0};
            vector<int> cols = {0,0,+1,-1};
            
            for(int k=0;k<4;k++){
                if(i+rows[k]>=0 && i+rows[k]<row && j+cols[k]>=0 && j+cols[k]<col && grid[i+rows[k]][j+cols[k]]==0){
                    grid[i+rows[k]][j+cols[k]]=1;
                    que.push({make_pair(i+rows[k],j+cols[k]),curr_dis+1});
                }
            }
        }
        return curr_dis;
        
        
    }
};