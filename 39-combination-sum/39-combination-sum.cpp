class Solution {
public:
    void findCombination(vector<int>& candidates,vector<int>& ans, vector<vector<int>>& st,int index,int n,int target){
        if(index==n){
            if(target==0){
                st.push_back(ans);   
            }
             return;
        }
        if(target-candidates[index]>=0){
            ans.push_back(candidates[index]);
            findCombination(candidates,ans,st,index,n,target-candidates[index]);
            ans.pop_back();
        }
        findCombination(candidates,ans,st,index+1,n,target);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> st;
        vector<int> ans;
        findCombination(candidates,ans,st,0,candidates.size(),target);
        return st;
    }
};