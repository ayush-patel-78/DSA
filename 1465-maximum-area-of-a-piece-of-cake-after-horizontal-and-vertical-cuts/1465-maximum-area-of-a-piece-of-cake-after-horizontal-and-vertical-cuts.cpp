#define ll long long
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        ll max_horizontal = 0;
        ll max_vertical = 0;
        ll prev_h = 0;
        ll prev_v = 0;
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        for(int i=0;i<horizontalCuts.size();i++){
            if(horizontalCuts[i]-prev_h>max_horizontal){
                max_horizontal = horizontalCuts[i]-prev_h;
            }
            prev_h = horizontalCuts[i];
        }
        if(h-prev_h>max_horizontal){
            max_horizontal = h-prev_h;
        }
        for(int i=0;i<verticalCuts.size();i++){
            if(verticalCuts[i]-prev_v>max_vertical){
                max_vertical = verticalCuts[i]-prev_v;
            }
            prev_v = verticalCuts[i];
        }
        if(w-prev_v>max_vertical){
            max_vertical = w-prev_v;
        }
        ll ans= ((max_horizontal*max_vertical)%1000000007);
        return ans;
    }
};