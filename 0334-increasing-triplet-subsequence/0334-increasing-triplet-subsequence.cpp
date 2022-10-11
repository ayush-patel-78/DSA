class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first=INT_MIN;
        int second = INT_MIN;
        int third = INT_MIN;
        
        for(int i=nums.size()-1;i>=0;i--){
            int curr = nums[i];
            if(curr > first){
                first = curr;
            }
            else if(curr > second && curr < first){
                second = curr;
            }
            else if(curr < second){
                third = curr;
                return true;
            }
        }
        
        return false;
    }
};
