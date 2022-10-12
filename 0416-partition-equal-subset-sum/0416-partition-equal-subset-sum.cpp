#define ll long long
class Solution {
public:
    bool solve(vector<int>& nums,int n,int target,vector<vector<int>>& dp){
        if(n==0 && target!=0) return dp[0][target]=false;
        if(n== 0 && target == 0) return dp[0][0]=true;
        if(dp[n][target] != -1) return dp[n][target];
        if(nums[n] <= target){
            dp[n][target] =solve(nums,n-1,target-nums[n],dp)||solve(nums,n-1,target,dp);
        }
        else{
            dp[n][target] = solve(nums,n-1,target,dp);
        }
        return dp[n][target];
    }
    bool canPartition(vector<int>& nums) {
         ll total = 0;
         for(int i=0;i<nums.size();i++){
             total += nums[i];  
         }
         ll target = total/2;
         if(total%2 != 0) return false;
         vector<vector<int>> dp(nums.size()+1,vector<int>(target + 1,-1));
         return solve(nums,nums.size()-1,target,dp);
    }   
};