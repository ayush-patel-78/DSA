class Solution {
public:
    int longestValidParentheses(string s) {
        int maximum1 = 0;
        int curr1 = 0;
        stack<int> st;
        st.push(-1);
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                    
                }
                else{
                    curr1 = i-st.top();
                }
               
            }
            if(curr1 > maximum1 ) maximum1=curr1;
        }
        
        
        return maximum1;
    }
};