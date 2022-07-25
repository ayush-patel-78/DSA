class Solution {
public:
    int binarySearch(vector<int>&arr){
        int start =0;
        int n = arr.size();
        int end = arr.size()-1;
        while(start <= end){
            int mid = start + (end - start )/2;
            if(arr[(mid+1)%n]<=arr[mid] && arr[(mid+n-1)%n]<= arr[mid]){
                return mid;
            }
            if(arr[(mid+1)%n]<arr[mid]){
                end = mid;
            }
            if(arr[(mid+n-1)%n]<arr[mid]){
                start = mid;
            }  
        }
        return -1;
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        if(arr.size()==0) return -1;
        return binarySearch(arr);
    }
};