class Solution {
public:
    int search(vector<int>& nums, int target) {
      int lo =0;
        int high = nums.size()-1;
        int mid ;
        while(lo <= high){
            mid = lo + (high - lo)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid] < target){
                lo = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
};