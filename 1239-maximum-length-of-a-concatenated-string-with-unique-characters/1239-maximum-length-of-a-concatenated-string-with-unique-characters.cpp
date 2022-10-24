class Solution {
public:
    int solve(vector<string>& arr,int i,unordered_map<char,int>& mpp){
        if(i>=arr.size()){
            return 0;
        }
        bool pick = true;
        for(int j = 0;j<arr[i].size();j++){
            mpp[arr[i][j]]++;
            if(mpp[arr[i][j]]>1){
                pick = false;
            }
        }
        int ans1=0;
        int ans2=0;
        if(pick){
            ans1 = arr[i].size() + solve(arr,i+1,mpp);
        }
         for(int j = 0;j<arr[i].size();j++){
            mpp[arr[i][j]]--;
        }
        
        ans2 = solve(arr,i+1,mpp);
        
        return max(ans1,ans2);
        
        
    }
    int maxLength(vector<string>& arr) {
        unordered_map<char,int> mpp;
        return solve(arr,0,mpp);
    }
};