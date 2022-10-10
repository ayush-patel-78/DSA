class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int sum = 0;
        int ans = INT_MAX;
        while(j<nums.size()){
            sum += nums[j];          
            while(sum >= target){
                 if(j-i+1 < ans){
                    ans = j-i+1;
                } 
                sum -=  nums[i++];
            }
            j++;
        }
        if(ans == INT_MAX) return 0;
        return ans;
    }
};