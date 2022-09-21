class Solution {
public:
    int dfs(int v,vector<vector<int>>& adjList,vector<int>& informTime,int time){
        int ans=time;
        for(int i=0;i<adjList[v].size();i++){

            int curr_ans = dfs(adjList[v][i],adjList,informTime,time + informTime[v]);
            if(curr_ans > ans) ans = curr_ans;
           
        }
        return ans;
    }
    int numOfMinutes(int n, int head, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adjList(n);
        for(int i=0;i<n;i++){
            if(manager[i] != -1){
                adjList[manager[i]].push_back(i);
            }
        }
        
        
        int ans = 0;
        int time = 0;
        for(int i = 0;i<adjList[head].size();i++){
            time = informTime[head];
            int curr_ans = dfs(adjList[head][i],adjList,informTime,time);
            if(curr_ans > ans) ans=curr_ans;
        }
        return ans;
        
    }
};