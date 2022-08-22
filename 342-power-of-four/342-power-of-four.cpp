class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        int t = log2(n)/log2(4);
        if(pow(4,t)==n) return true;
        return false;
    }
};