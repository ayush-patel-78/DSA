class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int> mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            mpp[t[i]]--;
        }
        for(auto x:mpp){
            if(x.second != 0) return false;
        }
        return true;
        
    }
};