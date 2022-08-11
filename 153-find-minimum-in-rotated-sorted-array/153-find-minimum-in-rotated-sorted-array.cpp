class Solution {
public:
    int binarySearch(vector<int>& nums,int start ,int end,int n){
        int mid = -1;
        while(start <= end){
            mid = start + (end - start)/2;
            if(nums[(mid+n-1)%n] >nums[mid] && nums[mid]< nums[(mid+1)%n])              {
                return mid;
            }
            else if(nums[start] <= nums[mid] && nums[mid]>=nums[end]){
                start = mid + 1;
            }
            else end = mid - 1;
        }
        return mid;
    }
    int findMin(vector<int>& nums) {
        int head = binarySearch(nums,0,nums.size()-1,nums.size());
        return nums[head];
    }
};