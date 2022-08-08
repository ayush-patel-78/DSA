class Solution {
public:
    int solve(vector<int>& nums,int tar, vector<vector<int>>& dp,int index)     {
        int ans =0;
         
        if(index==nums.size() && tar==0) return 1;
        if(index==nums.size()) return 0;
        if(tar < 0) return 0;
        if(dp[index][tar]!=-1) return dp[index][tar];
        
        ans += solve(nums,tar,dp,index+1);
        
        ans += solve(nums,tar-nums[index],dp,index+1);
        return dp[index][tar]=ans;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        target = abs(target);
        // s1 - s2 = target 
        // s1 + s2 = total
        // 2 * s1 = total + target 
        // s1 = (total + target)/2;
        if((total + target)%2==1) return 0;
        int tar = (total + target)/2;
        vector<vector<int>> dp(nums.size()+1,vector<int>(tar+1,-1));
        return solve(nums,tar,dp,0);
    }
};