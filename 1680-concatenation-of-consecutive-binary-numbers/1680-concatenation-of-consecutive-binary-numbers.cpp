#define ll long long
class Solution {
public:
    
   
    int concatenatedBinary(int n) {
        ll ans = 0;
        for(int i=1;i<=n;i++){
            int bits = log2(i) +1;
            ans = ((ans<<bits)%1000000007 + i)%1000000007;
        }
    
        return ans;
    }
};