class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> st(bank.begin(),bank.end());
        
        queue<pair<string,int>> q;
        q.push({start,0});
        if(st.find(start) != st.end()) st.erase(start);
        vector<char> v={'A','C','G','T'};
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            if(word == end) return steps;
            string original = word;
            q.pop();
            for(int i=0;i<word.size();i++){
                for(int j = 0;j<4;j++){
                    word[i]=v[j];
                    if(st.find(word) != st.end()){
                        q.push({word,steps + 1});
                        st.erase(word);
                    }
                }
                word = original;
            }
        }
        return -1;
    }
};