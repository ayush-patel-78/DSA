class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.size()==0) return 0;
        sort(tokens.begin(),tokens.end());
        if(power < tokens[0]){
                return 0;
        }
        int i=0;
        int j=tokens.size()-1;
        int score =0;
        for(i=0;i<=j;){
            if(power >= tokens[i]){
                power -= tokens[i];
                score++;
                i++;
            }
            else{
                power += tokens[j];
                j--;
                score--;
            }
        
        }
        if(i<tokens.size() && power >= tokens[i]){
                power -= tokens[i];
                score++;
                i++;
      }
        cout<<power<<endl;
        return score;
    }
};