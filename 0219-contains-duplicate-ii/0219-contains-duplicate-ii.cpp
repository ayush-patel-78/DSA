class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // if(nums.size()==1) return false;
        if(k==0) return false;
        int i=0;
        int j=0;
        unordered_map<int,int> mpp;
        while(j<nums.size()){
            if(j-i+1 <= k){
                mpp[nums[j]]++;
            }
            if(j-i+1 <= k){
                j++;
                if(j<nums.size() && mpp.find(nums[j]) != mpp.end()) return true;
                if(j<nums.size()) mpp[nums[j]]++;
                
            }
            while(j-i+1 > k){
                mpp.erase(nums[i]);
                i++;
            }
        }
        return false;
    }
};