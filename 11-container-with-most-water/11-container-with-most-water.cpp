class Solution {
public:
    int maxArea(vector<int>& height) {
        int maximum_storage = 0;
        int l=0,r=height.size()-1;
        while(l<r){
            int area = (r-l+1-1)*min(height[l],height[r]);
            if(area >= maximum_storage) maximum_storage = area;
            if(height[l]<height[r]) l++;
            else r--;
        }
        return maximum_storage;
    }
};