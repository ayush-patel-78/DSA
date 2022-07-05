class Solution {
public:
    void solve(int index,vector<int>& nums,int n,set<vector<int>>& st,vector<int> ans){
        if(index==n){
            st.insert(ans);
            return;
        }
        st.insert(ans);
        solve(index+1,nums,n,st,ans);
        ans.push_back(nums[index]);
        solve(index+1,nums,n,st,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> ans;
        solve(0,nums,nums.size(),st,ans);
        vector<vector<int>> result;
        for(auto x:st){
            result.push_back(x);
        }
        return result;
    }
};