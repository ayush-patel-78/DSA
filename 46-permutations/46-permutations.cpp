#define ll long long
class Solution {
public:
    void helpPermute(vector<int>& nums,unordered_map<int,int>& mpp,vector<vector<int>>& ans,vector<int>& res){
        if(res.size()==nums.size()){
            ans.push_back(res);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(mpp[nums[i]]==0){
                res.push_back(nums[i]);
                mpp[nums[i]]=1;
                helpPermute(nums,mpp,ans,res);
                mpp[nums[i]]=0;
                res.pop_back();
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int,int> mpp;
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]=0;
        }
        vector<int> res;
        helpPermute(nums,mpp,ans,res);
        return ans;   
    }
};