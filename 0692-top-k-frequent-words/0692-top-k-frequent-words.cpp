class comparator {
    public:
     bool operator()(pair<int,string>const& p1,pair<int,string>const& p2){
        if(p1.first > p2.first) return true;
         else if(p1.first == p2.first && p1.second < p2.second) return true;
         return false;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& nums, int k) {
        unordered_map<string,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,comparator> pq;
        for(auto x:mp){
            pq.push({x.second,x.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<string> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};