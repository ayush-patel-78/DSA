class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        set<pair<int,int>> st;
        vector<vector<int>> adjList(n);
        vector<int> count_degree(n,0);
        for(int i=0;i<roads.size();i++){
            adjList[roads[i][0]].push_back(roads[i][1]);
            st.insert({roads[i][0],roads[i][1]});
            count_degree[roads[i][0]]++;
            count_degree[roads[i][1]]++;
            adjList[roads[i][1]].push_back(roads[i][0]);
            st.insert({roads[i][1],roads[i][0]});
        }
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            vec.push_back({count_degree[i],i});
        }
      
        int ans = INT_MIN;
        
        
        for(int i=0;i<vec.size();i++){
            for(int j=0;j<vec.size();j++){
                if(i==j) continue;
                if(st.find({vec[i].second,vec[j].second})==st.end()){
                    if(vec[i].first + vec[j].first > ans)
                        ans = vec[i].first + vec[j].first;
                }
                else{
                    if(vec[i].first + vec[j].first - 1 > ans)
                        ans = vec[i].first + vec[j].first - 1;
                }
            }
        }
        return ans;
        
    }
};