class Solution {
public:
    int firstUniqChar(string s) {
      unordered_map<char,pair<int,int>> mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]].first++;
            mpp[s[i]].second = i;
        }
        int minimum = INT_MAX;
        for(auto x:mpp){
          if(x.second.first==1 && x.second.second < minimum)
              minimum = x.second.second;
        }
        if(minimum==INT_MAX) return -1;
        return minimum;
    }
};