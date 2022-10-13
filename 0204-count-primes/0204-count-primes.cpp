class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<bool> check(n+1,true);
        check[0]=false;
        check[1]=false;
        int count = 0;
        for(int i=0;i<n;i++){
            if(check[i]==true){
                count++;
                for(int j=i*2,k=2;j<n;j=i*k){
                    check[j]=false;
                    k++;
                }
            }
        }
        return count;
    }
};