class Solution {
public:
    bool check_palindrome(string word){
        if(word[0]==word[1]) return true;
        return false;
    }
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mpp;
        int maxLenght = INT_MIN;
        int countPal = 0;
        unordered_map<string,int> pal_words;
        for(int i=0;i<words.size();i++){
            
            if(check_palindrome(words[i])){
                pal_words[words[i]]++;
            }
            else mpp[words[i]]++;
        }
        int count = 0;
        bool pal=false;
        for(auto x:mpp){
            string rev = x.first;
            reverse(rev.begin(),rev.end());
            pal = check_palindrome(x.first);
            if(!pal && mpp[rev] > 0 && mpp[x.first] > 0){
                int hehe = min(mpp[x.first],mpp[rev]);
                mpp[x.first]-= hehe;
                mpp[rev]-=hehe;
                count= count + 2*hehe;
            }
        }
        int first_odd=0;
        for(auto y:pal_words){
            if(y.second%2==1 && first_odd==0){
                count += y.second;
                first_odd++;
            }
            else if(y.second%2==1 && first_odd > 0){
                count += y.second - 1;
            }
            else count += y.second;
        }
        int ans = count*2;
        return ans;
    }
};