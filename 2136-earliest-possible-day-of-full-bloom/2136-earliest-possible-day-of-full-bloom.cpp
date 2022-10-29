class Solution {
public:
    bool static comparator(pair<int,int>& p1,pair<int,int>& p2){
        if(p1.first > p2.first) return true;
        if(p1.first == p2.first && p1.second < p2.second) return true;
        return false;
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
         vector<pair<int,int>> vec;
         int n = plantTime.size();
        int total_plantationdays = 0;
         for(int i=0;i<n;i++){
             vec.push_back({growTime[i],plantTime[i]});
             total_plantationdays += plantTime[i];
         }
         sort(vec.begin(),vec.end(),comparator);
         // reverse(vec.begin(),vec.end());
         // for(int i=0;i<n;i++){
         //     cout<<vec[i].first<<" "<<vec[i].second<<endl;
         // }
        int ans = 0;
        for(int i=0;i<n;i++){
            int grow = vec[i].first;
            int plant = vec[i].second;
            ans += plant;
            total_plantationdays -= plant;
            if(grow <= total_plantationdays){
                vec[i].first = 0;
            }
            else{
                vec[i].first = grow - total_plantationdays;
            }
        }
         
       int more_days_required = 0;
       for(int i=0;i<n;i++){
           more_days_required = max(more_days_required,vec[i].first);
       }
        ans += more_days_required;
        return ans;
    }
};