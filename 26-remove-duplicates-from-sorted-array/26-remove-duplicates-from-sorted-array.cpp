class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator it=nums.begin();
        int prev = nums[0];
        int count = 1;
        for(int i=1;i<nums.size();){
            if(nums[i]==prev){
                nums.erase(it);
            }else{
                prev = nums[i];
                it++;
                count++;
                i++;
            }
        }
        
        return count;
    }
};