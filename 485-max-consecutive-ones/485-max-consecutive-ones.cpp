class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max=0;
        int current=0;
       for(int i=0;i<nums.size();i++){
           if(nums[i]==1){
               current++;
           }
           else{
               current=0;
           }
           if(current>max){
               max=current;
           }
       } 
       return max;
    }
};