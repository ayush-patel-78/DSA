class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        
        vector<vector<int>> ans(row,vector<int>(col)) ;
        for(int i=0;i<row;i++){
            vector<int> tem;
            for(int j=i,k=0;j<row && k<col;j++,k++){
                  tem.push_back(mat[j][k]);
            }
            sort(tem.begin(),tem.end());
            for(int j=i,k=0,z=0;j<row && k<col;j++,k++,z++){
                  ans[j][k]=tem[z];
            }
        }
        for(int i=1;i<col;i++){
            vector<int> tem;
            for(int j=0,k=i;j<row && k<col;j++,k++){
                  tem.push_back(mat[j][k]);
            }
            sort(tem.begin(),tem.end());
            for(int j=0,k=i,z=0;j<row && k<col;j++,k++,z++){
                  ans[j][k]=tem[z];
            }
        }
        return ans;
    }
};