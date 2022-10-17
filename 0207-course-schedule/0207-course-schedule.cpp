class Solution {
public:
    void dfs(vector<int>& vis,int v,vector<vector<int>>& adjList,stack<int>& st){
        vis[v]=1;
        for(int i=0;i<adjList[v].size();i++){
            if(!vis[adjList[v][i]]){
                dfs(vis,adjList[v][i],adjList,st);
            }
        }
        st.push(v);
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(auto x:prerequisites){
            adjList[x[1]].push_back(x[0]);
            if(x[1]==x[0]) return false;
        }
        bool check = true;
        vector<int> vis(numCourses,0);
        stack<int> st;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                dfs(vis,i,adjList,st);
            }
        }
        vector<int> topo;
        while(!st.empty()){
            topo.push_back(st.top());
            st.pop();
        }
        vector<int> vis2(numCourses,0);
        for(int i=topo.size()-1;i<topo.size();i--){
            if(!vis2[topo[i]]){
                dfs(vis2,topo[i],adjList,st);
            }
            else{
                return false;
            }
            
        }
        
        return true;
        
    }
};