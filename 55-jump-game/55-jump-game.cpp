class Solution {
public:
    
    // my approach 
    bool solve(vector<int>& nums,int index,vector<int>& dp){
        if(index >= nums.size()-1) return true;
        if(dp[index] != -1) return dp[index];
        int n = nums[index];
        for(int i=1;i<=n;i++){
         bool check  = solve(nums,index+i,dp);
            if(check){
                 dp[index]=1;
                return true;  
            }
           
        }
        dp[index]=0;
        return false;
        
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return solve(nums,0,dp);
    }
    
    // better approach 
    //   bool canJump(vector<int>& nums) {
    //     int i, minjump = 0;
    //     for(i = nums.size()-2; i >= 0; i--){
    //         minjump++;
    //         if(nums[i] >= minjump)
    //             minjump = 0;
    //         }
    //         if(minjump == 0) 
    //             return true;
    //         else 
    //             return false;
    // }
};