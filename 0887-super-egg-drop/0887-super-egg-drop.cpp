class Solution {
public:
    
    int solve(int k,int n,vector<vector<int>>& dp){
        if(k==1 || n==1 ||n==0) return n;
        if(dp[k][n] != -1) return dp[k][n];
        int ans = INT_MAX;
        int l = 1,h=n;
        while(l<=h)
        {
            int mid=(l+h)/2;
            int left=solve(k-1,mid-1,dp);   //egg broken check for down floors of mid
            int right=solve(k,n-mid,dp) ;   // not broken check for up floors of mid
            int temp=1+max(left,right);          //store max of both 
            if(left<right){                  //since right is more than left and we need more in worst case 
              l=mid+1;                       // so l=mid+1 to gain more temp for worst case : upward
            }
            else                             //left > right so we will go downward 
            {    
                h=mid-1;
            }
            ans=min(ans,temp);               //store minimum attempts
        }
        return dp[k][n] = ans;
    }
    int superEggDrop(int k, int n) {
    
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));    
        return solve(k,n,dp);
    }
};