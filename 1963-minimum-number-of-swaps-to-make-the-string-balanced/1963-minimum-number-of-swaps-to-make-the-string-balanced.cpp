#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++){
            if( !st.empty() && st.top()=='[' && s[i]==']'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        if(st.empty()) return 0;
        else if(st.size()==2) return 1;
        else {
            if(st.size()%4==0) return st.size()/4;
            return st.size()/4  +1 ;
        }
        
    }
};