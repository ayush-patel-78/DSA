class Solution {
public:
    int binarySearch_first(vector<int>& nums,int target){
        int start = 0;
        int end = nums.size()-1;
        int result = -1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target){
                result = mid;
                end = mid -1;
            }
            if(nums[mid]>target ){
                end = mid -1;
            }
            if(nums[mid]<target ){
                start = mid + 1;
            }
        }
        return result;
    }
    int binarySearch_last(vector<int>& nums,int target){
        int start = 0;
        int end = nums.size()-1;
        int result = -1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target){
                result = mid;
                start = mid +1;
            }
            if(nums[mid]>target ){
                end = mid -1;
            }
            if(nums[mid]<target ){
                start = mid + 1;
            }
        }
        return result;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(binarySearch_first(nums,target));
        ans.push_back(binarySearch_last(nums,target));
        return ans;
    }
};