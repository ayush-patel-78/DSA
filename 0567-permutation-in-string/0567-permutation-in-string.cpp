class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        map<char,int> mpp;
        for(int i=0;i<k;i++){
            mpp[s1[i]]++;
        }
        int i=0;
        int j=0;
        while(j<s2.size()){
            if(mpp.find(s2[j])!=mpp.end()){
                mpp[s2[j]]--;
            }
            if(j-i+1 == k){
                bool check = true;
                for(auto x:mpp){
                    if(x.second != 0){
                        check = false;
                        break;
                    }
                }
                if(check) return true;
                if(mpp.find(s2[i])!=mpp.end()){
                    mpp[s2[i]]++;
                }
                i++;
            }
            j++;
        }
        return false;
    }
};