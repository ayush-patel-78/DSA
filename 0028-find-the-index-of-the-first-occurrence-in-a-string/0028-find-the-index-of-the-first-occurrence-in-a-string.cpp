class Solution {
public:
    int strStr(string haystack, string needle) {
        unordered_set<string> st;
        st.insert(needle);
        if(needle.size() > haystack.size()) return -1;
        int i = 0;
        int j = 0;
        string s;
        int n = needle.size();
        for(i=0;i<n;i++){
            s += haystack[i];
        }
        if(st.find(s) != st.end()){
                return i - n;
        }
        for( ;i<haystack.size();i++ ){
            s.erase(0,1);
            s+=haystack[i];
             if(st.find(s) != st.end()){
                return i+1 - n;
             }
            
        }
        return -1;
    }
};