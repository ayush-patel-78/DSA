class Solution {
public:
    void solve(int index,vector<int>& nums,set<vector<int>>& st,int n,vector<int> ans){
        if(index==n){
            sort(ans.begin(),ans.end());
            st.insert(ans);
            return ;
        }
        sort(ans.begin(),ans.end());
        st.insert(ans);
        solve(index+1,nums,st,n,ans);
        ans.push_back(nums[index]);
        solve(index+1,nums,st,n,ans);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> ans;
        solve(0,nums,st,nums.size(),ans);
        vector<vector<int>> result;
        for(auto x:st){
            result.push_back(x);
        }
        return result;
    }
};