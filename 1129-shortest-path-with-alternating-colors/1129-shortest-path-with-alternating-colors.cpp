class Solution {
public:

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> blue(n);
        vector<vector<int>> red(n);
        
        for(int i=0;i<blueEdges.size();i++){
            blue[blueEdges[i][0]].push_back(blueEdges[i][1]);
        }
        for(int i=0;i<redEdges.size();i++){
            red[redEdges[i][0]].push_back(redEdges[i][1]);
        }
        
        vector<int> visRed(n,0);
        vector<int> visBlue(n,0);
        vector<int> path(n,-1);
        path[0]=0;
        queue<pair<pair<int,int>,int>> q;
        q.push({make_pair(0,0),0});
        while(!q.empty()){
            int v = q.front().first.first;
            int dis = q.front().first.second;
            int check = q.front().second;
            q.pop();
            if(check ==0 || check ==1){
                for(int i=0;i<blue[v].size();i++){
                    if(path[blue[v][i]] == -1) path[blue[v][i]]=dis+1;
                    if(!visBlue[blue[v][i]]){
                        visBlue[blue[v][i]]=1;
                        q.push({make_pair(blue[v][i],dis+1),2});
                    } 
                }
            }
            if(check ==0 || check ==2){
                for(int i=0;i<red[v].size();i++){
                    if(path[red[v][i]] == -1) path[red[v][i]]=dis+1;
                    if(!visRed[red[v][i]]){
                        visRed[red[v][i]]=1;
                        q.push({make_pair(red[v][i],dis+1),1});
                    } 
                }
            }
            
        }
        return path;
    }
};