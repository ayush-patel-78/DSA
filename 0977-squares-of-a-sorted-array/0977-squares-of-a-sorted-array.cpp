#define ll long long
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        stack<int> st;
        vector<int> ans;
        // st.push(INT_MAX);
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && st.top() <= nums[i]){
                int x = st.top();
                st.pop();
                int sqx = pow(x,2);
                ans.push_back(sqx);
            }
            st.push(abs(nums[i]));
        }
        while(!st.empty()){
            int x = st.top();
            st.pop();
            ll sqx = pow(x,2);
            ans.push_back(sqx);
        }
        return ans;
    }
};