#define ll long long
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        
        ll maximum = 0;
        int startGain = values[0];
        int overallGain = 0;
        for(int i=1;i<values.size();i++){
            startGain = max(startGain,values[i-1]+i-1);
            overallGain = max(overallGain,startGain+values[i]-i);
        }
        return overallGain;
    }
};