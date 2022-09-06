class comparator {
    public:
     bool operator()(pair<int,int>const& p1,pair<int,int>const& p2){
        return p1>p2;
    }
};
class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,comparator> pq;
        for(auto x:mp){
            pq.push({x.second,x.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};