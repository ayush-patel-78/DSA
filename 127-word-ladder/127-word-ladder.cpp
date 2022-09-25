class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         unordered_set<string> st(wordList.begin(),wordList.end());
        
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        if(st.find(beginWord) != st.end()) st.erase(beginWord);
        
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            if(word == endWord) return steps;
            string original = word;
            q.pop();
            for(int i=0;i<word.size();i++){
                for(int j = 97;j<=122;j++){
                    word[i]=j;
                    
                    if(st.find(word) != st.end()){
                        cout<<word<<" ";
                        q.push({word,steps + 1});
                        st.erase(word);
                    }
                }
                word = original;
            }
        }
        return 0;
    }
};