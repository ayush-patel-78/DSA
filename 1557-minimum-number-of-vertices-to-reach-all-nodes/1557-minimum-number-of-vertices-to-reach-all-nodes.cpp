class Solution {
public:
    void dfs(int v,vector<vector<int>>& adjList,vector<int>& vis,stack<int>& st){
        vis[v]=1;
        for(int i=0;i<adjList[v].size();i++){
            if(!vis[adjList[v][i]]){
                dfs(adjList[v][i],adjList,vis,st);
            }
        }
        st.push(v);
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        vector<int> topo;
        
        for(auto edge:edges){
            adjList[edge[0]].push_back(edge[1]);
        }
        
        vector<int> vis(n,0);
        stack<int> st;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                dfs(i,adjList,vis,st);  
            }  
        }
        while(!st.empty()){
            int x = st.top();
            st.pop();
            topo.push_back(x);
        }
        for(int i=0;i<n;i++){
            vis[i]=0;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!vis[topo[i]]){
                dfs(topo[i],adjList,vis,st);
                ans.push_back(topo[i]);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};