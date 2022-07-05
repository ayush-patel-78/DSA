#define ll long long 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set<int> myset;
        for(int i=0;i<nums.size();i++){
            myset.insert(nums[i]);
        }
        int current_sequence=1;
        int longest_sequence = 1;
        ll i=0;
        // ll j=0;
        while(i<nums.size()){
            int current = nums[i];
            int prev = nums[i]-1;
            if(myset.find(prev)==myset.end()){
                current_sequence=1;
                current=current+1;
                while(myset.find(current)!=myset.end()){
                        current_sequence++;
                        longest_sequence = max(longest_sequence,current_sequence);
                        current=current+1;
                }
   
            }
            i++;
        }
        return longest_sequence;
    }
};