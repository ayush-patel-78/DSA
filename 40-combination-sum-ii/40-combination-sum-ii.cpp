class Solution {
public:
    void findCombination(vector<int>& candidates,set<vector<int>>& st,vector<int>& ans,int index,int n,int target){
        if(target==0){
            st.insert(ans);
            return;
        }
        if(index==n) return;
        if(target-candidates[index]>=0){
            ans.push_back(candidates[index]);
            //picked
            findCombination(candidates,st,ans,index+1,n,target-candidates[index]);
            ans.pop_back();
        }
        //not pick 
        int new_num_index = index+1;
        if(new_num_index==n) return;
        while(candidates[index]==candidates[new_num_index]){
            new_num_index++;
            if(new_num_index==n) return;
        }
        findCombination(candidates,st,ans,new_num_index,n,target);  
         
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> st;
        vector<int> ans;
        int index = 0;
        // vector<int> hehe;
        // map<int,int> mpp;
        // for(int i=0;i<candidates.size();i++){
        //     mpp[candidates[i]]++;
        //     if(target/candidates[i] >=mpp[candidates[i]]){
        //         hehe.push_back(candidates[i]);
        //     }
        // }
        sort(candidates.begin(),candidates.end());
        int n = candidates.size();
        findCombination(candidates,st,ans,index,n,target);
        vector<vector<int>>result;
       
        for(auto x:st){
            result.push_back(x);
        }
        
        return result;
    }
};