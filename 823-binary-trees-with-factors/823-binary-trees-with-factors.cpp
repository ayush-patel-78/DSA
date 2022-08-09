#define ll long long
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int mod = 1e9 + 7;
        unordered_map<ll,ll> mpp;
        for(ll i=0;i<arr.size();i++){
            mpp[arr[i]]=1;
        }
        sort(arr.begin(),arr.end());
        for(ll i=0;i<arr.size();i++){
            for(ll j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    int temp = arr[i]/arr[j];
                    if(mpp.find(temp)!=mpp.end()){
                        mpp[arr[i]]+=(mpp[arr[j]]*mpp[temp])%mod;
                    }
                }
            }
        }
        ll ans =0;
        for(auto x:mpp){
            ans += x.second;
        }
        return ans%mod;
        
    }
};