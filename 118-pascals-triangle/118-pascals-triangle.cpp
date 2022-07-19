class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vec;
        for(int i=1;i<=numRows;i++){
           vector<int> v1(i,1);
            for(int j=1;j<v1.size();j++){
                if(j<vec[i-2].size()){
                    v1[j]=vec[i-2][j-1]+vec[i-2][j];
                 
                }
                // v1[j]=1;
                
            }
            vec.push_back(v1);
            
        }
      return vec;  
    }
};