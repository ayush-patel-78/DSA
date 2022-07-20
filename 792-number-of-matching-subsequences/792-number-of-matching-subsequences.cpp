class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
     
        int n = words.size();
        int count=0;
        unordered_map<char,vector<int>> mpp;
        unordered_map<char,vector<int>>::iterator it;
        for(int i=0;i<s.size();i++){
            mpp[s[i]].push_back(i);
        }
        int index = -1;
        for(int i=0;i<n;i++){
            int j = 0;
            index = -1;
            for(j=0;j<words[i].size();j++){
                if(mpp.find(words[i][j])!=mpp.end()){
                    it = mpp.find(words[i][j]);
                    int k=0;
                    for(k = 0;k<it->second.size();k++){
                        if(it->second[k]>index){
                            index = it->second[k];
                            break;
                        }
                    }
                    if(k==it->second.size()){
                        break;
                    }
                }
                else{
                    break;
                }
            }
            if(j==words[i].size()){
                count++;
            }
        }
        return count;
    }
};