class Solution {
public:
    //My Approach Dynamic programming O(n*n);
    
//     int solve(vector<int>& nums,int index,int n,int prev,vector<vector<int>>&dp){
//        if(index == n) return 0;
//         if(dp[index][prev+1]!= -1) return dp[index][prev+1];
//        int len = solve(nums,index+1,n,prev,dp);
        
//         if(prev==-1 || nums[index]>nums[prev]){
//             len = max(len,solve(nums,index+1,n,index,dp)+1);
//         }
//          return dp[index][prev+1]=len;
        
        
//     }
//     int lengthOfLIS(vector<int>& nums) {
        
//         vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
//         return solve(nums,0,nums.size(),-1,dp);
//     }
    
    // Best Approach O(n*log n);
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (int x : nums) {
            if (sub.empty() || sub[sub.size() - 1] < x) {
                sub.push_back(x);
            } else {
                auto it = lower_bound(sub.begin(), sub.end(), x); // Find the index of the smallest number >= x
                *it = x; // Replace that number with x
            }
        }
        return sub.size();
    }
};