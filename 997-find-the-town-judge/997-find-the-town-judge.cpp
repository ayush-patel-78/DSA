class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,vector<int>> adj;
        unordered_map<int,vector<int>> t;
        for(int i = 0;i<trust.size();i++){
            adj[trust[i][0]].push_back(trust[i][1]);
            t[trust[i][1]].push_back(trust[i][0]);
        }
        int count=0;
        int judge=-1;
        for(int i=1;i<=n;i++){
            if(adj[i].size()==0){
                count++;
                judge = i;
            }
        }  
        if(count>1) return -1;
        if(t[judge].size() == n-1) return judge;
        return -1;
    }
};