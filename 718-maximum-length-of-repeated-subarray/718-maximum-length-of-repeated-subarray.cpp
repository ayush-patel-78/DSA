class Solution {
public:
    /*int findLength(vector<int>& nums1, vector<int>& nums2) {
         unordered_map<int,vector<int>> mpp2;
         for(int i=0;i<nums2.size();i++){
             mpp2[nums2[i]].push_back(i);
         }
         
         int count = 0;
         int ans = 0;
         
         for(int i=0;i<nums1.size();i++){
             if(mpp2.find(nums1[i]) != mpp2.end()){
                 count = 1;
                 for(auto x:mpp2[nums1[i]]){
                     for(int k=1;k+i<nums1.size() && k+x<nums2.size();k++){
                         if(nums1[i+k]==nums2[k+x]){
                             count++;
                         }
                         else break;
                     }
                     if(count > ans){
                         ans = count;
                         if(count == nums1.size() || count == nums2.size()) return count;
                     }
                     count = 1;
                 }
             }
         }
        return ans;
        
    }*/
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
         vector<vector<int>> dp(n+1,vector<int> ( m+1 , 0));
         
        int ans = 0;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    if(dp[i][j]> ans) ans = dp[i][j];
                   
                }
                 // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        
        return ans;
    }
};