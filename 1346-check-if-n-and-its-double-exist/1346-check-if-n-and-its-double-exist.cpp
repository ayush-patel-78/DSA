class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        unordered_set<int> st;
        bool flag = false;
        int zeroes =0;
        for(int i = 0; i < arr.size();i++)
        {
           st.insert(arr[i]);
            if(arr[i]==0) zeroes++;
        }
        
        for(auto x:st){
            if(x!=0 && st.find(x*2)!=st.end()){
                return true;
            }
            if(x==0 && zeroes >=2) return true;
        }
        
        return false;
    }
}; 