class MyCalendar {
public:
    vector<pair<int,int>> pr;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(int i=0;i<pr.size();i++){
            if((pr[i].first <= start && start < pr[i].second) || (start <= pr[i].first && pr[i].first < end)){
                return false;
            }
            
        }
        pair<int,int> x;
        x.first = start;
        x.second = end;
        pr.push_back(x);
        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */