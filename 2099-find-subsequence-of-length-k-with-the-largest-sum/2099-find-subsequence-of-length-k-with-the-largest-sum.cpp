class Solution {
public:
    bool static compare(pair<int,int>& p1,pair<int,int>& p2){
        return p1.second < p2.second;
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<pair<int,int>> v;
        while(!pq.empty()){
            v.push_back(pq.top());
            pq.pop();
        } 
        sort(v.begin(),v.end(),compare);
        vector<int> ans;
        for(int i=0;i<v.size();i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};