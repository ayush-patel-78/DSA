class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        int t = log2(n)/log2(3);
        return pow(3,t)==n ? true :false;
        
    }
};