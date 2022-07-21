class Solution {
public:
    // Approach 1:
    int binarySearch(vector<int>& nums){
        int start = 0;
        int n = nums.size();
        int end = n-1;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            if(nums[(mid+1)%n]>=nums[mid] && nums[(mid + n -1)%n]>= nums[mid]){
                return mid;
            }
            if(nums[mid]<= nums[end]){
                end = mid -1;
            }
            else if(nums[start]<=nums[mid]){
                start = mid+1;
            }
            
        }
        return -1;
    }
    int binary_search_target(vector<int>& nums,int start,int end,int target){
        while(start <= end){
            int mid = start + (end-start)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]>target){
                end = mid -1;
            }
            if(nums[mid]<target){
                start = mid + 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int index = binarySearch(nums);
        // return binarySearch(nums);
        if(nums[end] >= target){
            return binary_search_target(nums,index,end,target);
        }
        if(nums[start]<=target){
            return binary_search_target(nums,start,index,target);
        }
        return -1;
    }
    // Approach 2 : better 
//     int search(vector<int>& nums, int target) {
//         int start = 0;
//         int end = nums.size()-1;
//         while(start <= end){
//             int mid = start + (end-start)/2;
//             if(nums[mid]==target) return mid;
//             // left half is sorted or not 
//             if(nums[start]<=nums[mid]){
//                 if(nums[start]<= target && target <= nums[mid]){
//                     end = mid - 1;
//                 }
//                 else{
//                     start = mid + 1;
//                 }
//             }
//             // right half is sorted 
//             else{
//                 if(nums[mid]<= target && target <= nums[end]){
//                     start = mid + 1;
//                 }
//                 else{
//                     end = mid -1;
//                 }
//             }
            
//         }
//         return -1;
//     }
};