class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n);
        for(int i=0;i<dislikes.size();i++){
            graph[dislikes[i][0]-1].push_back(dislikes[i][1]-1);
            graph[dislikes[i][1]-1].push_back(dislikes[i][0]-1);
            
        }
        queue<pair<int,int>> q;
        vector<int> vis(n,0);
        vector<int> color(n,-1);
        q.push({0,1});
        vis[0]=1;
        color[0]=1;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                q.push({i,1});
                color[i]=1;
                vis[i]=1;
            }
            while(!q.empty()){
                int v = q.front().first;
                int check = q.front().second;
                q.pop();
                for(int i=0;i<graph[v].size();i++){
                    if(!vis[graph[v][i]]){
                        if(check == 0)color[graph[v][i]]= 1;
                        else color[graph[v][i]]=0;
                        vis[graph[v][i]]=1;
                        q.push({graph[v][i],color[graph[v][i]]});   
                    }
                    else if(check == color[graph[v][i]]){
                        return false;
                    }
                 
                }
            }
        }
        
        return true;
    }
};