class Solution {
public:
    bool dfs(int index,vector<int>& arr,vector<int>& vis){
        vis[index] = 1;
        int n = arr.size();
         if(arr[index]==0) return true;
        if(index + arr[index] < n && !vis[index+arr[index]] && dfs(index + arr[index],arr,vis)) return true;
        if(index - arr[index] >=0 && !vis[index-arr[index]] && dfs(index - arr[index],arr,vis)) return true;
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        bool check = false;
        vector<int> vis(arr.size(),0);
        return dfs(start,arr,vis);
    }
};