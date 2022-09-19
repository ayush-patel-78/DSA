#define ll long long
class Solution {
public:
    int numRabbits(vector<int>& answers) {
         ll ans=0;
        unordered_map<int,int> mp;
        for(auto i:answers){
            mp[i]++;
        }
        for(auto x:mp){
            ans += (x.second/(x.first+1)) * (x.first+1);
            if(x.second%(x.first+1)){
                ans += (x.first+1);
            }
        }
        return ans;
    }
};