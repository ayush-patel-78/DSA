class Solution {
public:
    int binarySearch(vector<int>&arr){
        int start = 0;
        int n = arr.size();
        int end = arr.size()-1;
        while(start <= end){
            int mid = start + (end - start )/2;
            if(arr[(mid+1)%n]<=arr[mid] && arr[(mid+n-1)%n]<= arr[mid]){
                return mid;
            }
            if(arr[(mid+1)%n]>arr[mid]){
                start = mid+1;
            }
            else if(arr[(mid+n-1)%n]>arr[mid]){
                end = mid-1;
            }  
        }
        return -1;
    }
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        if(nums.size()==1) return 0;
        if(nums[start]>nums[start+1]){
            return 0;
        }
        if(nums[end]>nums[end-1]){
            return end;
        }
        return binarySearch(nums);
    }
};