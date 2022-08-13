#define ll long long
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        
        ll maximum = 0;
        for(ll i=0;i<values.size();i++){
            for(ll j=i+1;j<values.size() && (j-i)<=values[i];j++){
                int curr = values[i]+values[j] -j + i ;
                if(curr > maximum) maximum = curr;
            }
        }
        return maximum;
    }
};