class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      priority_queue<int> pq;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                if(pq.size()<k){
                    pq.push(matrix[i][j]);
                }
                else{
                    pq.push(matrix[i][j]);
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};