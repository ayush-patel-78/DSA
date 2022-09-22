class Solution {
public:
    string reverseWords(string s) {
        string ans ="";
        string small ="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                reverse(small.begin(),small.end());
                ans += small;
                ans+= s[i];
                small ="";
            }
            else{
                small += s[i];
            }
        }
        reverse(small.begin(),small.end());
        ans+= small;
        return ans;
    }
};