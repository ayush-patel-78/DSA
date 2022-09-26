class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st(deadends.begin(),deadends.end());
        string start = "0000";
        queue<pair<string,int>> q;
        unordered_map<string,int> mp; 
        mp[start]=1;
        q.push({start,0});
        if(st.find(start) != st.end()) return -1;
        vector<char> v={'0','1','2','3','4','5','6','7','8','9'};
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            // cout<<word<<" ";
            if(word == target) return steps;
            string original = word;
            q.pop();
             for(int i=0;i<4;i++){
                
                if(word[i]=='9') word[i]='0';
                else word[i]++;
                if(st.find(word)==st.end() && mp.find(word)==mp.end()){
                        mp[word]=1;
                        q.push({word,steps +1});
                }
                word = original;
            }
            for(int i=0;i<4;i++){
                
                if(word[i]=='0') word[i]='9';
                else word[i]--;
                if(st.find(word)==st.end() && mp.find(word)==mp.end()){
                        mp[word]=1;
                        q.push({word,steps +1});
                }
                word = original;
            }
           
        }
        return -1;
    }
};