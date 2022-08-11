class Solution {
public:
  

    int solve2(vector<int>& nums,int index,vector<int>& dp)
    {
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index]!=-1)return dp[index];
        
        int ans1 = solve2(nums,index+1,dp);
        int ans2 = solve2(nums,index+2,dp)+nums[index];
        
        return dp[index]=max(ans1,ans2);
    }
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> mpp;
         int maximum = 0;
       
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]+=nums[i];
            if(nums[i]>maximum) maximum = nums[i];
        }
       
        vector<int> v(maximum+1);
        for(int i=0;i<=maximum;i++){
            if(mpp.find(i)!=mpp.end())
                v[i]=mpp[i];
            else v[i]=0;
        }
        
        vector<int> dp(maximum+1,-1);
        return solve2(v,0,dp);
        int prev=-1;
        // return solve(arr,0,dp,prev);
        
    }
};