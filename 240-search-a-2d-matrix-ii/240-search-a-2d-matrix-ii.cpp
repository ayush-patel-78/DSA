class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            if(matrix[i][0]<= target && matrix[i][n-1]>=target){
                int start = 0;
                int end = n-1;
                while(start <= end){
                    int mid = start + (end - start)/2;
                    if(matrix[i][mid] == target){
                        return true;
                    }
                    else if(matrix[i][mid]> target){
                        end = mid - 1;
                    }
                    else if(matrix[i][mid]<target){
                        start = mid + 1;
                    }
                }
            }
        }
        return false;
    }
};