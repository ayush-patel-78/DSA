class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        set<vector<int>> st;
        for(int i=0;i<logs.size();i++){
            st.insert(logs[i]);
        }
        map<int,int> mpp;
        for(auto x:st){
            mpp[x[0]]++;
        }
        map<int,int> ans;
        for(auto y:mpp){
            ans[y.second]++;
        }
        vector<int> v(k,0);
        for(auto z:ans){
            v[z.first-1]=z.second;
        }
        return v;
    }
};