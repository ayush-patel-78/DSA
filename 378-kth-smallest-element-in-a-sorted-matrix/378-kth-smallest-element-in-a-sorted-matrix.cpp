class Solution {
public:
    
    // 1st approach mine
    // int kthSmallest(vector<vector<int>>& matrix, int k) {
    //   priority_queue<int> pq;
    //     for(int i=0;i<matrix.size();i++){
    //         for(int j=0;j<matrix.size();j++){
    //             if(pq.size()<k){
    //                 pq.push(matrix[i][j]);
    //             }
    //             else{
    //                 pq.push(matrix[i][j]);
    //                 pq.pop();
    //             }
    //         }
    //     }
    //     return pq.top();
    // }
    
    // better approach nested binary search
    
    int kthSmallest(vector<vector<int>>& matrix,int k) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        int startVal = matrix[0][0];
        int endVal = matrix[row-1][col-1];
        int midVal;
        
        while(startVal <= endVal){
            midVal = (startVal + endVal)/2;
            int ans = 0;
            for(int i=0;i<row;i++){
                int low = 0;
                int high = col -1;
                int m;
                while(low <= high){
                    m = (low + high)/2;
                    if(matrix[i][m] <= midVal) low = m+1;
                    else high = m-1;
                }
                ans += low;  
            }
            if(ans < k) startVal = midVal +1;
            else endVal = midVal -1;
        }
        return startVal;
    }
};