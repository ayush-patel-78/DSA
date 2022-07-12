#define ll long long
class Solution {
public:
    string ans="";
    void help(int k,int value,string s,int n){
        
        int number = k/value;
        ans+=s.substr(number,1);
        s = s.substr(0,number)+s.substr(number+1,s.size()-1);
        k = k-number*value;
        if(n==0) return;
        value/=n;
        help(k,value,s,n-1);
    }
    string getPermutation(int n, int k) {
        string s="";
        for(int i=49;i<49+n;i++){
            s+=i;
        }
        
        ll value = 1;
        for(int i=1;i<n;i++){
            value*=i;
        }
        help(k-1,value,s,n-1);
        return ans;
    }
};