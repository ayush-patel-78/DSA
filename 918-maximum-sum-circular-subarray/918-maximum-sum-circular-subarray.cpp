class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int min = nums[0];
        int n = nums.size();
        int curr = 0;
        int total = 0;
        
        // inverted kadane's algo 
        for(int i=0;i<n;i++){
            curr += nums[i];
            total += nums[i];
            if(curr < min) min = curr;
           
            if(curr > 0){
                curr = 0;
                continue;
            }  
            
        }
        int inverted_max = total - min;
        // kadane's algo
        curr = 0;
        int maxi = 0;
        int neg_max = INT_MIN;
        for(int i=0;i<n;i++){
            curr += nums[i];
            if(curr > maxi) maxi = curr;
            if(neg_max < curr) neg_max = curr;

            if(curr < 0){
                curr = 0;
                continue;
            }  
        }
        
        if(neg_max < 0) return neg_max;
        return max(maxi,inverted_max);
        
    }
};