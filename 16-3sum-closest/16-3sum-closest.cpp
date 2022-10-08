class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        int sum = 0;
        int close=INT_MAX;
        int ans;
        for(int k=0;k<nums.size();k++){
            sum = nums[k];
            for(int i=0,j=nums.size()-1;i<j ;){
                if(i==k){
                    i++;
                    continue;
                }
                if(j==k){
                    j--;
                    continue;
                }
                int x = nums[i]+nums[j];
                sum = sum + x;
                
                if(abs(sum - target) < close){
                        close = abs(sum - target);
                        ans = sum;
                }
                if(sum == target){
                    return target;
                }
                else if(sum > target){ 
                    
                    j--;
                }
                else if(sum < target){
                    i++;
                }
                sum = sum - x;
                
            }
        }
        return ans;
    }
};