class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j){
        if(i==grid.size()){
           return j;
           
        }
        int x = grid[i][j];
        if(j==grid[0].size()-1 && x==1 ) return -1;
        if(j==0 && x==-1) return -1;
        int ans = -1;
        if(x==1 && grid[i][j+1]==1){
            ans = solve(grid,i+1,j+1);
        }
        else if(x==-1 && grid[i][j-1]==-1){
            ans = solve(grid,i+1,j-1);
        }
        return ans;
        
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        for(int i=0;i<grid[0].size();i++){
            int x = solve(grid,0,i);
            ans.push_back(x);
            
        }
        return ans;
    }
};

// [[1,1,1,-1,-1],
//  [1,1,1,-1,-1],
//  [-1,-1,-1,1,1],
//  [1,1,1,1,-1],
//  [-1,-1,-1,-1,-1]]