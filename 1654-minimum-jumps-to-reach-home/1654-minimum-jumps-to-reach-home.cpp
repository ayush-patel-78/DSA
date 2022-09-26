class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        if(x == 0) return 0;
        vector<int> vis(40000,0);
        unordered_set<int> st(forbidden.begin(),forbidden.end());
        // for(int i=0;i<forbidden.size();i++){
        //     st.insert(forbidden[i]);
        // }
        // for(auto x:st){
        //     cout<<x<<" ";
        // }
        queue<pair<pair<int,int>,int>> q;
        q.push({make_pair(0,0),1});
        
        while(!q.empty()){
            int top = q.front().first.first;
            int steps = q.front().first.second;
            int check = q.front().second;
            if(top == x) return steps;
            q.pop();
           
            if(top - b >=0 && check && !vis[top-b] && st.find(top - b) == st.end()){
                vis[top-b] = 1;
                q.push({make_pair(top-b,steps + 1),0});
            }
             if(top + a <= 39999 && !vis[top+a] && st.find(top + a) == st.end()){
                vis[top + a] = 1;
                q.push({make_pair(top + a,steps + 1),1});
            }
 
        }
        return -1;
        
       
    }
};