class Solution {
public:
    bool binary(vector<int>& nums,int start,int end,int target){
        if(end>=start){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                return true;
            }
            if(target>nums[mid]){
                return binary(nums,mid+1,end,target);
            }
            return binary(nums,start,mid-1,target);
        }
        return false;
    }
    int binarySearch(vector<vector<int>>& matrix,int start,int end,int target){
        if(end>=start){
            int mid=start+(end-start)/2;
            if(matrix[mid][0]<=target && matrix[mid][matrix[0].size()-1]>=target){
                return mid;
            }
            if(target>matrix[mid][matrix[0].size()-1]){
                return binarySearch(matrix,mid+1,end,target);
            }
            
            return binarySearch(matrix,start,mid-1,target);
            
        }
        return -1;
        
        
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // if(matrix.size()==1 && matrix[0].size()==1){
        //     return matrix[0][0]==target;
        // }
        // else if(matrix.size()==1 && matrix[0].size()>1){
        //     return binary(matrix[0],0,matrix[0].size()-1,target);
        // }
        int res = binarySearch(matrix,0,matrix.size()-1,target);
        if(res!=-1){
            return binary(matrix[res],0,matrix[0].size()-1,target);
        }
        return false;
    }
};