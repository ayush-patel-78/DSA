class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        queue<int> q;
        for(int i=0;i<32;i++){
            int rem = n%2;
            n = n/2;
            q.push(rem);
        }
        string s="";
        long long int ans=0;
        while(!q.empty()){
            // cout<<q.front()<<" ";
             ans = ans<<1 ;
             ans += q.front();
            q.pop();
        }
        
        return ans;
    }
};