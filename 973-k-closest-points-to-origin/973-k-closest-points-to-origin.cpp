class comparator {
    public:
     bool operator()(pair<double,int>const& p1,pair<double,int>const& p2){
        return p1.first<p2.first;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<double,int>,vector<pair<double,int>>,comparator> pq;
        for(int i=0;i<points.size();i++){
            pq.push({sqrt(pow(points[i][0],2)+pow(points[i][1],2)),i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};