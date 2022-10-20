class Solution {
public:
    // My solution brute force   
    
//     void solve(vector<int> nums,set<vector<int>>& st,int i){
//         for(int j = i;j<nums.size();j++){
//             vector<int> vec;
//             int count = 0;
//             for(int x=0;x<i;x++){
//                 vec.push_back(nums[x]);
//             }
//             for(int k=j; count<nums.size()-i;){
//                 vec.push_back(nums[k]);
//                 if(k==nums.size()-1){
//                     k=i;
//                 }
//                 else k++;
//                 count++;
//             }
            
//             st.insert(vec);
            
//              solve(vec,st,i+1);
//         }
//     }
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         vector<vector<int>> ans;
//         set<vector<int>> st;
//         solve(nums,st,0);
//         for(auto x:st){
//             ans.push_back(x);
//         }
//         return ans;
//     }
    
    // better solution 
vector<vector<int> > permuteUnique(vector<int> &num) {
    vector<vector<int>> v;
    vector<int> r;
    map<int, int> map;
    for (int i : num)
    {
        if (map.find(i) == map.end()) map[i] = 0;
        map[i]++;
    }
    permuteUnique(v, r, map, num.size());
    return v;
}

void permuteUnique(vector<vector<int>> &v, vector<int> &r, map<int, int> &map, int n)
{
    if (n <= 0)
    {
        v.push_back(r);
        return;
    }
    for (auto &p : map)
    {
        if (p.second <= 0) continue;
        p.second--;
        r.push_back(p.first);
        permuteUnique(v, r, map, n - 1);
        r.pop_back();
        p.second++;
    }
}
};