class Solution {
public:
    int solve_first(vector<int>& nums,int index,vector<int>& dp)
    {
        if(index >=nums.size()-1) return 0;
        if(dp[index]!=-1)return dp[index];
        
        int ans1 = solve_first(nums,index+1,dp);
      
        int ans2 = solve_first(nums,index+2,dp)+nums[index];
        
        
        return dp[index]=max(ans1,ans2);
    }
    int solve_end(vector<int>& nums,int index,vector<int>& bp)
    {
        if(index >=nums.size()) return 0;
        if(bp[index]!=-1)return bp[index];
        
        int ans1 = solve_end(nums,index+1,bp);
        int ans2 = solve_end(nums,index+2,bp)+nums[index];
        
        
        return bp[index]=max(ans1,ans2);
    }
    
    int rob(vector<int>& nums) {
        int profit = 0;
        bool check = false;
        if(nums.size()==1) return nums[0];
        vector<int> dp(nums.size()+1,-1);
        vector<int> bp(nums.size()+1,-1);
        int ans1=solve_first(nums,0,dp);
        int ans2=solve_end(nums,1,bp);
        return max(ans1,ans2);
    }
};