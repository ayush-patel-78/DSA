class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int i = 0;
        int j = 0;
        for(int k=0;k<matrix.size();k++){
            i = k;
            j=0;
            int x = matrix[i][j];
            while(i<matrix.size() && j<matrix[0].size()){
                if(matrix[i][j] != x) return false;
                i++;
                j++;
            }
        }
        for(int k=1;k<matrix[0].size();k++){
            i=0;
            j=k;
            int x = matrix[i][j];
             while(i<matrix.size() && j<matrix[0].size()){
                if(matrix[i][j] != x) return false;
                i++;
                j++;
            }
        }
        return true;
    }
};