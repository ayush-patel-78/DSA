class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int count = 1;
        while(count != k){
            pq.pop();
            count++;
        }
        return pq.top();
        
    }
};