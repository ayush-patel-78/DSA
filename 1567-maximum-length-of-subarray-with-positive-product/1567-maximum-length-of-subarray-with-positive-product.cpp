class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int maximum_index_forward = 0;
        int starting_index_forward = -1;
        int curr = 1;
        int length_forward = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>0) curr*=1;
            if(nums[i]<0) curr*=-1;
            if(nums[i]==0) curr*=0;
            if(curr > 0 && (i-starting_index_forward)>= length_forward){
                maximum_index_forward = i;
                length_forward = maximum_index_forward - starting_index_forward;
            } 
            if(curr == 0){
                curr = 1;
                starting_index_forward = i;
            }
        }
        curr = 1;
        int maximum_index_backward = n-1;
        int starting_index_backward = n;
        int length_backward = 0;
        for(int i=n-1;i>0;i--){
             if(nums[i]>0) curr*=1;
            if(nums[i]<0) curr*=-1;
            if(nums[i]==0) curr*=0;
            if(curr > 0 && (starting_index_backward-i)>= length_backward){
                maximum_index_backward = i; 
                length_backward = starting_index_backward - maximum_index_backward;
            }
            if(curr == 0){
                curr = 1;
                starting_index_backward = i;
            }
        }
        return max(length_forward,length_backward);
    }
};