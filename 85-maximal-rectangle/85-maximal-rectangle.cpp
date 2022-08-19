class Solution {
public:
    int mah(vector<int> & heights){
        vector<int> left;
        int n = heights.size();
        stack<pair<int,int>> ls;
        for(int i=0;i<n;i++){
            int curr = heights[i];
            while(!ls.empty()){
                int upper = ls.top().first;
                int index = ls.top().second;
                if(upper < curr){
                    left.push_back(index);
                    break;
                }
                else{
                    ls.pop();
                }
            }
            if(ls.empty()){
                left.push_back(-1);
            }
            ls.push({curr,i});
        }
        
        vector<int> right(n);
        stack<pair<int,int>> rs;
        for(int i=n-1;i>=0;i--){
            int curr = heights[i];
            while(!rs.empty()){
                int upper = rs.top().first;
                int index = rs.top().second;
                if(upper < curr){
                    right[i]=index;
                    break;
                }
                else{
                    rs.pop();
                } 
            }
            if(rs.empty()){
                right[i]=n;
            }
            rs.push({curr,i});
        }
        
        vector<long long int> area;
        long long int maximum_area = 0;
        
        for(int i=0;i<n;i++){
            long long int ar = (right[i]-left[i]-1)*heights[i];
            area.push_back(ar);
            if(ar > maximum_area) maximum_area = ar;
        }
        // cout<<maximum_area<<endl;
        return maximum_area;
        
    }
    int maximalRectangle(vector<vector<char>>& str) {
        vector<vector<int>> matrix;
        for(int i=0;i<str.size();i++){
            vector<int> m;
            for(int j=0;j<str[0].size();j++){
                if(str[i][j]=='0') m.push_back(0);
                else m.push_back(1);
            }
            matrix.push_back(m);
        }
        // for(auto x:matrix){
        //     for(auto y:x){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int ans = mah(matrix[0]);
        
        for(int i=1 ; i < rows ; i++){
            for( int j = 0 ;j<cols;j++){
                if(matrix[i][j]==1)
                    matrix[i][j] = matrix[i][j]+matrix[i-1][j]; 
                else matrix[i][j]=0;
                
                // cout<<matrix[i][j]<<" ";
            }
            // cout<<endl;
            
            ans = max(ans,mah(matrix[i]));
        }
        return ans;
    }
};