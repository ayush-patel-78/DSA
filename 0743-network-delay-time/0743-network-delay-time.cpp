class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjList(n);
        for(auto x:times){
            adjList[x[0]-1].push_back({x[1]-1,x[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> timeTaken(n,INT_MAX);
        pq.push({0,k-1});
        timeTaken[k-1]=0;
        while(!pq.empty()){
            int v = pq.top().second;
            int t = pq.top().first;
            // cout<<v<<" "<<t<<endl;
            pq.pop();
            for(int i=0;i<adjList[v].size();i++){
                if(timeTaken[adjList[v][i].first] > t + adjList[v][i].second){
                    timeTaken[adjList[v][i].first] = t + adjList[v][i].second;
                    pq.push({t+adjList[v][i].second,adjList[v][i].first});
                }
            }
        }
        int ans = INT_MIN;
        for(int i=0;i<timeTaken.size();i++){
            // cout<<timeTaken[i]<<" ";
            ans = max(ans,timeTaken[i]);
        }
        if(ans == INT_MAX) return -1;
        return ans;
       
    }
};