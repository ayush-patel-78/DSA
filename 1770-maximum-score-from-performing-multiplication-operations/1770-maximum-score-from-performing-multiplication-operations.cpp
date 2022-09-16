#define ll long long
class Solution {
public:
    
    int solve(vector<int>& nums, vector<int>& multipliers,vector<vector<ll>>& dp,int i,int j,int k,int score){
        if( i> j|| i>=nums.size() || j<0 || k<=0) return 0;
        // cout<<"HEHE"<<endl;
         int m = multipliers.size();
         int n = nums.size()-1;
        if(dp[i][n-j] != 1000000000000) return dp[i][n-j];
        
       
        ll ans1 = solve(nums,multipliers,dp,i+1,j,k-1,score) + (ll) nums[i]*multipliers[m-k];
        ll ans2 = solve(nums,multipliers,dp,i,j-1,k-1,score) +(ll) nums[j]*multipliers[m-k];
        // cout<<i<<" "<<j<<" "<<" "<<ans2<<endl;
        ll ans = max(ans1,ans2);
       
        return  dp[i][n-j]=ans;
        
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
          ll score = 0;
          vector<vector<ll>> dp(1001,vector<ll>(1001,1000000000000));
        
         ll i=0;
        ll j=nums.size()-1;
        ll k =  multipliers.size();
        return solve(nums,multipliers,dp,i,j,k,score);
    }
};