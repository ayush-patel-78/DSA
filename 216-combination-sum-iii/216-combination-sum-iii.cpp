class Solution {
public:
    void findCombination(vector<int>& arr,vector<vector<int>>&ans,vector<int>& res,int k,int target,int n,int index){
        
        if(target==0 && res.size()==k){
            ans.push_back(res);
            return;
        }
        if(index==n) return;
        if(target-arr[index]>=0 && res.size()<k){
            res.push_back(arr[index]);
            findCombination(arr,ans,res,k,target-arr[index],n,index+1);
            res.pop_back();
        }
        if(res.size()<k){
            findCombination(arr,ans,res,k,target,n,index+1);
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr;
        for(int i=1;i<=9;i++){
            arr.push_back(i);
        }
        vector<vector<int>> ans;
        vector<int> res;
        int target = n;
        findCombination(arr,ans,res,k,target,arr.size(),0);
        return ans;
    }
};