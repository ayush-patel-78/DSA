class Solution {
public:
    bool isMatching(string word,string pattern){
        if(word.size()!=pattern.size()) return false;
        unordered_map<char,char> mpp;
        unordered_map<char,char>mp;
        for(int i=0;i<pattern.size();i++){
            if(mpp.find(pattern[i]) == mpp.end() && mp.find(word[i])==mp.end()){
                mpp[pattern[i]]=word[i];
                mp[word[i]]=pattern[i];
            }
            else if(mpp[pattern[i]]==word[i]) continue;
            else return false;
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
         vector<string> ans;
        for(auto word:words){
            if(isMatching(word,pattern)) ans.push_back(word);
        }
        return ans;
    }
};