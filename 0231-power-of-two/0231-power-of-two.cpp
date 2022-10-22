class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        int hehe = log2(n);
        if(pow(2,hehe)==n) return true;
        return false;
    }
};