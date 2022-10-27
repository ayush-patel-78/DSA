class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>> image1;
        vector<pair<int,int>> image2;
        
        for(int i=0;i<img1.size();i++){
            for(int j=0;j<img1.size();j++){
                if(img1[i][j]==1){
                    image1.push_back({i,j});
                }
                if(img2[i][j]==1){
                    image2.push_back({i,j});
                }
            }
        }
        int ans = 0;
        map<pair<int,int>,int> mpp;
        for(auto [i1,j1]:image1){
            for(auto [i2,j2]:image2){
                mpp[{i1-i2,j1-j2}]++;
                ans = max(ans,mpp[{i1-i2,j1-j2}]);
            }
        }
        return ans;
    }
};