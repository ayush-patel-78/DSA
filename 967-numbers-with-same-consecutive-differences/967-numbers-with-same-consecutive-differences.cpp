class Solution {
public:
    void solve(int curr,int n,int k,int sz,vector<int>& ans,int result){
        if(sz==n-1) {
            ans.push_back(result);
            return;
        }
        int zeroes = pow(10,n-sz-2);
        
        if(curr-k >=0){
            solve(curr-k,n,k,sz+1,ans,result + (curr-k)*zeroes);
        }
        if(curr + k <=9 && k!=0){
            solve(curr+k,n,k,sz+1,ans,result + (curr+k)*zeroes);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i=1;i<=9;i++){
            int zeroes = pow(10,n-1);
            solve(i,n,k,0,ans,i*zeroes);
        }
        return ans;
    }
};