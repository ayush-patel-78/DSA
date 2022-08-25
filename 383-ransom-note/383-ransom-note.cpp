class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
         unordered_map<char,int> ransom;
         unordered_map<char,int> mag;
        for(int i=0;i<ransomNote.size();i++){
            ransom[ransomNote[i]]++;
        }
         for(int i=0;i<magazine.size();i++){
            mag[magazine[i]]++;
        }
        for(auto x:ransom){
            if(x.second > mag[x.first]){
                return false;
            }
        }
        return true;
    }
};