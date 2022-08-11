class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum=0;
        int best_sum=nums[0];
        for(int x:nums){
            current_sum=current_sum + x;
                if(current_sum>best_sum){
                    best_sum=current_sum;
                   
                }
             if(current_sum<0){
                current_sum=0;
            }
        }
        return best_sum;
    }
};