class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
         vector<string> ans;
         vector<unordered_map<char,int>> v;
        
        for(int j=0;j<words2.size();j++){
            unordered_map<char,int> mpp;
            for(int k=0;k < words2[j].size();k++){
                mpp[words2[j][k]]++;
            }
            v.push_back(mpp);
        }
        unordered_map<char,int> hehe;
        for(int i=0;i<v.size();i++){
            for(auto x:v[i]){
                if(hehe.find(x.first)==hehe.end()){
                    hehe[x.first]=x.second;
                }
                else{
                    if(x.second > hehe[x.first]){
                        hehe[x.first]=x.second;
                    }
                }
            }
        }
        
        // for(int j=0;j<words2.size();j++){
        //     unordered_map<char,int> mpp;
        //     for(int k=0;k<words2[j].size();k++){
        //         mpp[words2[j][k]]++;
        //     }
        //     v.push_back(mpp);
        // }
        for(int i=0;i<words1.size();i++){
            bool check = true;
            unordered_map<char,int> mpp1;
            for(int j=0;j<words1[i].size();j++){
                mpp1[words1[i][j]]++;
            }
            
            for(auto x:hehe){
                if(mpp1.find(x.first)==mpp1.end() || mpp1[x.first] < x.second){
                    check = false;
                    break;
                }
            }
            if(check){
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
};