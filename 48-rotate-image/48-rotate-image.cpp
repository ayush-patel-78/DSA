class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // first step do the transpose of a matrix 
        for(int i=0;i<matrix.size();i++){
            for(int j=i;j<matrix.size();j++){
                if(i!=j){
                    int temp = matrix[i][j];
                    matrix[i][j]=matrix[j][i];
                    matrix[j][i]=temp;
                    
                }
            }
        }
        // second step reverse the first element with last element in a row and 2nd element with last 2nd element and so on...
        int low=0;
        int high=matrix.size()-1;
        for(int i=0;i<matrix.size();i++){
            for(low=0,high=matrix.size()-1 ;low<high;low++,high--){
                int temp=matrix[i][low];
                matrix[i][low]=matrix[i][high];
                matrix[i][high]=temp;
                
            }
        }
        
    }
};