class Solution {
public:
    bool checkIfPangram(string s) {
        unordered_map<int,int> mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(mpp[i]==0) return false;
        }
        return true;
    }
};