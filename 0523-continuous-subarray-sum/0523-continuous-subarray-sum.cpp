class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()==1) return false;
        unordered_map<int,int> mpp;
        mpp[0]=-1;
        int sum = 0;
        int rem = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(mpp.find(sum%k) != mpp.end()){
                int x = i - mpp[sum%k];
                if(x >= 2){
                    return true;
                }
            }
            else{
                mpp[sum%k]=i;
            }
            
        }
        return false;
        
    }
};