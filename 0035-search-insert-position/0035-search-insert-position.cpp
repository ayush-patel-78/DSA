class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int n = nums.size();
        while(start <= end){
            int mid = start + ( end - start)/2;
            // cout<<mid<<endl;
            if(nums[mid]==target) return mid;
            else if(nums[(mid+n-1)%n] < target && nums[(mid)%n] > target){
                return mid;
            }
            else if(nums[mid] < target && nums[(mid+1)%n]>target) return mid + 1;
            else if(nums[mid] > target) end = mid - 1;
            else start = mid + 1;
        }
        return start;
    }
};