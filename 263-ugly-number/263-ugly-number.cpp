class Solution {
public:
    bool isUgly(int n) {
        if(n<=0) return false;
        if(n==1) return true;
        int fac_2 =0,fac_3=0,fac_5=0;
        while(n%2==0){
            n=n/2;
            fac_2++;
        }
        while(n%3==0){
            n=n/3;
            fac_3++;
        }
        while(n%5==0){
            n=n/5;
            fac_5++;
        }
        if(n==1) return true;
        return false;
    }
};