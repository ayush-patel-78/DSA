class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0]=1;
        int sum =0;
        int rem = 0;
        int ans = 0;
        int minimum = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] < minimum) minimum = nums[i];
        }
        int x = minimum/k;
        int add_num = (x-1)*-1*k; 
        cout<<add_num<<endl;
        for(int i=0;i<nums.size();i++){
            nums[i] += add_num;
        }
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
             mpp[sum%k]++;
            if(mpp.find(sum%k) != mpp.end()){
                ans += mpp[sum%k] - 1;
            }
           
        }
        return ans;
    }
};