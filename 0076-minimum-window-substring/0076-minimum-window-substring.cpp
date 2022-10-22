class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mpp;
       
        int required = 0;
        for(int i=0;i<t.size();i++){
            mpp[t[i]]++;
            required++;
        }
        vector<char> curr;
        int ans_size = INT_MAX;
        int j=0;
        int i=0;
        int formed = 0;
        int ans_i = 0;
        int ans_j = 0;
        bool check = false;
        while(j<s.size()){
            curr.push_back(s[j]);
            if(mpp.find(s[j]) != mpp.end()){
                mpp[s[j]]--;
                if(mpp[s[j]]>=0) formed++;
            }
            while(formed == required){
                if(j-i+1 < ans_size){
                    ans_size = j-i+1;
                    ans_i = i;
                    ans_j = j;
                    check = true;
                }
                if(mpp.find(s[i]) != mpp.end()){
                    mpp[s[i]]++;
                    if(mpp[s[i]]>0) formed--;
                }
                i++;
            }
            j++;
        }
        string ans = "";
        if(check){
            for(int x = ans_i;x<=ans_j;x++){
               ans += s[x];
            }
        }
        
        return ans;
    }
};