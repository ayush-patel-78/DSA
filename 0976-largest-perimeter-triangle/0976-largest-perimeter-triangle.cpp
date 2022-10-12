class Solution {
public:
    bool static compare(int & i1,int & i2){
        return i1>i2;
    }
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end(),compare);
        for(int i=0,j=1,k=2;k<nums.size();i++,j++,k++){
            if(nums[k]+nums[j] > nums[i]){
                return nums[i]+nums[j]+nums[k];
            }
        }
        return 0;
    }
};