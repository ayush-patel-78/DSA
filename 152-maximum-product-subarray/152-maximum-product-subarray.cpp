class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maximum = nums[0];
        int curr = 1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            curr*=nums[i];
            if(curr > maximum) maximum = curr;
            if(curr == 0) curr = 1;
        }
        curr = 1;
        for(int i=n-1;i>0;i--){
            curr*=nums[i];
            if(curr > maximum) maximum = curr;
            if(curr == 0) curr = 1;
        }
        return maximum;
    }
};