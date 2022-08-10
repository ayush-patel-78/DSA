class Solution {
public:
    int solve(vector<int>& nums,vector<int>&dp,int index){
        
        if(index >= nums.size()-1) return 0;
        if(nums[index]== 0 ) return -1;
        if(dp[index]!= -1) return dp[index];
        int ans =0;
        int minimum = INT_MAX;
        for(int i=1;i<=nums[index];i++){
            // if(index + i >= nums.size()) return 1;
            ans = solve(nums,dp,index+i);
            if(ans == -1) continue;
            if(ans < minimum) minimum = ans;
        }
        if(minimum == INT_MAX) return -1;
        return dp[index]=(minimum+1);
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        int ans = solve(nums,dp,0);
        if(ans == -1) return 0;
        return ans;
    }
};