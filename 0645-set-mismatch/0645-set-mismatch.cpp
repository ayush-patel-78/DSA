class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        vector<int> ans;
        int x=0;
        for(int i=1;i<=nums.size();i++){
            if(mpp[i]==2) ans.push_back(i);
            if(mpp[i]==0){
                x=i;
            }
          
        }
        ans.push_back(x);
        return ans;
    }
};