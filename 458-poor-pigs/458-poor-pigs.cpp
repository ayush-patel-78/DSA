class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int tests = minutesToTest/minutesToDie;
        if(buckets==1) return 0;
        for(int i=1;i<1000;i++){
            if(pow(tests+1,i)>= buckets) return i;
        }
        return 0;
    
        
    }
};