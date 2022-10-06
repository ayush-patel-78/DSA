class TimeMap {
public:
    
    unordered_map<string,vector<pair<int,string>>> mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mpp.find(key)==mpp.end()) return "";
        int left = 0;
        int right = mpp[key].size();
        int mid = left + (right - left)/2;
        while(left < right){
            int mid = left + (right - left)/2;
            if(mpp[key][mid].first == timestamp){
                return mpp[key][mid].second;
            }
            else if(mpp[key][mid].first > timestamp){
                right = mid;
            }
            else left = mid + 1;
        }
         if(left >0 && left <= mpp[key].size()){
             return mpp[key][left-1].second ;
         }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */