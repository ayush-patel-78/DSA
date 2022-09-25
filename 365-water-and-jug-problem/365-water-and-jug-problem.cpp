class Solution {
public:
    bool dfs(int n,int& j1, int& j2, int& tc,unordered_set<int> & st){
        
        if(n == tc) return true;
        if(n<0 || n > j1 + j2) return false;
        if(st.find(n) != st.end()) return false;
        else st.insert(n);
        // cout<<n<<" ";
        if(dfs(j1-n,j1,j2,tc,st)) return true;
        if(dfs(j2-n,j1,j2,tc,st)) return true;
        if(dfs(n+j1,j1,j2,tc,st)) return true;
        if(dfs(n+j2,j1,j2,tc,st)) return true;
    
        return false;
    }
    bool canMeasureWater(int j1, int j2, int tc) {
        unordered_set<int> st;
        if(tc > j1 + j2) return false;
        if(j1%2 == 0 && j2%2 == 0 && tc%2==1) return false;
        int n = 0;
        if(dfs(n,j1,j2,tc,st)) return true;
        return false;
    }
};