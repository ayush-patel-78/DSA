class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int sum = 0;
        char prev = colors[0];
        int prev_time=neededTime[0];
        for(int i=1;i<colors.size();i++){
            if(colors[i]==prev){
                if(prev_time > neededTime[i] ){
                    sum += neededTime[i];
                }
                else{
                    sum += prev_time;
                    prev = colors[i];
                    prev_time = neededTime[i];
                }
            }
            else{
                    prev = colors[i];
                    prev_time = neededTime[i];
            }
        }
        return sum;
    }
};