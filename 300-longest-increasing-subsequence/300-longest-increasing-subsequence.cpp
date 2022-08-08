class Solution {
public:
    int solve(vector<int>& nums,int index,int n,int prev,vector<vector<int>>&dp){
       if(index == n) return 0;
        if(prev!= -1 && dp[index][prev]!= -1) return dp[index][prev];
       int len = solve(nums,index+1,n,prev,dp);
        
        if(prev==-1 || nums[index]>nums[prev]){
            len = max(len,solve(nums,index+1,n,index,dp)+1);
        }
        if(prev!=-1) return dp[index][prev]=len;
        return len;
        
    }
    int lengthOfLIS(vector<int>& nums) {
        
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(nums,0,nums.size(),-1,dp);
    }
};