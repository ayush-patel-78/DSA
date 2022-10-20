class Solution {
public:
       
    void solve(vector<int> nums,set<vector<int>>& st,int i){
        for(int j = i;j<nums.size();j++){
            vector<int> vec;
            int count = 0;
            for(int x=0;x<i;x++){
                vec.push_back(nums[x]);
            }
            for(int k=j; count<nums.size()-i;){
                vec.push_back(nums[k]);
                if(k==nums.size()-1){
                    k=i;
                }
                else k++;
                count++;
            }
            
            st.insert(vec);
            
             solve(vec,st,i+1);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        solve(nums,st,0);
        for(auto x:st){
            ans.push_back(x);
        }
        return ans;
    }
};