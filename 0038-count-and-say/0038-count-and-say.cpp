class Solution {
public:
    string solve(int n,string s,int i){
        if(i>n) return s;
        if(i==1){
            return solve(n,"1",i+1);
        }
        string str;
        int count = 1;
        char prev = s[0];
        stack<char> st;
        vector<int> vec;
        vector<char> vec2;
        for(int i=1;i<s.size();i++){
            if(prev == s[i]){
                count++;
            }
            else{
                vec.push_back(count);
                count = 1;
                prev = s[i];
                vec2.push_back(s[i-1]);
            }
        }
        vec.push_back(count);
        vec2.push_back(s[s.size()-1]);
        
        for(int i=0;i<vec.size();i++){
            int x = vec[i];
            while(x>0){
                int rem = x%10;
                x = x/10;
                char h = char (rem + 48);
                st.push(h);
            }
            while(!st.empty()){
                str.push_back(st.top());
                st.pop();
            }
            str.push_back(vec2[i]);
        }
        return solve(n,str,i+1);
    }
    string countAndSay(int n) {
        return solve(n,"",1);
    }
};