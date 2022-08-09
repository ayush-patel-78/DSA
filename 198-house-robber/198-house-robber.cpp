class Solution {
public:
    int solve(vector<int>& nums,int index,vector<vector<int>>& dp,int profit ){
        if(index>=nums.size()){
            return profit;
        }
        if(dp[index][profit]!=-1)return dp[index][profit];
        
        int ans1 = solve(nums,index+1,dp,profit);
        int ans2 = solve(nums,index+2,dp,profit+nums[index]);
        
        return dp[index][profit]=max(ans1,ans2);
    }
    int rob(vector<int>& nums) {
        int profit = 0;
        int total = 0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        vector<vector<int>> dp(nums.size()+1,vector<int> (total+1,-1));
        return solve(nums,0,dp,profit);
    }
};