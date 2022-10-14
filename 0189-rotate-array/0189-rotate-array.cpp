class Solution {
public:

    void rotate(vector<int>& nums, int k) {
         k = k % nums.size();
         int strt = nums.size()-k;
         reverse(nums.begin(),nums.begin()+strt);
        reverse(nums.begin()+strt,nums.end());
        for(int i=0,j=nums.size()-1;i<=j;i++,j--){
            swap(nums[i],nums[j]);
        }
    }
};