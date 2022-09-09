// class comparator{
//     public:
//     bool operator()(vector<int>const& v1,vector<int>const& v2){
//         if(v1[1]>v2[1]) return true;
//         else if(v1[1]==v2[1] && v1[0]>v2[0]) return true;
//         return false;
//     }
// };
// class Solution {
// public:
//     bool static compare(vector<int>& v1,vector<int>& v2){
//         if(v1[0]<v2[0]) return true;
//         else if(v1[0]==v2[0] && v1[1]>v2[1]) return true;
//         return false;
//     }
//     int numberOfWeakCharacters(vector<vector<int>>& properties) {
//         sort(properties.begin(),properties.end(),compare);
              
//         int count = 0;
//         long long max_def = INT_MIN;
//         for(int i=properties.size()-1;i>=0;i--){
//             if(properties[i][1]< max_def ) count++;
//             else{
//                 max_def = properties[i][1];
//             }
            
//         }
//         return count;
//     }
// };

class Solution {
public:
    void primt(const vector<vector<int>>& prop){
        for(auto x:prop){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<endl;
        }
    }
        
    void surt(vector<vector<int>>& prop){
    std::sort(prop.begin(), prop.end(),[](auto const &a, auto const &b) { return a[1] < b[1]; });
    }
    
    void calc(vector<vector<int>>& mat, int& ans){
        int max1 = 0;
        int max2 = 0;
        int max1_ = 0;
        int max2_ = 0;
        
        for(int i = mat.size()-1; i>=0; i--){
            if(max1 < mat[i][0]){
                if(max2 != mat[i][1]){
                    max1_ = max1;
                    max2_ = max2;
                }
                
                max1 = mat[i][0];
                max2 = mat[i][1];               
            }
            if(max1 > mat[i][0] && max2 > mat[i][1]){
                ans++;
                cout<<mat[i][0]<<" "<< mat[i][1]<<" < ";
            }
            else if(max2== mat[i][1]){ 
                if(max1_ > mat[i][0] && max2_ > mat[i][1]){
                ans++;
                // cout<<mat[i][0]<<" "<< mat[i][1]<<" < "<< "max_:"<<max1_<<","<<max2_<<endl;
                }
                // cout<< "max_:"<<max1_<<","<<max2_<<endl;
            }
            // else cout<<mat[i][0]<<" "<< mat[i][1]<<" * ";
            // cout<< "max:"<<max1<<","<<max2<<endl;
        }
               
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int ans = 0;
        surt(properties);
        // primt(properties);
        
        cout<<"=========="<<endl;
        
        calc(properties,ans);
        return ans;
    }
};
