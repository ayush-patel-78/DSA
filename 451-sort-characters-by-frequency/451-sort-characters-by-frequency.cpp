class comparator {
    public:
     bool operator()(pair<int,char>const& p1,pair<int,char>const& p2){
        if(p1.first < p2.first) return true;
         else if(p1.first == p2.first && p1.second < p2.second) return true;
         return false;
    }
};
class Solution {
public:
    string frequencySort(string nums) {
        unordered_map<char,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,char>,vector<pair<int,char>>,comparator> pq;
        for(auto x:mp){
            pq.push({x.second,x.first});
        
        }
        string ans = "";
        while(!pq.empty()){
            for(int i=0;i<pq.top().first;i++)
                ans += pq.top().second;
            pq.pop();
        }
        return ans;
    }
};