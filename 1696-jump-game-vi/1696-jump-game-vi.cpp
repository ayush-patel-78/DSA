#define ll long long
class Solution {
public:
    // Approach - 1 Dynamic programming O(n*k) complexity
//     ll help(vector<int>& nums, int k,vector<ll>& dp,int n,int index){
//         if(index==n-1){
//             dp[index] = nums[index];
//             return nums[index];
//         }
//         if(dp[index]!=INT_MIN){
//             return dp[index];
//         }
        
//         ll max = INT_MIN;
//         for(int i=1;i<=k;i++){
//             if(index+i<n){
//                 int ans = help(nums,k,dp,nums.size(),index+i);
//                 if(ans>=max){
//                     max = ans;
//                 }
//             }
            
//         }
//         dp[index]=nums[index]+max;
//         return nums[index]+max;
        
//     }
//     int maxResult(vector<int>& nums, int k) {
//         vector<ll>dp(nums.size()+1,INT_MIN);
        
//         ll ans = help(nums,k,dp,nums.size(),0);
//         return ans;
//     }
    
    
    // Approach - 2 sliding window O(n);
    int maxResult(vector<int>& nums, int k)
    {
        long curr=0;
        deque<int> dq;     		
        for(int i=nums.size()-1;i>=0;i--)
        {
            curr=nums[i]+(dq.empty()?0:nums[dq.front()]);       
			
			
            while(!dq.empty()&&curr>nums[dq.back()])
                dq.pop_back();	
            dq.push_back(i);              
			
		
            if(dq.front()>=i+k)
                dq.pop_front();
            nums[i]=curr;               
        }
        return curr;                           
    }
};