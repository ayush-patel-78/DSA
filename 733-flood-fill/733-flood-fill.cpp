class Solution {
public:
    void dfs(vector<vector<int>>& image,vector<vector<int>>& vis ,int sr, int sc, int color,int clr_strt){
        if(vis[sr][sc]==1 || image[sr][sc]!=clr_strt) return ;
        image[sr][sc]=color;
        vis[sr][sc]=1;
        vector<int> rows = {-1,0,+1,0};
        vector<int> cols = {0,-1,0,+1};
        for(int i=0;i<4;i++){
            if(sr+rows[i] >=0 && sr+rows[i] < image.size() && sc+cols[i] >= 0 && sc+cols[i]< image[0].size() && vis[sr+rows[i]][sc+cols[i]]==0){
                dfs(image,vis,sr+rows[i],sc+cols[i],color,clr_strt);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();
        vector<vector<int>> vis(row,vector<int>(col,0));
        dfs(image,vis,sr,sc,color,image[sr][sc]);
        return image;
    }
};