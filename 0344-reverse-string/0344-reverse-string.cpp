class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i=0,j=s.size()-1;i<j;i++,j--){
            char x = s[i];
            s[i]=s[j];
            s[j]=x;
        }
    }
};