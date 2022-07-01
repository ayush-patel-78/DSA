#define ll long long
class Solution {
public:
    int trap(vector<int>& height) {
        ll trapped_water = 0;
        ll prev_height=height[0],current_height;
        ll not_trapped=0;
        vector<int> trapped;
        for(int i=1;i<height.size();i++){
            current_height = height[i];
            if(current_height<=prev_height){
                not_trapped += prev_height-current_height;
            }
            if(current_height>prev_height){
                trapped.push_back(not_trapped);
                not_trapped = 0;
                prev_height = current_height;
            }
        }
        not_trapped = 0;
        prev_height = height[height.size()-1];
        for(int i=height.size()-2;i>=0;i--){
            current_height = height[i];
            if(current_height<prev_height){
                not_trapped += prev_height-current_height;
            }
            if(current_height>=prev_height){
                trapped.push_back(not_trapped);
                not_trapped = 0;
                prev_height = current_height;
            }
        }
        for(auto x:trapped){
            trapped_water += x;
        }
        return trapped_water;
    }
};