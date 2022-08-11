class Solution {
public:
    bool static compare(pair<int,int>& p1,pair<int,int>& p2){
        return p1.first<p2.first;
    }
//     int solve(vector<pair<int,int>>& arr,int index,vector<int>& dp,int prev){
//         if(index >= arr.size()) return 0;
//         if(dp[index] != -1) return dp[index];
//         int ans2 = 0;
        
//         if(arr[index].first != prev +1 && arr[index].first != prev -1){
//             ans2 = solve(arr,index+1,dp,arr[index].first) + arr[index].second;
           
//         }
//         int ans1 = solve(arr,index+1,dp,prev);
        
        
//         return dp[index]=max(ans1,ans2);
//     }
    int solve2(vector<int>& nums,int index,vector<int>& dp)
    {
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index]!=-1)return dp[index];
        
        int ans1 = solve2(nums,index+1,dp);
        int ans2 = solve2(nums,index+2,dp)+nums[index];
        
        return dp[index]=max(ans1,ans2);
    }
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]+=nums[i];
         
        }
        vector<pair<int,int>> arr;
        vector<int> points;
        int maximum = 0;
        for(auto x:mpp){
            arr.push_back({x.first,x.second});
            if(x.first > maximum) maximum = x.first;
            
        }
        // sort(arr.begin(),arr.end(),compare);
        // for(int i=0;i<arr.size();i++){
        //     points.push_back(arr[i].second);
        // }
        vector<int> v(maximum+1);
        for(int i=0;i<=maximum;i++){
            if(mpp.find(i)!=mpp.end())
                v[i]=mpp[i];
            else v[i]=0;
        }
        
        vector<int> dp(maximum+1,-1);
        return solve2(v,0,dp);
        int prev=-1;
        // return solve(arr,0,dp,prev);
        
    }
};