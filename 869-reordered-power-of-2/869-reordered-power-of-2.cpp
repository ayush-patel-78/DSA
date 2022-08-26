class Solution {
public:
    vector<int> Count(int n){
        vector<int> arr;
        while(n>0){
            arr.push_back(n%10);
            n/=10;
        }
        sort(arr.begin(),arr.end());
        return arr;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> count = Count(n);
        long long x = 1;
        for(int i=0;i<=30;i++){
            if(Count(x)==count){
                return true;
            }
            x = x*2;
        }
        return false;
    }
};