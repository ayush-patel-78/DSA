class Solution {
public:
    bool static compare(pair<int,int>& p1,pair<int,int>&p2){
        return p1.second>p2.second;
    }
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mpp;
        vector<pair<int,int>> v;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        for(auto x:mpp){
            v.push_back({x.first,x.second});
        }
        sort(v.begin(),v.end(),compare);
        int half = arr.size()/2;
        unordered_set<int> st;
        int count = 0;
        for(int i=0;i<v.size();i++){
            count+=v[i].second;
            if(count >= half){
                st.insert(v[i].first);
                break;
            }
            st.insert(v[i].first);
        }
        return st.size();
    }
    
};